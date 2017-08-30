#include <SDL2/SDL.h>
#include <graphics.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "I love Yasya");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}