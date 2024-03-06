// Enemy class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include "Globals.h"   // include Global header file
#include <iostream>

class Enemy
{
	// the data members are private by default

	sf::Texture texture; // texture for Enemy
	sf::Sprite sprite;   // sprite used to represent Enemy

	int strength; // the strength of the Enemy 1-10
	int direction; // is the Enemy moving east or west
	int speed;   // the speed that the Enemy moves
	bool alive;    // is the enemy alive


public:	  // declaration of member functions	

	Enemy(); // default constructor
	void loadImage(); // load the image 

	void moveEnemy();

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);

};
