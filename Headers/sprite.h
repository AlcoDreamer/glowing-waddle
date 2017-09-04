#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <graphics.h>
#include <string>

/*
* All information about individual sprite
*/

#include <string>
#include <map>

class Sprite {
public:
	Sprite();
	Sprite(Graphics *graphics, const std::string &filePath, int sourseX, int SourseY, int width, int height, double posX, double posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);
protected:
	SDL_Rect _sourseRect;
	SDL_Texture* _spriteSheet;

	double _x, _y;

private:
};

#endif