#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "global.h"

class AnimatedSprite : protected Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics *graphics, const std::string &filePath, int sourseX, int sourseY,
		int width, int height, double posX, double posY, double timeToUpdate);

	void playAnimation(std::string animation, bool once = false);

	void update(int elapsedTime);

	void draw(Graphics *graphics, int x, int y);
	
protected:
	double _timeToUpdated;
	double _currentAnimationOnce;
	std::string _currentAnimation;

	/* addAnimation
	*  Add animation to map of animations for the sprite
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	void resetAnimations();

	void stopAnimation();

	void setVisible(bool _visible);

	virtual void animationDone(std::string currentAnimation) = 0;

	virtual void setupAnimations() = 0;

private:
	std::map < std::string, std::vector < SDL_Rect > > _animations;
	std::map < std::string, Vector2 > _offsets;

	int _frameIndex;
	int _timeElapsed;
	int _visible;
};

#endif