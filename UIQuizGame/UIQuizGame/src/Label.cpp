#include "Label.h"

Label::Label(std::string t_text, sf::Vector2f &t_pos,sf::Font & t_font, const sf::Color t_color, int t_characterSize)
{
	if (t_text != "")
	{
		m_text.setString(t_text);
		m_text.setCharacterSize(t_characterSize);
		m_text.setFont(t_font);
		m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);
		m_text.setFillColor(t_color);
		m_text.setOutlineColor(sf::Color::Blue);
		m_text.setPosition(t_pos);
	}
}

void Label::init(std::string t_text, sf::Vector2f &t_pos, sf::Font &t_font, sf::Color t_color, int t_characterSize)
{
	m_text.setString(t_text);
	m_text.setCharacterSize(t_characterSize);
	m_text.setFont(t_font);
	m_text.setOrigin(m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().height / 2.0f);
	m_text.setFillColor(t_color);
	m_text.setPosition(t_pos);
}

void Label::position(const sf::Vector2f & t_position)
{
	m_text.setPosition(t_position);
}

void Label::string(const std::string & t_string)
{
	m_text.setString(t_string);
}

void Label::render(sf::RenderWindow & t_window)
{
	if (m_text.getString() != "")
	{
		t_window.draw(m_text);
	}
}
