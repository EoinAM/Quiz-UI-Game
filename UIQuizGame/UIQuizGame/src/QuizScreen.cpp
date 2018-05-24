#include "..\include\QuizScreen.h"

QuizScreen::QuizScreen(sf::Font & t_font, sf::Texture & t_texture, Xbox360Controller & t_controller):
	m_keyboard(t_controller, t_font, t_texture)
{
	//load data into the vector array here
	m_font = t_font;
	m_texture = t_texture;
	m_answerRadios.createButtons(4);
	loadQuestions();
	nextQuestion();

}

void QuizScreen::update(sf::Time & t_dTime, Xbox360Controller & t_controller, float & t_animationScalar, CurrentScreen & t_currentScreen)
{
	m_acceptButton.update(t_dTime, t_controller, t_animationScalar);
	m_exitButton.update(t_dTime, t_controller, t_animationScalar);
	m_answerRadios.update(t_dTime, t_controller, t_animationScalar);
	m_keyboard.update(t_dTime,t_animationScalar,m_correctlyAnsweredQuestions, t_currentScreen);
	navigate(t_controller);
	if (m_acceptButton.isPressed())
	{
		bool answered = false;
		std::string answerPutForth;
		for (int i = 0; i < 4; i++)
		{
			if (m_answerRadios.m_buttons.at(i)->isPressed())
			{
				answerPutForth = m_answerRadios.m_buttons.at(i)->m_buttonLabel.m_text.getString();
				answered = true;
			}
		}
		if (answered)
		{
			if (m_activeQuestion +1 < 3)
			{
				if (answerPutForth == m_correctAnswer)
				{
					m_correctlyAnsweredQuestions++;
				}
				nextQuestion();
			}
			else
			{
				m_activeQuestion = -1;
				m_status = QuizStatus::HIGHSCORE_INPUT;
				m_keyboard.m_isShown = true;
				resetButtons();

				if (!m_keyboard.m_isShown)
				{
					t_currentScreen = CurrentScreen::MAINMENU;
				}

			}
		}
	}
	if (m_exitButton.isPressed())
	{
		m_activeQuestion = -1;
		resetButtons();
		m_answerRadios.m_buttons.at(0)->isHighlighted(true);
		t_currentScreen = CurrentScreen::MAINMENU;
	}
}

void QuizScreen::render(sf::RenderWindow & t_window)
{
	if (m_status == QuizStatus::ANSWERING)
	{
		m_acceptButton.render(t_window);
		m_exitButton.render(t_window);
		m_answerRadios.render(t_window);
		m_screenTitle.render(t_window);
		m_question.render(t_window);
	}
	else if( m_status == QuizStatus::HIGHSCORE_INPUT)
	{
		m_keyboard.render(t_window);
	}
}

void QuizScreen::nextQuestion()
{
	//init buttons depending on the question just answered
	m_activeQuestion++;
	resetButtons();
	Button tempButton;
	resetButtons();
	switch (m_activeQuestion)
	{
	case 0:
		m_correctAnswer = m_quizData.at(0);
		m_question.init(m_quizData.at(1), sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 350), m_font);
		m_screenTitle.init("Answer The Questions", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 200), m_font);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 500, 500), sf::Vector2f(20,20), true, sf::Texture(), Label(m_quizData.at(2), sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 500), m_font));
		m_answerRadios.initButtons(0, tempButton);
		m_answerRadios.m_buttons.at(0)->m_isPressed = true;
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f, 500), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(3), sf::Vector2f(ScreenSize::s_width / 2.0f + 100, 500), m_font));
		m_answerRadios.initButtons(1, tempButton);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 500, 600), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(4), sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 600), m_font));
		m_answerRadios.initButtons(2, tempButton);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f, 600), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(5), sf::Vector2f(ScreenSize::s_width / 2.0f + 100, 600), m_font));
		m_answerRadios.initButtons(3, tempButton);

		m_acceptButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 800), sf::Vector2f(200, 50), false, m_texture, Label("Accept Answer", sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 800), m_font));
		m_exitButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f + 50, 800), sf::Vector2f(200, 50), false, m_texture, Label("Exit", sf::Vector2f(ScreenSize::s_width / 2.0f + 50, 800), m_font));
		break;
	case 1:
		m_correctAnswer = m_quizData.at(6);
		m_question.init(m_quizData.at(7), sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 350), m_font);
		m_screenTitle.init("Answer The Questions", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 200), m_font);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 500, 500), sf::Vector2f(20, 20), true, sf::Texture(), Label(m_quizData.at(8), sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 500), m_font));
		m_answerRadios.initButtons(0, tempButton);
		m_answerRadios.m_buttons.at(0)->m_isPressed = true;
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f, 500), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(9), sf::Vector2f(ScreenSize::s_width / 2.0f + 100, 500), m_font));
		m_answerRadios.initButtons(1, tempButton);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 500, 600), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(10), sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 600), m_font));
		m_answerRadios.initButtons(2, tempButton);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f, 600), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(11), sf::Vector2f(ScreenSize::s_width / 2.0f + 100, 600), m_font));
		m_answerRadios.initButtons(3, tempButton);

		m_acceptButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 800), sf::Vector2f(200, 50), false, m_texture, Label("Accept Answer", sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 800), m_font));
		m_exitButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f + 50, 800), sf::Vector2f(200, 50), false, m_texture, Label("Exit", sf::Vector2f(ScreenSize::s_width / 2.0f + 50, 800), m_font));
		break;
		break;
	case 2:
		m_correctAnswer = m_quizData.at(12);
		m_question.init(m_quizData.at(13), sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 350), m_font);
		m_screenTitle.init("Answer The Questions", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 200), m_font);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 500, 500), sf::Vector2f(20, 20), true, sf::Texture(), Label(m_quizData.at(14), sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 500), m_font));
		m_answerRadios.initButtons(0, tempButton);
		m_answerRadios.m_buttons.at(0)->m_isPressed = true;
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f, 500), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(15), sf::Vector2f(ScreenSize::s_width / 2.0f + 100, 500), m_font));
		m_answerRadios.initButtons(1, tempButton);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 500, 600), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(16), sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 600), m_font));
		m_answerRadios.initButtons(2, tempButton);
		tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f, 600), sf::Vector2f(20, 20), false, sf::Texture(), Label(m_quizData.at(17), sf::Vector2f(ScreenSize::s_width / 2.0f + 100, 600), m_font));
		m_answerRadios.initButtons(3, tempButton);

		m_acceptButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 800), sf::Vector2f(200, 50), false, m_texture, Label("Accept Answer", sf::Vector2f(ScreenSize::s_width / 2.0f - 400, 800), m_font));
		m_exitButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f + 50, 800), sf::Vector2f(200, 50), false, m_texture, Label("Exit", sf::Vector2f(ScreenSize::s_width / 2.0f + 50, 800), m_font));
		break;
	}
}

void QuizScreen::resetButtons()
{
	m_acceptButton.reset();
	m_exitButton.reset();
	m_answerRadios.fullReset();
}

void QuizScreen::navigate(Xbox360Controller & t_controller)
{
	if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
	{
		if (m_answerRadios.m_buttons.at(0)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(0)->isHighlighted(false);
			m_answerRadios.m_buttons.at(2)->isHighlighted(true);
		}
		else if (m_answerRadios.m_buttons.at(1)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(1)->isHighlighted(false);
			m_answerRadios.m_buttons.at(3)->isHighlighted(true);
		}
		else if (m_answerRadios.m_buttons.at(2)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(2)->isHighlighted(false);
			m_acceptButton.isHighlighted(true);
		}
		else if (m_answerRadios.m_buttons.at(3)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(3)->isHighlighted(false);
			m_acceptButton.isHighlighted(true);
		}
	}
	else if ((t_controller.m_currentState.DpadRight && !t_controller.m_previousState.DpadRight) || (t_controller.m_currentState.LeftThumbStick.x > 0 && t_controller.m_previousState.LeftThumbStick.x == 0))
	{
		if (m_answerRadios.m_buttons.at(0)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(0)->isHighlighted(false);
			m_answerRadios.m_buttons.at(1)->isHighlighted(true);
		}
		else if (m_answerRadios.m_buttons.at(2)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(2)->isHighlighted(false);
			m_answerRadios.m_buttons.at(3)->isHighlighted(true);
		}
		else if (m_acceptButton.isHighlighted())
		{
			m_acceptButton.isHighlighted(false);
			m_exitButton.isHighlighted(true);
		}
	}
	else if ((t_controller.m_currentState.DpadLeft && !t_controller.m_previousState.DpadLeft) || (t_controller.m_currentState.LeftThumbStick.x < 0 && t_controller.m_previousState.LeftThumbStick.x == 0))
	{
		if (m_answerRadios.m_buttons.at(1)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(1)->isHighlighted(false);
			m_answerRadios.m_buttons.at(0)->isHighlighted(true);
		}
		else if (m_answerRadios.m_buttons.at(3)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(3)->isHighlighted(false);
			m_answerRadios.m_buttons.at(2)->isHighlighted(true);
		}
		else if (m_exitButton.isHighlighted())
		{
			m_exitButton.isHighlighted(false);
			m_acceptButton.isHighlighted(true);
		}
	}
	else if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
	{
		if (m_answerRadios.m_buttons.at(2)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(2)->isHighlighted(false);
			m_answerRadios.m_buttons.at(0)->isHighlighted(true);
		}
		else if (m_answerRadios.m_buttons.at(3)->isHighlighted())
		{
			m_answerRadios.m_buttons.at(3)->isHighlighted(false);
			m_answerRadios.m_buttons.at(1)->isHighlighted(true);
		}
		else if (m_exitButton.isHighlighted())
		{
			m_exitButton.isHighlighted(false);
			m_answerRadios.m_buttons.at(2)->isHighlighted(true);
		}
		else if (m_acceptButton.isHighlighted())
		{
			m_acceptButton.isHighlighted(false);
			m_answerRadios.m_buttons.at(2)->isHighlighted(true);
		}
	}
}

void QuizScreen::loadQuestions()
{
	m_quizFile.open("QUIZ1.txt");
	while (!m_quizFile.eof())
	{
		std::string str;
		std::getline(m_quizFile, str);
		m_quizData.push_back(str);
	}
	m_quizFile.close();
}
