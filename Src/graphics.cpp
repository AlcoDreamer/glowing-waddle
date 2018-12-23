#include <SDL2/SDL.h>
#include <graphics.h>
#include <global.h>

Graphics::Graphics() {
	this->_window = SDL_CreateWindow("I love Yasya", 0, 0, global::SCREEN_WIDTH, global::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//SDL_CreateWindowAndRenderer(global::SCREEN_WIDTH, global::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	//SDL_SetWindowTitle(this->_window, "I love Yasya");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
	if (this->_spriteSheets.count(filePath) == 0) {
		//this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
		this->_spriteSheets[filePath] = IMG_Load("content/sprites/slimeking.png");
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *sourse, SDL_Rect *sourseRectange, SDL_Rect *destinationRectangle) {
	SDL_RenderCopy(this->_renderer, sourse, sourseRectange, destinationRectangle); 
}

void Graphics::flip() {
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}