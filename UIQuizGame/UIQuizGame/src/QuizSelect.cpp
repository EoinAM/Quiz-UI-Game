#include "..\include\QuizSelect.h"

QuizSelectMenu::QuizSelectMenu(sf::Font & t_font, sf::Texture & t_buttonTexture)
{
	m_screenLabel.init("Select Your Quiz!", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 200), t_font, sf::Color::Red, 40);

	Button tempButton;
	m_quizButtons.createButtons(3);
	tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 500, 500), sf::Vector2f(200,200), true, t_buttonTexture, Label("Quiz 1", sf::Vector2f(ScreenSize::s_width / 2.0f - 500, 500), t_font, sf::Color::Red));
	m_quizButtons.initButtons(0, tempButton);
	m_quizButtons.m_buttons.at(0)->m_isPressed = true;
	tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 500), sf::Vector2f(200, 200), false, t_buttonTexture, Label("Quiz 2", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 500), t_font, sf::Color::Red));
	m_quizButtons.initButtons(1, tempButton);
	tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f + 100, 500), sf::Vector2f(200, 200), false, t_buttonTexture, Label("Quiz 3", sf::Vector2f(ScreenSize::s_width / 2.0f + 100, 500), t_font, sf::Color::Red));
	m_quizButtons.initButtons(2, tempButton);

	
	m_selectButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 350, (ScreenSize::s_height / 2.0f) + 300), sf::Vector2f(200, 50), false, t_buttonTexture, Label("Accept", sf::Vector2f(ScreenSize::s_width / 2.0f - 350, (ScreenSize::s_height / 2.0f) + 300), t_font));
	m_returnButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 50, (ScreenSize::s_height / 2.0f) + 300), sf::Vector2f(200, 50), false, t_buttonTexture, Label("Return", sf::Vector2f(ScreenSize::s_width / 2.0f - 50, (ScreenSize::s_height / 2.0f) + 300), t_font));
}

void QuizSelectMenu::update(sf::Time t_dTime, Xbox360Controller & t_controller, CurrentScreen & t_currentScreen, const int & t_animationScalar, CurrentQuiz &t_currentQuiz)
{
	m_quizButtons.update(t_dTime, t_controller, t_animationScalar);
	m_selectButton.update(t_dTime, t_controller, t_animationScalar);
	m_returnButton.update(t_dTime, t_controller, t_animationScalar);

	if (m_quizButtons.m_buttons.at(0)->isHighlighted())
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_quizButtons.m_buttons.at(0)->isHighlighted(false);
			m_selectButton.isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadRight && !t_controller.m_previousState.DpadRight) || (t_controller.m_currentState.LeftThumbStick.x > 0 && t_controller.m_previousState.LeftThumbStick.x == 0))
		{
			m_quizButtons.m_buttons.at(0)->isHighlighted(false);
			m_quizButtons.m_buttons.at(1)->isHighlighted(true);
		}
	}
	else if (m_quizButtons.m_buttons.at(1)->isHighlighted())
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_quizButtons.m_buttons.at(1)->isHighlighted(false);
			m_selectButton.isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadRight && !t_controller.m_previousState.DpadRight) || (t_controller.m_currentState.LeftThumbStick.x > 0 && t_controller.m_previousState.LeftThumbStick.x == 0))
		{
			m_quizButtons.m_buttons.at(1)->isHighlighted(false);
			m_quizButtons.m_buttons.at(2)->isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadLeft && !t_controller.m_previousState.DpadLeft) || (t_controller.m_currentState.LeftThumbStick.x < 0 && t_controller.m_previousState.LeftThumbStick.x == 0))
		{
			m_quizButtons.m_buttons.at(1)->isHighlighted(false);
			m_quizButtons.m_buttons.at(0)->isHighlighted(true);
		}
	}
	else if (m_quizButtons.m_buttons.at(2)->isHighlighted())
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_quizButtons.m_buttons.at(2)->isHighlighted(false);
			m_selectButton.isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadLeft && !t_controller.m_previousState.DpadLeft) || (t_controller.m_currentState.LeftThumbStick.x < 0 && t_controller.m_previousState.LeftThumbStick.x == 0))
		{
			m_quizButtons.m_buttons.at(2)->isHighlighted(false);
			m_quizButtons.m_buttons.at(1)->isHighlighted(true);
		}
	}
	else if (m_returnButton.isHighlighted())
	{
		if ((t_controller.m_currentState.DpadLeft && !t_controller.m_previousState.DpadLeft) || (t_controller.m_currentState.LeftThumbStick.x < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_returnButton.isHighlighted(false);
			m_selectButton.isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_returnButton.isHighlighted(false);
			m_quizButtons.m_buttons.at(0)->isHighlighted(true);
		}
	}
	else if (m_selectButton.isHighlighted())
	{
		if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_selectButton.isHighlighted(false);
			m_quizButtons.m_buttons.at(0)->isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadRight && !t_controller.m_previousState.DpadRight) || (t_controller.m_currentState.LeftThumbStick.x > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_selectButton.isHighlighted(false);
			m_returnButton.isHighlighted(true);
		}
	}
	if (m_returnButton.isPressed())
	{
		t_currentScreen = CurrentScreen::MAINMENU;
		for (int i = 0; i < 3; i++)
		{
			m_quizButtons.fullReset();
		}
		m_quizButtons.m_buttons.at(0)->isHighlighted(true);
		m_quizButtons.m_buttons.at(0)->m_isPressed = true;
		m_returnButton.reset();
		m_selectButton.reset();
	}
	if (m_selectButton.isPressed())
	{
		bool quizSelected = false;
		if (m_quizButtons.m_buttons.at(0)->m_isPressed == true)
		{
			t_currentQuiz = CurrentQuiz::QUIZ1;
			quizSelected = true;
		}
		else if (m_quizButtons.m_buttons.at(1)->m_isPressed == true)
		{
			t_currentQuiz = CurrentQuiz::QUIZ2;
			quizSelected = true;
		}
		else if (m_quizButtons.m_buttons.at(2)->m_isPressed == true)
		{
			t_currentQuiz = CurrentQuiz::QUIZ3;
			quizSelected = true;
		}
		else
		{
			m_selectButton.m_isPressed = false;
		}
		if (quizSelected)
		{
			t_currentScreen = CurrentScreen::PLAYING;
			for (int i = 0; i < 3; i++)
			{
				m_quizButtons.fullReset();
			}
			m_quizButtons.m_buttons.at(0)->isHighlighted(true);
			m_quizButtons.m_buttons.at(0)->m_isPressed = true;
			m_returnButton.reset();
			m_selectButton.reset();
		}
	}
}

void QuizSelectMenu::render(sf::RenderWindow & t_window)
{
	m_quizButtons.render(t_window);
	m_selectButton.render(t_window);
	m_returnButton.render(t_window);
	m_screenLabel.render(t_window);
}
