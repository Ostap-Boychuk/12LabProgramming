// Name: 
// Login: 
// Date: 
// Approx hours of work : 
//---------------------------------------------------------------------------
/* 
1. Make the player move up, down, left and right via the arrow keys.
2. Add an array of 5 enemies that move from left to right across the screen. Each enemy should start at the left side of the 
   console window. When they reach the boundary of the screen on the right they should start from the left again and 
   move left to right again and so on.
   Position them at different y values.  
*/
// ---------------------------------------------------------------------------
// Known Bugs:
// When a key is pressed on the keyboard, it picks up multiple clicks at once not just one click.

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file


int main()
{
	Game myGame;
	myGame.loadContent();
	myGame.run();

	return 0;
}

Game::Game() :window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Display player object within screen boundary", sf::Style::Default)
//  default constructor function
{
}


void Game::loadContent()
// load the font file & set the message string
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen
}


void Game::run()
//This function is the most important function in the project. 
// This function contains the main game loop which controls the game. 
{
	setUpEnemy();

	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased)
			{

			}
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

} // end main




void Game::setUpEnemy()
{
	enemyArray[0].setPosition(move.x, move.y + 100);
	enemyArray[1].setPosition(move.x, move.y + 200);
	enemyArray[2].setPosition(move.x, move.y + 300);
	enemyArray[3].setPosition(move.x, move.y + 400);
	enemyArray[4].setPosition(move.x, move.y + 500);
}

void Game::update()
// handles input in the game
{
	// checks what  keys have been pressed  

	// calls the player object to move itself in the appropriate direction
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		myPlayer.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		myPlayer.moveDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		myPlayer.moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		myPlayer.moveRight();
	}

	moveEnemies();
}

void Game::draw()
// draws/renders the game world
{
	window.clear(); // clear the screen 

	m_message.setString("The player should move via the arrow keys. \nAdd an array of 5 enemies that move to the right and wrap around.");
	
	window.draw(m_message);  // write the message on the screen

	window.draw(myPlayer.getBody());  // draw the player object
	

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		window.draw(enemyArray[i].getBody());
	}
	window.display();
}

void Game::moveEnemies()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		enemyArray[i].moveEnemy();
	}
}


