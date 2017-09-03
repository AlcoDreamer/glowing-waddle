#ifndef GAME_H

#define GAME_H

#include "animatedsprite.h"

class Graphics;

class Game
{
public:
	Game();
	~Game();
private:
	void GameLoop();
	void draw(Graphics *graphics);
	void update(double elapsedTime);

	AnimatedSprite _player;
};

#endif