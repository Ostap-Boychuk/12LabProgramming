// Player class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include "Globals.h"   // include Global header file
#include <iostream>

class Player
{
	// the data members are private by default

	sf::Texture texture; // texture for player
	sf::Sprite sprite;   // sprite used to represent player
	int image_width;  // the width of the image in pixels
	bool scaled;  // is the image increased in size
	
	int speed;   // the speed that the player moves
	int lives;    // the number of lives
	int direction; // is the player moving east or west
	

	// private member functions


public:	  // declaration of member functions	

	Player(); // default constructor
	void loadImage(); // load the image 

	sf::Sprite getBody();
	
	void setPosition(int xPos, int yPos);
	void movementCheck();
	void changeDirection();
	void moveLeft();
	void moveRight();
	void speedIncrease();
	void speedDecrease();
	void scalePlayerSize();
	void colorChange();
	

};
