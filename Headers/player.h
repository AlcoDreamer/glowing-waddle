#ifndef PLAYER_H
#define PLAYER_H

#include <animatedsprite.h>
#include <global.h>

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics *graphics, double x, double y);
	void draw(Graphics *graphics);
	void update(double elapsedTime);

	void moveUp();
	void moveLeft();
	void moveRight();
	void moveDown();
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
private:
	double _dx, _dy;

	Direction _facing;
};

#endif