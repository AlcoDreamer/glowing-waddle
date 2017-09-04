#include <player.h>
#include <graphics.h>

namespace player_constant {
	double WALK_SPEED = 0.2f;
	std::string PATH_TO_CHAR = "Content/sprites/slimeking.png";
}

Player::Player() {};

Player::Player(Graphics *graphics, double x, double y) : 
	AnimatedSprite(graphics, player_constant::PATH_TO_CHAR, 0, 0, 48, 48, x, y, 100)
{
	graphics->loadImage(player_constant::PATH_TO_CHAR);

	this->setupAnimations();
	this->playAnimation("RunRight");
};

void Player::setupAnimations() {
	this->addAnimation(3, 0, 0, "RunUp", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 1, "RunLeft", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 2, "RunRight", 48, 48, Vector2(0, 0));
	this->addAnimation(3, 0, 3, "RunDown", 48, 48, Vector2(0, 0));
	
	this->addAnimation(1, 1, 0, "IdleUp", 48, 48, Vector2(0, 0));
	this->addAnimation(1, 1, 1, "IdleLeft", 48, 48, Vector2(0, 0));
	this->addAnimation(1, 1, 2, "IdleRight", 48, 48, Vector2(0, 0));
	this->addAnimation(1, 1, 3, "IdleDown", 48, 48, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation) {}

void Player::update(double elapsedTime) {
	this->_x += this->_dx * elapsedTime;
	this->_y += this->_dy * elapsedTime;

	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics *graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y); 
}

void Player::stopMoving() {
	this->_dx = 0.0f;
	this->_dy = 0.0f;
	switch (this->_facing) {
		case UP :
			this->playAnimation("IdleUp");
			break;
		case LEFT :
			this->playAnimation("IdleLeft");
			break;
		case RIGHT :
			this->playAnimation("IdleRight");
			break;
		case DOWN :
			this->playAnimation("IdleDown");
			break;
		default:
			break;
	}
}

void Player::moveUp() {
	this->_dy = -player_constant::WALK_SPEED;
	this->playAnimation("RunUp");
	this->_facing = UP;
}

void Player::moveLeft() {
	this->_dx = -player_constant::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void Player::moveRight() {
	this->_dx = player_constant::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::moveDown() {
	this->_dy = player_constant::WALK_SPEED;
	this->playAnimation("RunDown");
	this->_facing = DOWN;
}