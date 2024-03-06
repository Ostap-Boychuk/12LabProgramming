// Game class declaration
#pragma once

#include "Player.h"   // include Player header file
#include "Enemy.h"   // include Enemy header file

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file

class Game
{
	static const int MAX_ENEMIES = 5;
	// data members
	Player myPlayer;  // creates an object of type Player using the default constructor
	Enemy enemyArray[MAX_ENEMIES];  // creates an object of type Enemy using the default constructor

	sf::RenderWindow window;  // main game window

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	sf::Vector2f move = { 0.0f, 0.0f };

public:	  // declaration of function members
	Game();  //  default constructor function
	void	loadContent();
	void	run();

private:
	void setUpEnemy();
	void update();  // handles input in the game
	void draw();  // draws/renders the game world
	void moveEnemies();
};



