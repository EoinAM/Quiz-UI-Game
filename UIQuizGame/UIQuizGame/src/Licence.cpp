#include "Licence.h"

LicenseScreen::LicenseScreen(sf::RenderWindow & t_window, sf::Font & t_font) :
	m_window(t_window),
	m_font(t_font)
{

	m_sfmlTexture.loadFromFile("Assets\\sfml.png");

	m_sfmlLogo.setTexture(m_sfmlTexture);
	m_sfmlLogo.setPosition(ScreenSize::s_width * .4, ScreenSize::s_height * .4);
	m_sfmlLogo.setOrigin(m_sfmlLogo.getGlobalBounds().width / 2, m_sfmlLogo.getGlobalBounds().height / 2);
	m_sfmlLogo.setScale(sf::Vector2f(m_scale, m_scale));
	m_sfmlLogo.setColor(sf::Color(20, 90, 50, m_logoOpacity));

	m_sfmlText.setFillColor(sf::Color(20, 90, 50,255));
	m_sfmlText.setFont(m_font);
	m_sfmlText.setString("SFML");
	m_sfmlText.setCharacterSize(90);
	m_sfmlText.setPosition(650, 685);

	setupArrays();
}

LicenseScreen::~LicenseScreen()
{
}

void LicenseScreen::update()
{
	switch (m_currentState)
	{
	case AnimationState::NONE:
		m_waitTimer++;
		if (m_waitTimer >= 30)
		{
			m_madeDrawn = false;
			if (m_waitTimer >= 200)
			{
				m_sfmlText.setString("");
				m_currentState = AnimationState::DISAPPEAR;
			}
		}
		break;
	case AnimationState::APPEAR:
		if (m_logoOpacity < 255)
		{
			m_logoOpacity += 1;
			m_sfmlLogo.setColor(sf::Color(255, 255, 255, m_logoOpacity));
		}
		if (m_logoOpacity == 255)
		{
			moveArray();
		}

		break;
	case AnimationState::DISAPPEAR:
		if (m_sfmlLogo.getScale().x < 2)
		{
			m_rotation++;
			m_sfmlLogo.setRotation(m_rotation);
			m_sfmlLogo.setScale(m_sfmlLogo.getScale().x + m_scaleoffset, m_sfmlLogo.getScale().y + m_scaleoffset);
		}
		if (m_sfmlLogo.getScale().x >= 2)
		{
			m_finished = true;
		}
		break;
	default:
		break;
	}
}

void LicenseScreen::render()
{
	m_window.draw(m_sfmlLogo);

	if (m_madeDrawn)
	{
		for (int i = 0; i < MAXCHARACTERS; i++)
		{
			m_window.draw(m_madeUsingText[i]);
		}
	}
	if (m_madeDrawn == false)
	{
		m_window.draw(m_sfmlText);
	}
}

void LicenseScreen::moveArray()
{
	for (int i = 1; i < MAXCHARACTERS; i++)
	{
		if (m_madeUsingText[0].getPosition().y > m_finalTextPosition.y)
		{
			m_madeUsingText[0].setPosition(m_madeUsingText[0].getPosition().x, m_madeUsingText[0].getPosition().y - 2);
		}

		if (m_madeUsingText[i - 1].getPosition().y == m_finalTextPosition.y)
		{
			if (m_madeUsingText[i].getPosition().y > m_finalTextPosition.y)
			{
				m_madeUsingText[i].setPosition(m_madeUsingText[i].getPosition().x, m_madeUsingText[i].getPosition().y - 10);
			}
		}

		if (m_madeUsingText[MAXCHARACTERS - 1].getPosition().y <= m_finalTextPosition.y)
		{
			m_currentState = AnimationState::NONE;
		}
	}
}

void LicenseScreen::setupArrays()
{
	for (int i = 0; i < MAXCHARACTERS; i++)
	{
		m_madeUsingText[i].setString(m_madeUsingString[i]);
		m_madeUsingText[i].setFillColor(sf::Color(20, 90, 50,255));
		m_madeUsingText[i].setFont(m_font);
		m_madeUsingText[i].setCharacterSize(50);
		m_madeUsingText[i].setPosition(m_startTextPosition.x + 50 * i, m_startTextPosition.y);
	}
}
