// Player class

#include "Player.h"   // include Player header file


// Definition of member functions of the Player class


Player::Player() // default constructor
{
	loadImage(); // load the image file for the sprite

	image_width = 124; // the width of the image in pixels
	scaled = false; // the image is not scaled
	
	int xPos = SCREEN_WIDTH/2;        // place the player object in the centre of the screen
	int yPos = SCREEN_HEIGHT/2;
	setPosition(xPos, yPos);  // set the position of the players sprite
	
	speed = 5; // the average speed
	direction = (rand() % 2) + 1;        // Generates a random number between 1 and 2
	lives = 3;
}

void Player::loadImage()
// Loads the image for the player object
{
	if (!texture.loadFromFile("ASSETS/IMAGES/SquareGuy.bmp"))
	{
		std::cout << "error with player image file";
	}

	sprite.setTexture(texture);
}



sf::Sprite Player::getBody() // get the player's body
{
	return sprite;
}


void Player::setPosition(int xPos, int yPos)  // set the position of the player on the screen
{
	sprite.setPosition(xPos, yPos);
}

void Player::movementCheck()
{
	 if (direction == WEST)
	 {
		 moveLeft();
	 }
	 if (direction == EAST)
	 {
		 moveRight();
	 }
}

void Player::changeDirection()
{
	if (direction == WEST)
	{
		direction = EAST;
	}
	else if (direction == EAST)
	{
		direction = WEST;
	}

}

void Player::moveLeft()
{
	sf::Vector2f move = sprite.getPosition();
	move.x -= speed;
	if (move.x <= 0.0f)
	{
		direction = EAST;
	}
	sprite.setPosition(move);
}

void Player::moveRight()
{
	sf::Vector2f move = sprite.getPosition();
	move.x += speed;
	if (move.x >= SCREEN_WIDTH - image_width) // left edge
	{
		direction = WEST;
	}
	sprite.setPosition(move);
}

void Player::speedIncrease()
{
	if (speed < 15)
	{
		speed++;
		std::cout << speed << std::endl;
	}
	
}

void Player::speedDecrease()
{
	if (speed > 0)
	{
		speed--;
		std::cout << speed << std::endl;
	}
}

void Player::scalePlayerSize()
{
	if (scaled == false)
	{
		sprite.setScale(1.5f, 1.5f);
		image_width = image_width * 1.5;
		scaled = true;
	}
	
}

void Player::colorChange()
{
	int color = (rand() % 5) + 1;
	switch (color)
	{
	case 1: 
		sprite.setColor(sf::Color::Red);
		break;
	case 2: 
		sprite.setColor(sf::Color::Yellow);
		break;
	case 3: 
		sprite.setColor(sf::Color::Cyan);
		break;
	case 4: 
		sprite.setColor(sf::Color::Magenta);
		break;
	case 5: 
		sprite.setColor(sf::Color::Green);
		break;
	default:
		sprite.setColor(sf::Color::White);
		break;
	}
}





