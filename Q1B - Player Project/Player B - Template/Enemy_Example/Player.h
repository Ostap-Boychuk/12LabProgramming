// Player class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include "Globals.h"   // include Global header file
#include <iostream>

class Player
{
	// the data members are private by default

	sf::Texture texture; // texture for Player
	sf::Sprite sprite;   // sprite used to represent Player

	int speed;   // the speed that the Player moves
	int direction; // is the Player moving north, south, east or west
	int lives;    // the number of lives


public:	  // declaration of member functions	

	Player(); // default constructor
	void loadImage(); // load the image 

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

};
