#ifndef GAME_H

#define GAME_H

#include "player.h"

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

	Player _player;
};

#endif