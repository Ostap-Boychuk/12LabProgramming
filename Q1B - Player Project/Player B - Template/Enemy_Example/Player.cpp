// Player class

#include "Player.h"   // include Player header file


// Definition of member functions of the Player class


Player::Player() // default constructor
{
	loadImage(); // load the image file for the sprite
	setPosition(300, 200);  // set the position of the Player 

	speed = 1; // the average speed
	direction = (rand() % 4) + 1;     // Generates a random number between 1 - 4
	lives = 3;
}

void Player::loadImage()
// Loads the image for the Player object
{
	if (!texture.loadFromFile("ASSETS/IMAGES/SquareGuy.bmp"))
	{
		std::cout << "error with player image file";
	}

	sprite.setTexture(texture);
}


sf::Sprite Player::getBody() // get the Player's body
{
	return sprite;
}


void Player::setPosition()  // set the position of the Player on the screen
{
	sprite.setPosition(300, 200);
}


void Player::setPosition(int xPos, int yPos)  // set the position of the Player on the screen
{
	sprite.setPosition(xPos, yPos);
}

void Player::moveUp()
{
	sf::Vector2f move = sprite.getPosition();

	move.y -= speed;

	sprite.setPosition(move);
}

void Player::moveDown()
{
	sf::Vector2f move = sprite.getPosition();

	move.y += speed;

	sprite.setPosition(move);
}

void Player::moveLeft()
{
	sf::Vector2f move = sprite.getPosition();

	move.x -= speed;

	sprite.setPosition(move);
}

void Player::moveRight()
{
	sf::Vector2f move = sprite.getPosition();

	move.x += speed;

	sprite.setPosition(move);
}

