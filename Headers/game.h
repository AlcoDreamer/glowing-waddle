#ifndef GAME_H

#define GAME_H

#include "player.h"

class Game
{
public:
	Game();
	~Game();
private:
	/*
	 * main game function
	 * function that realizes the game cycle
	 */
	void GameLoop();

	/*
	 * main game function
	 * function that realizes the game cycle
	 */
	void draw(Graphics *graphics);
	

	void update(double elapsedTime);

	Player _player;
};

#endif