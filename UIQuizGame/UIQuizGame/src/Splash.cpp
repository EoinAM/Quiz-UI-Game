#include "Splash.h"


SplashScreen::SplashScreen(sf::RenderWindow & t_window, Xbox360Controller & t_controller, sf::Font & t_font) :
	m_logoAnimation(m_logoShape, 30, m_logoTexture, m_logoRect),
	m_font(t_font),
	m_controller(t_controller),
	m_window(t_window)
{
	m_logoTexture.loadFromFile("Assets\\logo\\GearSprite2.png");
	m_logoShape.setSize(sf::Vector2f(m_logoRect.width, m_logoRect.height));
	m_logoShape.setTexture(&m_logoTexture);
	m_logoShape.setTextureRect(m_logoRect);
	m_logoShape.setOrigin(m_logoShape.getGlobalBounds().width * .5, m_logoShape.getGlobalBounds().height* .5);
	m_logoShape.setPosition(sf::Vector2f(ScreenSize::s_width * .40,m_logoShape.getGlobalBounds().height - 50));
	
	m_keyText.setFont(m_font);
	m_keyText.setString("Button");
	m_keyText.setCharacterSize(70);
	m_keyText.setPosition(ScreenSize::s_width, ScreenSize::s_height * .6);
	m_keyText.setFillColor(sf::Color(20, 90, 50, m_opacity));

	m_AText.setFont(m_font);
	m_AText.setString("The A");
	m_AText.setCharacterSize(70);
	m_AText.setOrigin(m_AText.getGlobalBounds().width / 2, m_AText.getGlobalBounds().height / 2);
	m_AText.setPosition((ScreenSize::s_width * .38), ScreenSize::s_height + 200);
	m_AText.setFillColor(sf::Color(20, 90, 50, m_opacity));

	m_pressText.setFont(m_font);
	m_pressText.setString("Press");
	m_pressText.setCharacterSize(70);
	m_pressText.setPosition(sf::Vector2f(-200, ScreenSize::s_height * .6));
	m_pressText.setFillColor(sf::Color(20, 90, 50, m_opacity));
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::update()
{
	switch (m_currentState)
	{
	case AnimationState::NONE:
		m_logoAnimation.update();
		
		if (m_opacity >= 254 || m_opacity <= 10)
		{
			m_opacityOffset *= -1;
		}
		
		m_opacity += m_opacityOffset;
		m_pressText.setFillColor(sf::Color(20, 90, 50, m_opacity));
		m_AText.setFillColor(sf::Color(20, 90, 50, m_opacity));
		m_keyText.setFillColor(sf::Color(20, 90, 50, m_opacity));

		if (m_controller.m_currentState.A)
		{
			m_currentState = AnimationState::DISAPPEAR;
		}
		break;

		break;
	case AnimationState::APPEAR:
		m_logoAnimation.update();

		if (m_pressText.getPosition().x <= 450)
		{
			m_pressText.setPosition(m_pressText.getPosition().x + 2.8, m_pressText.getPosition().y);
		}

		if (m_keyText.getPosition().x >= 850)
		{
			m_keyText.setPosition(m_keyText.getPosition().x - 4, m_keyText.getPosition().y);
		}
		
		if (m_AText.getPosition().y >= m_keyText.getPosition().y + (m_AText.getOrigin().y))
		{
			m_AText.setPosition(m_AText.getPosition().x, m_AText.getPosition().y - 2);
			m_AText.setRotation(m_AText.getRotation() + 8);
			if (m_AText.getPosition().y <= m_keyText.getPosition().y + (m_AText.getOrigin().y))
			{
				m_AText.setRotation(0);
				m_currentState = AnimationState::NONE;
			}
		}
		break;
	case AnimationState::DISAPPEAR:
		if (m_logoShape.getPosition().y + m_logoShape.getOrigin().y < m_pressText.getPosition().y && m_hit == false)
		{
			m_logoShape.setPosition(m_logoShape.getPosition().x, m_logoShape.getPosition().y + 2);
		}
		if (m_logoShape.getPosition().y + m_logoShape.getOrigin().y >= m_pressText.getPosition().y && m_hit == false)
		{
			m_hit = true;
		}
		if (m_hit && !m_logoShape.getPosition().y - m_logoShape.getOrigin().y <= 0)
		{
			m_logoShape.setPosition(m_logoShape.getPosition().x, m_logoShape.getPosition().y - 1);
			m_pressText.setPosition(m_pressText.getPosition().x, m_pressText.getPosition().y + 1);
			m_pressText.setRotation(m_pressText.getRotation() + 2);

			m_AText.setPosition(m_AText.getPosition().x, m_AText.getPosition().y + 1);
			m_AText.setRotation(m_AText.getRotation() - 2);

			m_keyText.setPosition(m_keyText.getPosition().x, m_keyText.getPosition().y + 2);
			m_keyText.setRotation(m_keyText.getRotation() + 4);
		}

		if (m_hit && m_logoShape.getPosition().y + m_logoShape.getOrigin().y <= 0)
		{
			m_finished = true;
		}
		break;
	default:
		break;
	}

}

void SplashScreen::render()
{
	m_window.draw(m_logoShape);
	m_window.draw(m_AText);
	m_window.draw(m_pressText);
	m_window.draw(m_keyText);

}
