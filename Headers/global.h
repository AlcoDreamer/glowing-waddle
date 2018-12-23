#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>

namespace global {
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	const double SPRITE_SCALE = 1.0f;
}

enum Direction
{
	DOWN,
	LEFT,
	RIGHT,
	UP
};

struct Vector2 {
	int x, y;
	Vector2(int _x = 0, int _y = 0) : x(_x), y(_y) {};
};

#endif