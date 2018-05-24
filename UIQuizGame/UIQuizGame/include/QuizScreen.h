#ifndef QUIZ_SCREEN
#define QUIZ_SCREEN

#include "SFML\Graphics.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "Button.h"
#include "RadioButton.h"
#include "Label.h"
#include "KeyBoardInput.h"


enum class QuizStatus
{
	ANSWERING,
	HIGHSCORE_INPUT
};

class QuizScreen
{
public:
	QuizScreen(sf::Font &t_font, sf::Texture &t_texture, Xbox360Controller & t_controller);
	void update(sf::Time &t_dTime, Xbox360Controller &t_controller, float &t_animationScalar, CurrentScreen &t_currentScreen);
	void render(sf::RenderWindow &t_window);
private:
	void nextQuestion();
	void resetButtons();
	void navigate(Xbox360Controller & t_controller);

	void loadQuestions();
	Button m_acceptButton;
	Button m_exitButton;
	RadioButton m_answerRadios;
	Label m_screenTitle;
	Label m_question;

	QuizStatus m_status{ QuizStatus::ANSWERING };

	int m_activeQuestion = -1;
	int m_correctlyAnsweredQuestions{ 0 };

	sf::Font m_font;
	sf::Texture m_texture;

	std::fstream m_quizFile;

	KeyBoardInput m_keyboard;

	std::vector<std::string> m_quizData;
	std::string m_correctAnswer{ "" };
};

#endif