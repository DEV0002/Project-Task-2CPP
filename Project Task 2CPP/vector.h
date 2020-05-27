#pragma once
#include <complex>
#include <cmath>

using namespace std::complex_literals;

namespace gls {
	struct Vector2 {
	public:
		std::complex<float> x, y;
	public:
		Vector2() {
			x = y = 0;
		}
		Vector2(float _xy) {
			x = y = _xy;
		}
		Vector2(float _x, float _y) {
			x = _x;
			y = _y;
		}
		Vector2(std::complex<float> _xy) {
			x = y = _xy;
		}
		Vector2(std::complex<float> _x, std::complex<float> _y) {
			x = _x;
			y = _y;
		}
	public:
		//Gets Length of current Vector2
		std::complex<float> Length() {
			return sqrt(x * x + y * y);
		}
		//Gets Absolute Value of Vector2
		Vector2 Abs() {
			return Vector2(abs(x), abs(y));
		}
	public:
		Vector2 operator +(const Vector2& b) {
			return Vector2(x + b.x, y + b.y);
		}
		Vector2 operator +(const std::complex<float>& b) {
			return Vector2(x + b, y + b);
		}
		Vector2 operator -(const Vector2& b) {
			return Vector2(x - b.x, y - b.y);
		}
		Vector2 operator -(const std::complex<float>& b) {
			return Vector2(x - b, y - b);
		}
		Vector2 operator /(const Vector2& b) {
			return Vector2(x / b.x, y / b.y);
		}
		Vector2 operator *(const Vector2& b) {
			return Vector2(x * b.x, y * b.y);
		}
		Vector2 operator /(const std::complex<float>& b) {
			return Vector2(x / b, y / b);
		}
		Vector2 operator *(const std::complex<float>& b) {
			return Vector2(x * b, y * b);
		}
		void operator +=(const Vector2& b) {
			x += b.x; y += b.y;
		}
		void operator -=(const Vector2& b) {
			x -= b.x; y -= b.y;
		}
		void operator *=(const Vector2& b) {
			x *= b.x; y *= b.y;
		}
		void operator /=(const Vector2& b) {
			x /= b.x; y /= b.y;
		}
		//Gets the Dot Product of the current and specified Vector2
		std::complex<float> Dot(const Vector2& b) {
			return x * b.x + y * b.y;
		}
		//Gets the Maximum of the current and specified Vector2
		Vector2 Max(const Vector2& b) {
			return Vector2(max(x.real(), b.x.real()), max(y.real(), b.y.real()));
		}
		//Gets the Maximum of the current Vector2 and specified float
		Vector2 Max(const float& b) {
			return Vector2(max(x.real(), b), max(y.real(), b));
		}
		//Gets the Minimum of the current and specified Vector2
		Vector2 Min(const Vector2& b) {
			return Vector2(min(x.real(), b.x.real()), min(y.real(), b.y.real()));
		}
		//Gets the Minimum of the current Vector2 and specified float
		Vector2 Min(const float& b) {
			return Vector2(min(x.real(), b), min(y.real(), b));
		}
	};

	struct Vector3 {
	public:
		std::complex<float> x, y, z;
	public:
		Vector3() {
			x = y = z = 0;
		}
		Vector3(float _xyz) {
			x = y = z = _xyz;
		}
		Vector3(const Vector2& _xy, float _z) {
			x = _xy.x;
			y = _xy.y;
			z = _z;
		}
		Vector3(float _x, float _y, float _z) {
			x = _x;
			y = _y;
			z = _z;
		}
		Vector3(std::complex<float> _xyz) {
			x = y = z = _xyz;
		}
		Vector3(const Vector2& _xy, std::complex<float> _z) {
			x = _xy.x;
			y = _xy.y;
			z = _z;
		}
		Vector3(std::complex<float> _x, std::complex<float> _y, std::complex<float> _z) {
			x = _x;
			y = _y;
			z = _z;
		}
	public:
		//Gets Length of current Vector3
		std::complex<float> Length() {
			return sqrt(x * x + y * y + z * z);
		}
		//Gets Normalized Vector3
		Vector3 Normalized() {
			std::complex<float> distance = Length();
			return Vector3(x / distance, y / distance, z / distance);
		}
		//Gets Absolute Value of Vector3
		Vector3 Abs() {
			return Vector3(abs(x), abs(y), abs(z));
		}
	public:
		Vector3 operator +(const Vector3& b) {
			return Vector3(x + b.x, y + b.y, z + b.z);
		}
		Vector3 operator +(const std::complex<float>& b) {
			return Vector3(x + b, y + b, z + b);
		}
		Vector3 operator -(const Vector3& b) {
			return Vector3(x - b.x, y - b.y, z - b.z);
		}
		Vector3 operator -(const std::complex<float>& b) {
			return Vector3(x - b, y - b, z - b);
		}
		Vector3 operator /(const Vector3& b) {
			return Vector3(x / b.x, y / b.y, z / b.z);
		}
		Vector3 operator *(const Vector3& b) {
			return Vector3(x * b.x, y * b.y, z * b.z);
		}
		Vector3 operator /(const std::complex<float>& b) {
			return Vector3(x / b, y / b, z / b);
		}
		Vector3 operator *(const std::complex<float>& b) {
			return Vector3(x * b, y * b, z * b);
		}
		void operator +=(const Vector3& b) {
			x += b.x; y += b.y; z += b.z;
		}
		void operator -=(const Vector3& b) {
			x -= b.x; y -= b.y; z -= b.z;
		}
		void operator *=(const Vector3& b) {
			x *= b.x; y *= b.y; z *= b.z;
		}
		void operator /=(const Vector3& b) {
			x /= b.x; y /= b.y; z /= b.z;
		}

		//Gets the Dot Product of the current and specified Vector3
		std::complex<float> Dot(const Vector3& b) {
			return x * b.x + y * b.y + z * b.z;
		}
		//Gets the Maximum of the current and specified Vector3
		Vector3 Max(const Vector3& b) {
			return Vector3(max(x.real(), b.x.real()), max(y.real(), b.y.real()), max(z.real(), b.z.real()));
		}
		//Gets the Maximum of the current Vector3 and specified float
		Vector3 Max(const float& b) {
			return Vector3(max(x.real(), b), max(y.real(), b), max(z.real(), b));
		}
		//Gets the Minimum of the current and specified Vector3
		Vector3 Min(const Vector3& b) {
			return Vector3(min(x.real(), b.x.real()), min(y.real(), b.y.real()), min(z.real(), b.z.real()));
		}
		//Gets the Minimum of the current Vector3 and specified float
		Vector3 Min(const float& b) {
			return Vector3(min(x.real(), b), min(y.real(), b), min(z.real(), b));
		}
	};

	struct Vector4 {
	public:
		std::complex<float> x, y, z, w;
	public:
		Vector4() {
			x = y = z = w = 0;
		}
		Vector4(float _xyzw) {
			x = y = z = w = _xyzw;
		}
		Vector4(const Vector3& _xyz, float _w) {
			x = _xyz.x;
			y = _xyz.y;
			z = _xyz.z;
			w = _w;
		}
		Vector4(float _x, float _y, float _z, float _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}
		Vector4(std::complex<float> _xyzw) {
			x = y = z = w = _xyzw;
		}
		Vector4(const Vector3& _xyz, std::complex<float> _w) {
			x = _xyz.x;
			y = _xyz.y;
			z = _xyz.z;
			w = _w;
		}
		Vector4(std::complex<float> _x, std::complex<float> _y, std::complex<float> _z, std::complex<float> _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}
	public:
		//Gets Length of current Vector4
		std::complex<float> Length() {
			return sqrt(x * x + y * y + z * z + w * w);
		}
		//Gets Normalized Vector4
		Vector4 Normalized() {
			std::complex<float> distance = Length();
			return Vector4(x / distance, y / distance, z / distance, w / distance);
		}
		//Gets Absolute Value of Vector4
		Vector4 Abs() {
			return Vector4(abs(x), abs(y), abs(z), abs(w));
		}
	public:
		Vector4 operator +(const Vector4& b) {
			return Vector4(x + b.x, y + b.y, z + b.z, w + b.w);
		}
		Vector4 operator +(const std::complex<float>& b) {
			return Vector4(x + b, y + b, z + b, w + b);
		}
		Vector4 operator -(const Vector4& b) {
			return Vector4(x - b.x, y - b.y, z - b.z, w - b.w);
		}
		Vector4 operator -(const std::complex<float>& b) {
			return Vector4(x - b, y - b, z - b, w - b);
		}
		Vector4 operator /(const Vector4& b) {
			return Vector4(x / b.x, y / b.y, z / b.z, w / b.w);
		}
		Vector4 operator *(const Vector4& b) {
			return Vector4(x * b.x, y * b.y, z * b.z, w * b.w);
		}
		Vector4 operator /(const std::complex<float>& b) {
			return Vector4(x / b, y / b, z / b, w / b);
		}
		Vector4 operator *(const std::complex<float>& b) {
			return Vector4(x * b, y * b, z * b, w * b);
		}
		void operator +=(const Vector4& b) {
			x += b.x; y += b.y; z += b.z; w += b.w;
		}
		void operator -=(const Vector4& b) {
			x -= b.x; y -= b.y; z -= b.z; w -= b.w;
		}
		void operator *=(const Vector4& b) {
			x *= b.x; y *= b.y; z *= b.z; w *= b.w;
		}
		void operator /=(const Vector4& b) {
			x /= b.x; y /= b.y; z /= b.z; w /= b.w;
		}

		//Gets the Dot Product of the current and specified Vector4
		std::complex<float> Dot(const Vector4& b) {
			return x * b.x + y * b.y + z * b.z + w * b.w;
		}
		//Gets the Maximum of the current and specified Vector4
		Vector4 Max(const Vector4& b) {
			return Vector4(max(x.real(), b.x.real()), max(y.real(), b.y.real()), max(z.real(), b.z.real()), max(w.real(), b.w.real()));
		}
		//Gets the Maximum of the current Vector4 and specified float
		Vector4 Max(const float& b) {
			return Vector4(max(x.real(), b), max(y.real(), b), max(z.real(), b), max(w.real(), b));
		}
		//Gets the Maximum of the current and specified Vector4
		Vector4 Min(const Vector4& b) {
			return Vector4(min(x.real(), b.x.real()), min(y.real(), b.y.real()), min(z.real(), b.z.real()), min(w.real(), b.w.real()));
		}
		//Gets the Maximum of the current Vector4 and specified float
		Vector4 Min(const float& b) {
			return Vector4(min(x.real(), b), min(y.real(), b), min(z.real(), b), min(w.real(), b));
		}
	};
}