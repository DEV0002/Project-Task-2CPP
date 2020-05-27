#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "raymarch.h"
#include "vector.h"
#include <thread>
#include <queue>

const unsigned int threadCount = std::thread::hardware_concurrency() * 2;

class PT2 : public olc::PixelGameEngine {
private:
	int* size;
	gls::Vector3 *pScreen = nullptr;
	std::queue<gls::Vector3 *> queue;
	gls::RayMarch marcher;

public:
	PT2() {
		sAppName = "PT2";
	}

public:
	bool OnUserCreate() override {
		//Called once at the start
		size = new int[2]{ ScreenWidth(), ScreenHeight() };
		pScreen = new gls::Vector3[ScreenWidth() * ScreenHeight()];
		marcher = gls::RayMarch();
		marcher.UpdateSize(size);
		marcher.AddObject(gls::Object(gls::Vector3(0, 1, 6), gls::Vector3(1), gls::Object::ObjectType::Box));
		marcher.AddLight(gls::Light(gls::Vector3(0, 5, 6), gls::Vector3(1, 0, 0)));
		return true;
	}

	bool OnUserDestroy() override {
		//Called at end of program
		delete[] pScreen;
		marcher.Dispose();
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		//Called once per frame
		size = new int[2]{ ScreenWidth(), ScreenHeight() };
		RenderScreenSingle(new int[2]{ 0, 0 }, size, fElapsedTime);
		for (int x = 0; x < size[0]; x++)
			for (int y = 0; y < size[1]; y++) {
				gls::Vector3 col = pScreen[x + size[1] * y];
				Draw(x, y, olc::PixelF(col.x.real(), col.y.real(), col.z.real()));
			}
		return true;
	}

	void RenderScreenSingle(int tl[2], int br[2], float fElapsedTime) {
		for (int x = tl[0]; x < br[0]; x++)
			for (int y = br[1]; y >= tl[1]; y--)
				pScreen[x + size[1] * y] = marcher.CalculateColorAtLocation(gls::Vector2(x + .5f, (size[1] - y) + .5f), fElapsedTime);
	}
};

int main() {
	PT2 pt2;
	if (pt2.Construct(640, 480, 1, 1, false, true))
		pt2.Start();
	return 0;
}