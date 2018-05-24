#include "RadioButton.h"

RadioButton::RadioButton()
{
}

void RadioButton::createButtons(int t_numberOfButtons)
{
	for (int i = 0; i < t_numberOfButtons; i++)
	{
		m_buttons.push_back(new Button());
	}
	MAX_BUTTONS += t_numberOfButtons;
}

void RadioButton::initButtons(int buttonNum, Button & button)
{
	m_buttons.at(buttonNum)->init(button);
}

void RadioButton::update(sf::Time & t_dTime, const Xbox360Controller &t_controller, const int &t_animationScalar)
{
	for (int i = 0; i < m_buttons.capacity();i++)
	{
		/*int pressedButton = -1;
		if (m_buttons.at(i)->isPressed())
		{
			pressedButton = i;
		}*/
		m_buttons.at(i)->update(t_dTime, t_controller, t_animationScalar);
		/*if (pressedButton != -1)
		{
			m_buttons.at(pressedButton)->m_isPressed = true;
		}*/
		if (m_buttons.at(i)->m_isPressed)
		{
			m_buttons.at(i)->color(sf::Color::Green);
			for (int j = 0; j < m_buttons.capacity(); j++)
			{
				if (j != i)
				{
					m_buttons.at(j)->color(sf::Color::White);
					m_buttons.at(j)->m_isPressed = false;
				}
			}
		}
		else
		{
			m_buttons.at(i)->color(sf::Color::White);
		}
	}
}

void RadioButton::render(sf::RenderWindow & t_window)
{
	for (int i = 0; i < m_buttons.capacity(); i++)
	{
		m_buttons[i]->render(t_window);
	}
}

void RadioButton::resetRemember()
{
	for (int i = 0; i < m_buttons.capacity(); i++)
	{
		bool current = m_buttons.at(i)->isPressed();
		m_buttons.at(i)->reset();
		m_buttons.at(i)->m_isPressed = current;
	}
}

void RadioButton::fullReset()
{
	for (int i = 0; i < m_buttons.capacity(); i++)
	{
		bool current = m_buttons.at(i)->isPressed();
		m_buttons.at(i)->reset();
		m_buttons.at(i)->m_isPressed = current;
	}
}

bool RadioButton::isPressed(int t_buttonNum)
{
	return m_buttons.at(t_buttonNum)->m_isPressed;
}

void RadioButton::position(int t_buttonNum, sf::Vector2f & t_pos)
{
	if (t_buttonNum >=0 || t_buttonNum < m_buttons.capacity())
	{
		m_buttons[t_buttonNum]->position(t_pos);
	}
	else
	{
		return;
	}
}

sf::Vector2f RadioButton::position(const int t_buttonNum)
{
	if (t_buttonNum >= 0 || t_buttonNum < m_buttons.capacity())
	{
		return m_buttons[t_buttonNum]->position();
	}
	else
	{
		return sf::Vector2f(0,0);
	}
}

void RadioButton::size(int t_buttonNum, sf::Vector2f & t_size)
{
	if (t_buttonNum >= 0 || t_buttonNum < m_buttons.capacity())
	{
		m_buttons[t_buttonNum]->size(t_size);
	}
	else
	{
		return;
	}
}

sf::Vector2f RadioButton::size(int t_buttonNum)
{
	if (t_buttonNum >= 0 || t_buttonNum < m_buttons.capacity())
	{
		return m_buttons[t_buttonNum]->size();;
	}
	else
	{
		return sf::Vector2f(0, 0);
	}
}

void RadioButton::color(int t_buttonNum, const sf::Color & t_color)
{
	if (t_buttonNum >= 0 || t_buttonNum < m_buttons.capacity())
	{
		m_buttons[t_buttonNum]->color(t_color);
	}
	else
	{
		return;
	}
}

sf::Color RadioButton::color(int t_buttonNum)
{
	if (t_buttonNum >= 0 || t_buttonNum < m_buttons.capacity())
	{
		return m_buttons[t_buttonNum]->color();
	}
	else
	{
		return sf::Color::Cyan;
	}
}

void RadioButton::isHighlighted(int t_buttonNum, const bool t_boolean)
{
	if (t_buttonNum >= 0 || t_buttonNum < m_buttons.capacity())
	{
		return m_buttons[t_buttonNum]->isHighlighted(t_boolean);
	}
	else
	{
		return;
	}
}

bool RadioButton::isHighlighted(int t_buttonNum)
{
	if (t_buttonNum >= 0 || t_buttonNum < m_buttons.capacity())
	{
		return m_buttons[t_buttonNum]->isHighlighted();
	}
	else
	{
		return false;
	}
}
