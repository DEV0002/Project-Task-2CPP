#pragma once
#include "vector.h"
#include <vector>
#include <atomic>
#define clamp(v, lo, hi) (v < lo) ? lo : (hi < v) ? hi : v;

namespace gls {
	struct Light {
	public:
		Vector3 lightPosition = 0, lightColor = 0;

	public:
		Light(Vector3 _lightPositon, Vector3 _lightColor) {
			lightPosition = _lightPositon;
			lightColor = _lightColor;
		}
	};

	struct Object {
	public:
		Vector3 position = 0;
		Vector3 size = 0;
		enum ObjectType {
			Sphere = 1,
			Box = 2
		} type;
	public:
		Object(Vector3 _position, Vector3 _size, ObjectType _type) {
			position = _position;
			size = _size;
			type = _type;
		}
	public:
		std::complex<float> Distance(Vector3 p) {
			switch (type) {
			case 1:
				return p.Length() - size.x;
			case 2:
				Vector3 q = p.Abs() - size;
				return q.Max(0.0).Length() + min(max(q.x.real(), max(q.y.real(), q.z.real())), 0.0f);
			}
		}
	};

	class RayMarch {
	private:
		const int MAX_STEPS = 100;
		const float MAX_DIST = 100.0f;
		const float SURF_DIST = .01f;
	public:
		std::vector<Light> lights;
		std::vector<Object> objects;
		std::atomic<int> currentInstances;
		std::atomic<bool> inUse;
		int* size;
	public:
		RayMarch() {
			lights = std::vector<Light>();
			objects = std::vector<Object>();
			currentInstances = 0;
			inUse = false;
		}
		RayMarch(const RayMarch& a) {
			lights = std::vector<Light>();
			objects = std::vector<Object>();
			currentInstances = 0;
			inUse = false;
		}
		void UpdateSize(int _size[2]) {
			size = _size;
		}
		RayMarch operator=(const RayMarch& a) {
			return a;
		}
	public:
		void Begin() {
			currentInstances++;
			inUse.store(true);
		}
		void End() {
			currentInstances--;
			inUse.store(currentInstances != 0);
		}
		void Dispose() {
			lights.clear();
			objects.clear();
			currentInstances.store(0);
			inUse.store(false);
		}
	public:
		int AddLight(Light light) {
			while (inUse);
			lights.push_back(light);
			return lights.size() - 1;
		}
		int AddObject(Object object) {
			while (inUse);
			objects.push_back(object);
			return objects.size() - 1;
		}
		void ModifyLight(int i, Light light) {
			while (inUse);
			lights.at(i) = light;
		}
		void ModifyObject(int i, Object object) {
			while (inUse);
			objects.at(i) = object;
		}
	public:
		Vector3 CalculateColorAtLocation(Vector2 pos, float fElapsedTime) {
			Vector2 uv = (pos - Vector2(.5 * size[0], .5 * size[1])) / std::complex<float>(size[1]);
			Vector3 col = Vector3(0);
			Vector3 ro = Vector3(0, 1, 0);
			Vector3 rd = Vector3(uv.x, uv.y, 1).Normalized();
			std::complex<float> d = MarchRay(ro, rd);
			if (d.real() > MAX_DIST)
				return Vector3(0);
			Vector3 p = ro + rd * d;
			for (int i = 0; i < lights.size(); i++)
				col = col + lights.at(i).lightColor * GetLight(p, lights.at(i));
			return col;
		}
		std::complex<float> GetLight(Vector3 p, Light light) {
			Vector3 l = (light.lightPosition - p).Normalized();
			Vector3 n = GetNormal(p);
			std::complex<float> dif = clamp(n.Dot(l).real(), .0, 1.0);
			std::complex<float> d = MarchRay(p + n * std::complex<float>(SURF_DIST * 2.), l);
			if (d.real() < (light.lightPosition - p).Length().real())
				dif *= .1;
			return dif;
		}
		Vector3 GetNormal(Vector3 p) {
			std::complex<float> d = GetDist(p);
			Vector2 e = Vector2(.01, 0);
			Vector3 n = Vector3(
				d - GetDist(p - Vector3(e.x, e.y, e.y)),
				d - GetDist(p - Vector3(e.y, e.x, e.y)),
				d - GetDist(p - Vector3(e.y, e.y, e.x)));
			return n.Normalized();
		}
		std::complex<float> MarchRay(Vector3 ro, Vector3 rd) {
			std::complex<float> dO = .0;
			for (int i = 0; i < MAX_STEPS; i++) {
				Vector3 p = ro + rd * dO;
				std::complex<float> dS = GetDist(p);
				dO += dS;
				if (dO.real() > MAX_DIST || dS.real() < SURF_DIST) break;
			}
			return dO;
		}
		std::complex<float> GetDist(Vector3 p) {
			std::complex<float> val = 100;
			for (int i = 0; i < objects.size(); i++)
				val = min(objects.at(i).Distance(p).real(), val.real());
			return min(val.real(), p.y.real());
		}
	};
}