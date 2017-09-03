#include <graphics.h>
#include <sprite.h>
#include <global.h>

Sprite::Sprite() {}

Sprite::Sprite(Graphics *graphics, const std::string &filePath,
	int sourseX, int sourseY, int width, int height, double posX, double posY)
{
	this->_x = posX;
	this->_y = posY;

	this->_sourseRect.x = sourseX;
	this->_sourseRect.y = sourseY;
	this->_sourseRect.w = width;
	this->_sourseRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics->getRenderer(), graphics->loadImage(filePath));
	if (this->_spriteSheet == NULL) {
		fprintf(stderr, "\nError: Unable to load Image %s", filePath.c_str());
	}
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics, int x, int y) {
	SDL_Rect destinationRectangle = {x, y, (int)(this->_sourseRect.w * global::SPRITE_SCALE), 
		(int)(this->_sourseRect.h * global::SPRITE_SCALE)};
	graphics.blitSurface(this->_spriteSheet, &this->_sourseRect, &destinationRectangle);
}

void Sprite::update() {}