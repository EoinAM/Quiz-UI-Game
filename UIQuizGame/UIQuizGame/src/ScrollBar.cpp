#include "ScrollBar.h"

void ScrollBar::init(sf::Vector2f &t_position, Label & t_label, int const t_barLength, bool const t_highlighted, float t_initialValue, BarOrientation t_orientation)
{
	m_orientation = t_orientation;
	switch (m_orientation)
	{
	case BarOrientation::Horizontal:
	{
		if (t_initialValue > 100 || t_initialValue < 0)
		{
			throw std::invalid_argument("The value passed to initial value is a percentage so needs to be between 0  and 100.");
		}
		m_barLength = t_barLength;
		m_isHighlighted = t_highlighted;
		m_currnetValue = t_initialValue;

		//set up the endpoints, the middle bar, the label, scroll indicator, positions
		m_label = Label(t_label);
		m_label.position(t_position);

		m_endpoints[0].setPosition(t_position + sf::Vector2f(200, 0));
		m_endpoints[0].setFillColor(sf::Color::White);
		m_endpoints[0].setRadius(10);
		m_endpoints[0].setOrigin(m_endpoints[0].getRadius(), m_endpoints[0].getRadius());

		m_endpoints[1].setPosition(m_endpoints[0].getPosition() + sf::Vector2f(t_barLength, 0));
		m_endpoints[1].setFillColor(sf::Color::White);
		m_endpoints[1].setRadius(10);
		m_endpoints[1].setOrigin(m_endpoints[1].getRadius(), m_endpoints[1].getRadius());

		m_centreBar.setPosition(m_endpoints[0].getPosition().x + ((m_endpoints[1].getPosition().x - m_endpoints[0].getPosition().x) / 2), m_endpoints[0].getPosition().y);
		m_centreBar.setSize(sf::Vector2f(t_barLength, 10));
		m_centreBar.setOrigin(m_centreBar.getSize().x / 2, m_centreBar.getSize().y / 2);
		m_centreBar.setFillColor(sf::Color::White);


		m_scrollIndicator.setPosition(m_endpoints[0].getPosition().x + (t_barLength * (t_initialValue / 100)), m_endpoints[0].getPosition().y);
		m_scrollIndicator.setSize(sf::Vector2f(20, 50));
		m_scrollIndicator.setOrigin(m_scrollIndicator.getSize().x / 2, m_scrollIndicator.getSize().y / 2);
		m_scrollIndicator.setFillColor(sf::Color::White);
		break;
	}
	case BarOrientation::Vertical:
	{
		if (t_initialValue > 100 || t_initialValue < 0)
		{
			throw std::invalid_argument("The value passed to initial value is a percentage so needs to be between 0  and 100.");
		}
		m_barLength = t_barLength;
		m_isHighlighted = t_highlighted;
		m_currnetValue = t_initialValue;

		//set up the endpoints, the middle bar, the label, scroll indicator, positions
		m_label = Label(t_label);
		m_label.position(t_position);

		m_endpoints[0].setPosition(t_position + sf::Vector2f(200, -m_barLength / 2.0f));
		m_endpoints[0].setFillColor(sf::Color::White);
		m_endpoints[0].setRadius(10);
		m_endpoints[0].setOrigin(m_endpoints[0].getRadius(), m_endpoints[0].getRadius());

		m_endpoints[1].setPosition(m_endpoints[0].getPosition() + sf::Vector2f(t_barLength, m_barLength / 2.0f));
		m_endpoints[1].setFillColor(sf::Color::White);
		m_endpoints[1].setRadius(10);
		m_endpoints[1].setOrigin(m_endpoints[1].getRadius(), m_endpoints[1].getRadius());

		m_centreBar.setPosition(m_endpoints[0].getPosition().x , m_endpoints[0].getPosition().y + ((m_endpoints[1].getPosition().y - m_endpoints[0].getPosition().y) / 2.0f));
		m_centreBar.setSize(sf::Vector2f(10, m_barLength));
		m_centreBar.setOrigin(m_centreBar.getSize().x / 2, m_centreBar.getSize().y / 2);
		m_centreBar.setFillColor(sf::Color::White);


		m_scrollIndicator.setPosition(m_endpoints[0].getPosition().x, m_endpoints[0].getPosition().y - (t_barLength * (t_initialValue / 100)));
		m_scrollIndicator.setSize(sf::Vector2f(50, 20));
		m_scrollIndicator.setOrigin(m_scrollIndicator.getSize().x / 2, m_scrollIndicator.getSize().y / 2);
		m_scrollIndicator.setFillColor(sf::Color::White);
		break;
	}
	}
}

void ScrollBar::update(sf::Time t_dTime, Xbox360Controller & t_controller, const int &t_animationScalar)
{
	if (m_isHighlighted)
	{
		if (!m_prevIsHighlighted)
		{
			m_highlightOnAnimation = true;
		}
		if (m_highlightOnAnimation)
		{
			if (m_label.m_text.getOutlineThickness() < 5)
			{
				m_label.m_text.setOutlineThickness(m_label.m_text.getOutlineThickness() + (0.4f * t_animationScalar));
			}
			else
			{
				m_highlightOnAnimation = false;
			}
		}
	}
	else
	{
		if (m_label.m_text.getOutlineThickness() > 0)
		{
			m_label.m_text.setOutlineThickness(m_label.m_text.getOutlineThickness() - (0.4f * t_animationScalar));
		}
		else
		{
			m_label.m_text.setOutlineThickness(0);
			m_highlightOnAnimation = false;
		}
	}
	m_prevIsHighlighted = m_isHighlighted;


	switch (m_orientation)
	{
	case BarOrientation::Horizontal:
		if (m_isHighlighted)
		{
			if (t_controller.m_currentState.LeftThumbStick.x > 0)
			{
				m_currnetValue += 0.5;
			}
			else if (t_controller.m_currentState.LeftThumbStick.x < 0)
			{
				m_currnetValue -= 0.5;
			}
		}


		break;
	case BarOrientation::Vertical:
		if (m_isHighlighted)
		{
			if (t_controller.m_currentState.LeftThumbStick.y > 0)
			{
				m_currnetValue+= 0.5;
			}
			else if (t_controller.m_currentState.LeftThumbStick.y < 0)
			{
				m_currnetValue-= 0.5;
			}
		}


		break;
	default:

		break;
	}
	updateScrollIndicator();
}

void ScrollBar::render(sf::RenderWindow & t_window)
{
	for (int i = 0; i < 2; i++)
	{
		t_window.draw(m_endpoints[i]);
	}
	t_window.draw(m_centreBar);
	t_window.draw(m_scrollIndicator);
	m_label.render(t_window);
}

void ScrollBar::reset()
{
	m_isHighlighted = false;
	m_prevIsHighlighted = false;
	m_highlightOnAnimation = false;
	m_highlightOffAnimation = false;
	m_label.m_text.setOutlineThickness(0);
}

void ScrollBar::updateScrollIndicator()
{
	switch (m_orientation)
	{
	case BarOrientation::Horizontal:
	{
		if (m_barLength * (m_currnetValue / 100) > m_barLength)
		{
			m_scrollIndicator.setPosition(m_endpoints[0].getPosition().x + m_barLength, m_endpoints[0].getPosition().y );

		}
		else if (m_barLength * (m_currnetValue / 100) < 0)
		{
			m_scrollIndicator.setPosition(m_endpoints[0].getPosition().x, m_endpoints[0].getPosition().y);
		}
		else
		{
			m_scrollIndicator.setPosition(m_endpoints[0].getPosition().x + (m_barLength * (m_currnetValue / 100)), m_endpoints[0].getPosition().y);
		}
		break;
	}
	case BarOrientation::Vertical:
	{
		if (m_barLength * (m_currnetValue / 100) > m_barLength)
		{
			m_scrollIndicator.setPosition(m_endpoints[0].getPosition().x, m_endpoints[0].getPosition().y + m_barLength);

		}
		else if (m_barLength * (m_currnetValue / 100) < 0)
		{
			m_scrollIndicator.setPosition(m_endpoints[0].getPosition().x, m_endpoints[0].getPosition().y);
		}
		else
		{
			m_scrollIndicator.setPosition(m_endpoints[0].getPosition().x, m_endpoints[0].getPosition().y + (m_barLength * (m_currnetValue / 100)));
		}
		break;
	}
	default:
		break;
	}
	
}

void ScrollBar::isHighlighted(const bool t_boolean)
{
	m_isHighlighted = t_boolean;
}

bool ScrollBar::isHighlighted()
{
	return m_isHighlighted;
}
