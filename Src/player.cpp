#include <player.h>
#include <graphics.h>

Player::Player() {};

Player::Player(Graphics *graphics, double x, double y) : 
	AnimatedSprite(graphics, "Content/sprites/slimeking.png", 0, 0, 48, 48, x, y, 100)
{
	graphics->loadImage("Content/sprites/slimeking.png");

	this->setupAnimations();
	this->playAnimation("RunRight");
};

void Player::setupAnimations() {
	this->addAnimation(3, 0, 0, "RunUp", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 48, "RunLeft", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 48 * 2, "RunRight", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 48 * 3, "RunDown", 48, 48, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation) {}

void Player::update(double elapsedTime) {
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics *graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y); 
}