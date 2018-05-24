#include "..\include\MainMenu.h"

MainMenu::MainMenu(sf::Font & t_font, sf::Texture & t_texture)
{
	m_gameTitle.init("Television Quiz", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, 200), t_font, sf::Color::Red, 40);


	m_mainMenuButtons[0].init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) - 200), sf::Vector2f(200, 50), true, t_texture, Label("Play", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) - 200), t_font));
	m_mainMenuButtons[1].init(sf::Vector2f(ScreenSize::s_width / 2.0f-  200, (ScreenSize::s_height / 2.0f) - 100), sf::Vector2f(200, 50), false, t_texture, Label("Help", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) - 100), t_font));
	m_mainMenuButtons[2].init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f)), sf::Vector2f(200, 50), false, t_texture, Label("Options", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f)), t_font));
	m_mainMenuButtons[3].init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 100), sf::Vector2f(200, 50), false, t_texture, Label("HighScores", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 100), t_font));
	m_mainMenuButtons[4].init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 200), sf::Vector2f(200, 50), false, t_texture, Label("Exit", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 200), t_font));

	m_confirmBoard.setFillColor(sf::Color::Blue);
	m_confirmBoard.setSize(sf::Vector2f(600,200));
	m_confirmBoard.setPosition(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f));
	m_confirmBoard.setOrigin(m_confirmBoard.getSize().x / 2.0, m_confirmBoard.getSize().y / 2.0);

	m_confirmTitle.init("Are You Sure?", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) - 50), t_font);

	m_confirmButtons[0].init(sf::Vector2f(ScreenSize::s_width / 2.0f - 320, (ScreenSize::s_height / 2.0f) + 50), sf::Vector2f(100, 50), false, t_texture, Label("Yes", sf::Vector2f(ScreenSize::s_width / 2.0f - 320, (ScreenSize::s_height / 2.0f) + 50), t_font));
	m_confirmButtons[1].init(sf::Vector2f(ScreenSize::s_width / 2.0f-90, (ScreenSize::s_height / 2.0f) + 50), sf::Vector2f(100, 50), false, t_texture, Label("No", sf::Vector2f(ScreenSize::s_width / 2.0f - 90, (ScreenSize::s_height / 2.0f) + 50), t_font));
}

void MainMenu::update(const sf::Time & t_dTime, const Xbox360Controller & t_controller, const int & t_animationScalar, CurrentScreen & t_currentScreen, sf::RenderWindow &t_window)
{
	switch (m_currentState)
	{
	case MainStates::MainMenu:
	{
		int activeButton = 0;
		for (int i = 0; i < M_MAX_BUTTONS; i++)
		{
			if (m_mainMenuButtons[i].isHighlighted())
			{
				activeButton = i;
				break;
			}
		}
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			if (activeButton != M_MAX_BUTTONS - 1)
			{
				m_mainMenuButtons[activeButton].isHighlighted(false);
				m_mainMenuButtons[activeButton + 1].isHighlighted(true);
			}
		}
		else if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			if (activeButton != 0)
			{
				m_mainMenuButtons[activeButton].isHighlighted(false);
				m_mainMenuButtons[activeButton - 1].isHighlighted(true);
			}
		}

		for (int i = 0; i < M_MAX_BUTTONS; i++)
		{
			m_mainMenuButtons[i].update(t_dTime, t_controller, t_currentScreen);
		}
		if (m_mainMenuButtons[0].isPressed())
		{
			for (int i = 0; i < M_MAX_BUTTONS; i++)
			{
				m_mainMenuButtons[i].reset();
			}
			t_currentScreen = CurrentScreen::QuizSelect;
			m_mainMenuButtons[0].isHighlighted(true);
		}
		else if (m_mainMenuButtons[1].isPressed())
		{
			for (int i = 0; i < M_MAX_BUTTONS; i++)
			{
				m_mainMenuButtons[i].reset();
			}
			t_currentScreen = CurrentScreen::Help;
			m_mainMenuButtons[1].isHighlighted(true);
		}
		else if (m_mainMenuButtons[2].isPressed())
		{
			for (int i = 0; i < M_MAX_BUTTONS; i++)
			{
				m_mainMenuButtons[i].reset();
			}
			t_currentScreen = CurrentScreen::OPTIONS_;
			m_mainMenuButtons[2].isHighlighted(true);
		}
		else if (m_mainMenuButtons[3].isPressed())
		{
			for (int i = 0; i < M_MAX_BUTTONS; i++)
			{
				m_mainMenuButtons[i].reset();
			}
			t_currentScreen = CurrentScreen::HIGHSCORE;
			m_mainMenuButtons[3].isHighlighted(true);
		}
		else if (m_mainMenuButtons[4].isPressed())
		{
			for (int i = 0; i < M_MAX_BUTTONS; i++)
			{
				m_mainMenuButtons[i].reset();
			}
			m_mainMenuButtons[4].isHighlighted(true);
			m_currentState = MainStates::Confirmation;
			for (int i = 0; i < 2; i++)
			{
				m_confirmButtons[i].reset();
			}
			m_confirmButtons[0].isHighlighted(true);
		}
		break;
	}
	case MainStates::Confirmation:
	{
		int activeButton = 0;
		for (int i = 0; i < 2; i++)
		{
			if (m_confirmButtons[i].isHighlighted())
			{
				activeButton = i;
				break;
			}
		}

		if ((t_controller.m_currentState.DpadRight && !t_controller.m_previousState.DpadRight) || (t_controller.m_currentState.LeftThumbStick.x > 0 && t_controller.m_previousState.LeftThumbStick.x == 0))
		{
			if (activeButton != 2 - 1)
			{
				m_confirmButtons[activeButton].isHighlighted(false);
				m_confirmButtons[activeButton + 1].isHighlighted(true);
			}
		}
		else if ((t_controller.m_currentState.DpadRight && !t_controller.m_previousState.DpadRight) || (t_controller.m_currentState.LeftThumbStick.x < 0 && t_controller.m_previousState.LeftThumbStick.x == 0))
		{
			if (activeButton != 0)
			{
				m_confirmButtons[activeButton].isHighlighted(false);
				m_confirmButtons[activeButton - 1].isHighlighted(true);
			}
		}

		for (int i = 0; i < 2; i++)
		{
			m_confirmButtons[i].update(t_dTime, t_controller, t_currentScreen);
		}
		if (m_confirmButtons[0].isPressed())
		{
			t_window.close();
		}
		else if (m_confirmButtons[1].isPressed())
		{
			m_currentState = MainStates::MainMenu;
		}
		break;
	}
	}
}

void MainMenu::render(sf::RenderWindow & t_window)
{
	m_gameTitle.render(t_window);
	for (int i = 0; i < M_MAX_BUTTONS; i++)
	{
		m_mainMenuButtons[i].render(t_window);
	}
	if (m_currentState == MainStates::Confirmation)
	{
		t_window.draw(m_confirmBoard);
		m_confirmTitle.render(t_window);
		for (int i = 0; i < 2; i++)
		{
			m_confirmButtons[i].render(t_window);
		}
	}
}
