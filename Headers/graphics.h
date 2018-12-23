#ifndef GRAPHICS_H
#define GRAPHICS_H

/*
* All information dealing with graphics for the game
*/

#include <SDL2/SDL.h>
//#include <SDL_image.h>
#include <SDL2/SDL_image.h>
//#include <SDL2_image/SDL_image.h>
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
public:
	Graphics();
	~Graphics();
	SDL_Surface* loadImage(const std::string &filePath);
	void blitSurface(SDL_Texture *sourse, SDL_Rect *sourseRectange, SDL_Rect *destinationRectangle);
	
	/* void fleep
	* Renders everything to the screen
	*/
	void flip();
	
	/* void clear
	* Celar the screen
	*/
	void clear();

	SDL_Renderer* getRenderer() const;
private:
	SDL_Window *_window = nullptr;
	SDL_Renderer *_renderer = nullptr;
	std::map < std::string, SDL_Surface * > _spriteSheets;
};

#endif