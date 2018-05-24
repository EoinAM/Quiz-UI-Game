#ifndef HIGHSCORESCREEN
#define HIGHSCORESCREEN

#include "Global.h"
#include "SFML\Graphics.hpp"
#include "Button.h"
#include "CheckBox.h"
#include "Label.h"
#include "Xbox360Controller.h"

#include <fstream>
#include <vector>
#include <iostream>

class HighScoreScreen
{
public:
	HighScoreScreen(Xbox360Controller & t_controller, sf::Font & t_font, sf::Texture t_buttonTexture) ;
	~HighScoreScreen();

	void update(CurrentScreen & t_currentScreen);
	void render(sf::RenderWindow & t_window);

	void renewScores();

	void loadScores();
	Xbox360Controller m_controller;
	sf::Font m_font;

	void labelInit();
	sf::Texture m_buttonTexture;
	std::fstream highScores;

	std::vector<Label> m_labels;
	std::vector<std::string> m_scores;

	Button m_returnButton;

};

#endif 
