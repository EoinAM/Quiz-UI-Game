#ifndef GAME
#define GAME

#include <iostream>
#include <fstream>
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

#include "Xbox360Controller.h"
#include "Global.h"
#include "Splash.h"
#include "Author.h"
#include "Licence.h"
#include "HighScoreScreen.h"


#include "Button.h"
#include "RadioButton.h"
#include "Label.h"
#include "KeyBoardInput.h"
#include "ScrollBar.h"
#include "CheckBox.h"


#include "MainMenu.h"
#include "Options.h"
#include "Help.h"
#include "QuizSelect.h"
#include "QuizScreen.h"



class Game
{
public:
	Game(sf::Font &t_font, sf::Texture &t_buttonSprite);
	void run();
private:
	void processEvents();
	void update(sf::Time &t_dTime);
	void render();

	Xbox360Controller m_controller;

	CurrentScreen m_currentScreen;
	CurrentQuiz m_currentQuiz;

	SplashScreen m_splashScreen;
	AuthorScreen m_authorScreen;
	LicenseScreen m_licenseScreen;
	HighScoreScreen m_highScoreScreen;
	
	sf::Texture m_terminalTexture;
	sf::RectangleShape m_terminalRect;
	sf::Texture m_screenTexture;
	sf::RectangleShape m_screenRect;


	sf::RenderWindow m_window;
	sf::Time& M_MS_PER_UPDATE{sf::milliseconds(10)};

	Settings m_settings;

	static const int M_MAX_BUTTONS{4};

	/*Button m_buttons[M_MAX_BUTTONS];*/
	sf::Vector2f m_buttonSize{ 200,50 };

	KeyBoardInput m_keyboard;

	int m_playerScore;

	MainMenu m_mainMenu;
	Options m_options;
	HelpMenu m_helpMenu;
	QuizSelectMenu m_quizSelectScreen;
	QuizScreen m_tempQuiz;
};

#endif//!GAME