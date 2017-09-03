#ifndef GLOBAL_H
#define GLOBAL_H

namespace global {
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	const double SPRITE_SCALE = 0.5f;
}

struct Vector2 {
	int x, y;
	Vector2(int _x = 0, int _y = 0) : x(_x), y(_y) {};
};

#endif