#include "Button.h"

Button::Button()
{
	m_body.setOrigin(m_body.getSize().x / 2.0, m_body.getSize().y / 2.0);
	m_body.setOutlineColor(sf::Color::White);
	init();
}


void Button::init(sf::Vector2f &t_pos, sf::Vector2f &t_size, const bool &t_isHighlighed, sf::Texture &t_texture, Label &t_label, const sf::Color &t_color)
{
	position(t_pos);
	size(t_size);
	color(t_color);
	m_isHighlighted = t_isHighlighed;
	m_body.setOrigin(m_body.getSize().x / 2.0, m_body.getSize().y / 2.0);
	m_body.setTexture(&t_texture);
	m_body.setTextureRect(sf::IntRect(0, 0, 100, 41));
	m_buttonLabel = Label(t_label);
}

void Button::init(Button & t_button)
{
	position(t_button.position());
	size(t_button.size());
	color(t_button.color());
	m_isHighlighted = t_button.isHighlighted();
	m_body.setOrigin(m_body.getSize().x / 2.0, m_body.getSize().y / 2.0);
	m_body.setTexture(t_button.m_body.getTexture());
	m_body.setTextureRect(sf::IntRect(0, 0, 100, 41));
	m_buttonLabel = Label(t_button.m_buttonLabel);
}

void Button::update(const sf::Time & t_dTime, const Xbox360Controller & t_controller, const int &t_animationScalar)
{
	if (m_isHighlighted)
	{
		if (!m_prevIsHighlighted)
		{
			m_highlightOnAnimation = true;
		}
		if (m_highlightOnAnimation)
		{
			if (m_body.getOutlineThickness() < 5)
			{
				m_body.setOutlineThickness(m_body.getOutlineThickness() + (0.4f * t_animationScalar));
			}
			else
			{
				m_highlightOnAnimation = false;
			}
		}
		if ( !m_isPressed && !t_controller.m_previousState.A && t_controller.m_currentState.A)
		{
			m_isPressed = true;
		}
		else if (m_isPressed && (!t_controller.m_previousState.A && t_controller.m_currentState.A))
		{
			m_isPressed = false;
		}
	}
	else
	{
		if (m_body.getOutlineThickness() > 0)
		{
			m_body.setOutlineThickness(m_body.getOutlineThickness() - (0.4f * t_animationScalar));
		}
		else
		{
			m_body.setOutlineThickness(0);
			m_highlightOnAnimation = false;
		}
	}
	m_prevIsHighlighted = m_isHighlighted;
}

void Button::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
	m_buttonLabel.render(t_window);
}

bool Button::isPressed()
{
	return m_isPressed;
}

void Button::size(sf::Vector2f & t_size)
{
	m_body.setSize(t_size);
	m_body.setOrigin(0.5f * t_size.x, 0.5f * t_size.y);
}

sf::Vector2f Button::size()
{
	return m_body.getSize();
}

void Button::position(sf::Vector2f & t_pos)
{
	m_body.setPosition(t_pos);
}

sf::Vector2f Button::position()
{
	return m_body.getPosition();
}

void Button::color(const sf::Color & t_color)
{
	m_body.setFillColor(t_color);
}

sf::Color Button::color()
{
	return m_body.getFillColor();
}

void Button::isHighlighted(const bool t_boolean)
{
	m_isHighlighted = t_boolean;
}

bool Button::isHighlighted()
{
	return m_isHighlighted;
}

sf::RectangleShape Button::body()
{
	return m_body;
}

void Button::reset()
{
	m_isPressed = false;
	m_isHighlighted = false;
	m_prevIsHighlighted = false;
	m_highlightOnAnimation = false;
	m_highlightOffAnimation = false;
	m_body.setOutlineThickness(0);
}
