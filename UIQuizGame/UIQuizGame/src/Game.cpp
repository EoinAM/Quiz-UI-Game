#include "Game.h"


Game::Game(sf::Font &t_font, sf::Texture &t_buttonSprite) :
	m_window(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height), "UI Quiz Game"),
	m_currentScreen{CurrentScreen::AUTHOR},
	m_keyboard(m_controller, t_font,t_buttonSprite),
	m_mainMenu(t_font, t_buttonSprite),
	m_options(t_font, t_buttonSprite),
	m_splashScreen(m_window, m_controller, t_font),
	m_authorScreen(m_window, t_font),
	m_licenseScreen(m_window,t_font),
	m_helpMenu(t_font, t_buttonSprite),
	m_quizSelectScreen(t_font, t_buttonSprite),
	m_tempQuiz(t_font, t_buttonSprite, m_controller),
	m_highScoreScreen(m_controller, t_font, t_buttonSprite)
{
	m_terminalTexture.loadFromFile("Assets\\terminal.png");
	m_terminalRect.setTexture(&m_terminalTexture);
	m_terminalRect.setFillColor(sf::Color(255, 255, 255, 100));
	m_terminalRect.setSize(sf::Vector2f(ScreenSize::s_width, ScreenSize::s_height));

	m_screenTexture.loadFromFile("Assets\\screen.png");
	m_screenRect.setTexture(&m_screenTexture);
	m_screenRect.setFillColor(sf::Color(164, 97, 45, 255));
	m_screenRect.setSize(sf::Vector2f(ScreenSize::s_width, ScreenSize::s_height));

}

void Game::run()
{
	sf::Clock clock;
	sf::Time lag = sf::Time::Zero;

	while (m_window.isOpen())
	{
		sf::Time dTime = clock.restart();
		lag += dTime;
		processEvents();
		 
		while (lag > M_MS_PER_UPDATE)
		{
			update(M_MS_PER_UPDATE);
			lag -= M_MS_PER_UPDATE;
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_window.close();
	}
}

void Game::update(sf::Time & t_dTime)
{
	m_controller.update();
	switch (m_currentScreen)
	{
	case AUTHOR:
		m_authorScreen.update();
		if (m_authorScreen.m_finished)
		{
			m_currentScreen = CurrentScreen::LICENCE;
		}
		break;
	case LICENCE:
		m_licenseScreen.update();
		if (m_licenseScreen.m_finished)
		{
			m_currentScreen = CurrentScreen::SPLASH;
		}
		break;
	case SPLASH:
		m_splashScreen.update();
		if (m_splashScreen.m_finished)
		{
			m_currentScreen = CurrentScreen::MAINMENU;
		}
		break;
	case STORY:
		break;
	case MAINMENU:
		m_mainMenu.update(t_dTime, m_controller, m_settings.m_animationScalar, m_currentScreen, m_window);
		m_highScoreScreen.renewScores();
		break;
	case QuizSelect:
		m_quizSelectScreen.update(t_dTime, m_controller, m_currentScreen, m_settings.m_animationScalar, m_currentQuiz);
		break;
	case PLAYING:
		m_tempQuiz.update(t_dTime, m_controller, m_settings.m_animationScalar, m_currentScreen);
		switch (m_currentQuiz)
		{
		case CurrentQuiz::QUIZ1:

			break;
		case CurrentQuiz::QUIZ2:

			break;
		case CurrentQuiz::QUIZ3:

			break;
		default:
			break;
		}
		break;
	case OPTIONS_:
		m_options.update(t_dTime, m_controller, m_settings.m_animationScalar, m_currentScreen, m_window);
		break;
	case Help:
		m_helpMenu.update(t_dTime, m_controller, m_currentScreen, m_settings.m_animationScalar);
		break;
	case HIGHSCORE:
		m_highScoreScreen.update(m_currentScreen);
		break;
	case CREDITS:
		break;
	default:
		break;
	}

	m_controller.m_previousState = m_controller.m_currentState;
}

void Game::render()
{
	m_window.clear();

	switch (m_currentScreen)
	{
	case AUTHOR:
		m_authorScreen.render();
		break;
	case LICENCE:
		m_licenseScreen.render();
		if (m_licenseScreen.m_finished)
		{
			m_currentScreen = CurrentScreen::LICENCE;
		}
		break;
	case SPLASH:
		m_splashScreen.render();
		if (m_splashScreen.m_finished)
		{
			m_currentScreen = CurrentScreen::LICENCE;
		}
		break;
	case STORY:
		break;
	case MAINMENU:
		m_mainMenu.render(m_window);
		break;
	case QuizSelect:
		m_quizSelectScreen.render(m_window);
		break;
	case PLAYING:
		m_tempQuiz.render(m_window);
		switch (m_currentQuiz)
		{
		case CurrentQuiz::QUIZ1:

			break;
		case CurrentQuiz::QUIZ2:

			break;
		case CurrentQuiz::QUIZ3:

			break;
		default:
			break;
		}
		break;
	case OPTIONS_:
		m_options.render(m_window);
		break;
	case Help:
		m_helpMenu.render(m_window);
		break;
	case HIGHSCORE:
		m_highScoreScreen.render(m_window);
		break;
	case CREDITS:
		break;
	default:
		break;
	}

	m_window.draw(m_terminalRect);
	m_window.draw(m_screenRect);
	m_window.display();
}