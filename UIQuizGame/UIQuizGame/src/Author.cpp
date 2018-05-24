#include "Author.h"

AuthorScreen::AuthorScreen(sf::RenderWindow & t_window, sf::Font & t_font) :
	m_font(t_font),
	m_window(t_window)
{
	m_madeByText.setFont(m_font);
	m_madeByText.setFillColor(sf::Color(20, 90, 50, 255));
	m_madeByText.setPosition(m_madePosition);
	m_madeByText.setString(First_MESSAGE);	// "Made By"
	m_madeByText.setCharacterSize(150);
	m_madeByText.setOrigin(m_madeByText.getGlobalBounds().width / 2, m_madeByText.getGlobalBounds().height / 2);

	m_nameText.setFont(m_font);
	m_nameText.setFillColor(sf::Color(20, 90, 50,255));
	m_nameText.setPosition(m_namePosition);
	m_nameText.setCharacterSize(120);
	m_nameText.setScale(.62, 1.3);
	m_nameText.setOrigin(m_nameText.getGlobalBounds().width / 2, m_nameText.getGlobalBounds().height / 2);
	m_nameText.setString(SECOND_MESSAGE);

	m_coverSquare.setSize(sf::Vector2f(m_madeByText.getGlobalBounds().width, m_madeByText.getGlobalBounds().height + 50));
	m_coverSquare.setPosition(m_finalmadePosition.x - m_madeByText.getOrigin().x, m_finalmadePosition.y -60);
	m_coverSquare.setFillColor(sf::Color::Black);

	m_finalmadePosition = sf::Vector2f( ScreenSize::s_width * .3, 318 );

	m_textLenght = strlen(First_MESSAGE);
}

AuthorScreen::~AuthorScreen()
{
}

void AuthorScreen::update()
{
	switch (m_currentState)
	{
	case AnimationState::NONE:
		m_exitTimer++;

		if (m_exitTimer >= 20)
		{
			m_currentState = AnimationState::DISAPPEAR;
		}
		break;
	case AnimationState::APPEAR:
		if (m_madePosition.x < m_finalmadePosition.x)
		{
			m_madeByText.setRotation(m_rotation);
			m_madeByText.setPosition(m_madePosition);
			m_madePosition.x += 3;
			m_rotation += 8;
		}
		if (m_madePosition.x >= m_finalmadePosition.x && m_namePosition.y < m_finalnamePosition.y)
		{
			m_madeByText.setRotation(0);
			m_namePosition.y++;
			m_nameText.setPosition(m_namePosition);
		}

		if (m_madePosition.x >= m_finalmadePosition.x && m_namePosition.y == m_finalnamePosition.y)
		{
			m_currentState = AnimationState::NONE;
		}
		break;
	case AnimationState::DISAPPEAR:
		if (m_namePosition.y > m_finalnamePosition.y);
		{
			m_namePosition.y--;
			m_nameText.setPosition(m_namePosition);
		}
		if (m_namePosition.y == m_coverSquare.getPosition().y)
		{
			m_nameText.setString("");
			m_madeMove = true;
		}
		if (m_madeMove)
		{
			moveArray();
		}
		break;
	default:
		break;
	}
}

void AuthorScreen::render()
{
	
	m_window.draw(m_nameText);
	m_window.draw(m_coverSquare);
	m_window.draw(m_madeByText);
}

void AuthorScreen::moveArray()
{
	if (m_madeByText.getPosition().x < ScreenSize::s_width)
	{
		m_madeByText.setPosition(m_madeByText.getPosition().x + 5, m_madeByText.getPosition().y);
	}
	if (m_madeByText.getPosition().x >= ScreenSize::s_width)
	{
		m_finished = true;
	}
}
