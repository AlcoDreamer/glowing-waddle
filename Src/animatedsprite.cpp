#include "animatedsprite.h"
#include "graphics.h"

AnimatedSprite::AnimatedSprite() {};

AnimatedSprite::AnimatedSprite(Graphics *graphics, const std::string &filePath, 
	int sourseX, int sourseY, int widht, int height, double posX, double posY, double timeToUpdate) :
		Sprite(graphics, filePath, sourseX, sourseY, widht, height, posX, posY),
		_timeToUpdated(timeToUpdate),
		_currentAnimationOnce(false),
		_currentAnimation(""),
		_frameIndex(0),
		_visible(true)
{}

void AnimatedSprite::addAnimation(int frames, int x, int y, std::string name, int widht, int height, Vector2 offset) {
	std::vector < SDL_Rect > rectangles;
	for (int i = 0; i < frames; ++i) {
		SDL_Rect newRect = { (i + x) * widht, y, widht, height };
		rectangles.push_back(newRect);
	}
	this->_animations[name] = rectangles;
	this->_offsets[name] = offset;
}

void AnimatedSprite::resetAnimations() {
	this->_animations.clear();
	this->_offsets.clear();
}

void AnimatedSprite::playAnimation(std::string animation, bool once) {
	this->_currentAnimationOnce = once;
	if (this->_currentAnimation != animation) {
		this->_currentAnimation = animation;
		this->_frameIndex = 0;
	}
}

void AnimatedSprite::setVisible(bool visible) {
	this->_visible = visible;
}

void AnimatedSprite::stopAnimation() {
	this->_frameIndex = 0;
	this->animationDone(this->_currentAnimation);
}

void AnimatedSprite::update(int elapsedTime) {
	Sprite::update();

	this->_timeElapsed += elapsedTime;
	if (this->_timeElapsed > this-> _timeToUpdated) {
		this->_timeElapsed -= this->_timeToUpdated;
		if (this->_frameIndex < this->_animations[this->_currentAnimation].size() - 1) {
			++this->_frameIndex;
		} else {
			if (this->_currentAnimationOnce == true) {
				this->setVisible(false);
			}
			this->_frameIndex = 0;
			this->animationDone(this->_currentAnimation);
		}
	}
}

void AnimatedSprite::draw(Graphics *graphics, int x, int y) {	
	if (this->_visible) {
		SDL_Rect destinationRectangle;
		destinationRectangle.x = x + this->_offsets[this->_currentAnimation].x;
		destinationRectangle.y = y + this->_offsets[this->_currentAnimation].y;
		destinationRectangle.w = this->_sourseRect.w * global::SPRITE_SCALE;
		destinationRectangle.h = this->_sourseRect.h * global::SPRITE_SCALE;
				
		SDL_Rect sourseRect = this->_animations[this->_currentAnimation][this->_frameIndex];
	
		graphics->blitSurface(this->_spriteSheet, &sourseRect, &destinationRectangle);
	}
}

/*
void AnimatedSprite::setupAnimation() {
	this->addAnimation(3, 0, 0, "RunUp", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 48, "RunLeft", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 48 * 2, "RunRight", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 48 * 3, "RunDown", 48, 48, Vector2(0, 0));
}

*/