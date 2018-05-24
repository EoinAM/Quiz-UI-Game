#ifndef QUIZ_SELECT
#define QUIZ_SELECT

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Xbox360Controller.h"
#include "Button.h"
#include "RadioButton.h"
#include "Label.h"

class QuizSelectMenu
{
public:
	QuizSelectMenu(sf::Font &t_font, sf::Texture &t_buttonTexture);

	void update(sf::Time t_dTime, Xbox360Controller &t_controller, CurrentScreen &t_currentScreen, const int &t_animationScalar, CurrentQuiz &t_currentQuiz);
	void render(sf::RenderWindow &t_window);
private:
	Button m_selectButton;
	Button m_returnButton;

	RadioButton m_quizButtons;
	Label m_screenLabel;
};

#endif