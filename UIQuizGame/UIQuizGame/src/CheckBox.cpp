#include "..\include\CheckBox.h"

void CheckBox::update(const sf::Time & t_dTime, const Xbox360Controller & t_controller, const int & t_animationScalar)
{
	m_button.update(t_dTime, t_controller, t_animationScalar);
	if (m_button.isPressed())
	{
		m_button.color(sf::Color::Blue);
	}
	else
	{
		m_button.color(sf::Color::White);
	}
}

void CheckBox::render(sf::RenderWindow & t_window)
{
	m_button.render(t_window);
}

void CheckBox::reset()
{
	bool currentStatus = m_button.isPressed();
	m_button.reset();
	m_button.m_isPressed = currentStatus;
}

bool CheckBox::isPressed()
{
	return m_button.isPressed();
}

void CheckBox::size(sf::Vector2f & t_size)
{
	m_button.size(t_size);
}

sf::Vector2f CheckBox::size()
{
	return m_button.size();
}

void CheckBox::position(sf::Vector2f & t_pos)
{
	m_button.position(t_pos);
}

sf::Vector2f CheckBox::position()
{
	return m_button.position();
}

void CheckBox::color(const sf::Color & t_color)
{
	m_button.color(t_color);
}

sf::Color CheckBox::color()
{
	return m_button.color();;
}

void CheckBox::isHighlighted(const bool t_boolean)
{
	m_button.isHighlighted(t_boolean);
}

bool CheckBox::isHighlighted()
{
	return m_button.isHighlighted();
}

sf::RectangleShape CheckBox::body()
{
	return m_button.body();
}

void CheckBox::init(sf::Vector2f & t_pos, sf::Vector2f & t_size, const bool & t_isHighlighed, sf::Texture & t_texture, Label & t_label, const sf::Color & t_color)
{
	position(t_pos);
	size(t_size);
	color(t_color);
	m_isHighlighted = t_isHighlighed;
	m_button.m_body.setOrigin(m_button.m_body.getSize().x / 2.0, m_button.m_body.getSize().y / 2.0);
	m_button.m_body.setOrigin(m_button.m_body.getSize().x / 2.0, m_button.m_body.getSize().y / 2.0);
	m_button.m_body.setOrigin(m_button.m_body.getSize().x / 2.0, m_button.m_body.getSize().y / 2.0);
	m_button.m_body.setTexture(&t_texture);
	m_button.m_buttonLabel = Label(t_label);
}

void CheckBox::init(Button & button)
{
	m_button.init(button);
}
