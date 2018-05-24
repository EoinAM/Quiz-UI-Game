#include "HighScoreScreen.h"

HighScoreScreen::HighScoreScreen(Xbox360Controller & t_controller, sf::Font & t_font, sf::Texture t_buttonTexture) :
	m_font(t_font),
	m_controller(t_controller),
	m_buttonTexture(t_buttonTexture)
{
	m_returnButton.init(sf::Vector2f(ScreenSize::s_width* .5, ScreenSize::s_height * .5), sf::Vector2f(100, 20), true, t_buttonTexture, Label("Return"));
	loadScores();
	labelInit();
}


HighScoreScreen::~HighScoreScreen()
{
}

void HighScoreScreen::update(CurrentScreen & t_currentScreen)
{
	if (m_controller.m_currentState.A)
	{
		t_currentScreen = CurrentScreen::MAINMENU;
	}
}

void HighScoreScreen::loadScores()
{
	highScores.open("highscores.txt");
	while (!highScores.eof())
	{
		std::string str;
		std::getline(highScores, str);
		m_scores.push_back(str);
	}
	highScores.close();
}

void HighScoreScreen::labelInit()
{
	for (int i = 0; i < m_scores.size() ; i++)
	{
		Label label;
		label.init("", sf::Vector2f(ScreenSize::s_width * .1, ScreenSize::s_height * .2 + (70 * i)), m_font, sf::Color::White, 50);
		m_labels.push_back(label);
	}
	for (int i = 0; i < m_scores.size(); i++)
	{
		m_labels[i].m_text.setString(m_scores[i]);
	}
}


void HighScoreScreen::renewScores()
{
	m_scores.clear();
	loadScores();
	m_labels.clear();
	labelInit();
	
}

void HighScoreScreen::render(sf::RenderWindow & t_window)
{
	for (int i = 0; i < m_scores.size(); i++)
	{
		m_labels[i].render(t_window);
	}
	m_returnButton;
}