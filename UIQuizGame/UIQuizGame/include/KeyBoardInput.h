#ifndef KEYBOARD
#define KEYBOARD

#include "Button.h"
#include "Label.h"
#include "Xbox360Controller.h"
#include "Global.h"

#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class KeyBoardInput
{
public:
	KeyBoardInput(Xbox360Controller & t_controller, sf::Font & t_font, sf::Texture & t_buttonTexture);
	~KeyBoardInput();

	void render(sf::RenderWindow & t_window);
	void update(const sf::Time &t_dtime, const int &t_AnimationScalar, int t_scoreNum, CurrentScreen & t_currentScreen);
	void buttonInit();
	void labelInit();

	void takeName(int t_scoreNum, CurrentScreen & t_currentScreen);

	bool m_isShown{ true };

	void handleInput();

	void writeToFile(int t_scoreNum);

	Xbox360Controller & m_controller;
	sf::Font & m_font;
	sf::Texture & m_Buttontexture;

	int m_activeButton{ 0 };
	int scoreLine{ 0 };

	std::fstream highScores;

	sf::String m_fullString;
	sf::String m_stringAddition;
private:
	std::vector<Button> m_buttons;
	std::vector<Label> m_labels;
	std::vector<std::string> m_scores;
	std::vector<std::string> m_oldScores;

	sf::RectangleShape m_body;

	const int NOOFBUTTONS{29};
	const int NOOFSCORES{10};


	Label m_textBlock;

};

#endif // !KEYBOARD