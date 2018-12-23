#include "game.h"
#include "graphics.h"
#include "input.h"
#include <SDL2/SDL.h>

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->GameLoop();
}

Game::~Game() {

}

void Game::GameLoop() {
	Graphics graphics;
	SDL_Event event;
	Input input;

	this->_player = Player(&graphics, 100, 100);
	
	int LAST_UPDATE_TIME_MS = SDL_GetTicks();

	while (true) {
		input.beginNewFrame();
		
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			} else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			} else if (event.type == SDL_QUIT) {
				return;
			}
		}

		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		int vertical = 0, horizontal = 0;
		if (input.isKeyHeld(SDL_SCANCODE_UP) == true) {
			vertical -= 1;
		}
		if (input.isKeyHeld(SDL_SCANCODE_DOWN) == true) {
			vertical += 1;
		}

		if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			horizontal -= 1;
		}
		if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			horizontal += 1;
		}
		
		if (vertical != 0 && horizontal == 0) {
			if (vertical == 1) {
				this->_player.moveDown();
			} else {
				this->_player.moveUp();
			}
		} else if (vertical == 0 && horizontal != 0) {
			if (horizontal == 1) {
				this->_player.moveRight();
			} else {
				this->_player.moveLeft();
			}
		} else {
			this->_player.stopMoving();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSEDTIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME_MS;

		this->update(std::min(ELAPSEDTIME_MS, MAX_FRAME_TIME));

		LAST_UPDATE_TIME_MS = CURRENT_TIME_MS;

		this->draw(&graphics);
	}
}

void Game::draw(Graphics *graphics) {
	graphics->clear();

	this->_player.draw(graphics);

	graphics->flip();
} 

void Game::update(double elapsedTime) {
	this->_player.update(elapsedTime);
}