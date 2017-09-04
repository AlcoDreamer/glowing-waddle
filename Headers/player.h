#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <animatedsprite.h>

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics *graphics, double x, double y);
	void draw(Graphics *graphics);
	void update(double elapsedTime);

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
private:

};

#endif