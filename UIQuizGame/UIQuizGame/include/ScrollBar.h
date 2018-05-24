#ifndef SCROLLBAR
#define SCROLLBAR

#include "SFML\Graphics.hpp"
#include "Xbox360Controller.h"
#include "UIElements.h"
#include "Label.h"


enum class BarOrientation
{
	Horizontal,
	Vertical
};


class ScrollBar : UIElements
{
public:
	ScrollBar() {};

	void init(sf::Vector2f &t_position = sf::Vector2f(), Label &t_label = Label(), int const  t_barLength = 100, bool const t_highlighted = false,  float t_initialValue = 50.f, BarOrientation t_orientation = BarOrientation::Horizontal);

	void update(sf::Time t_dTime, Xbox360Controller &t_controller, const int &t_animationScalar);
	void render(sf::RenderWindow &t_window);

	void reset();

	/*void size(sf::Vector2f &t_size);
	sf::Vector2f size();
	void position(sf::Vector2f &t_pos);
	sf::Vector2f position();
	void color(const sf::Color &t_color);
	sf::Color color();*/
	void isHighlighted(const bool t_boolean);
	bool isHighlighted();
	float m_currnetValue{ 50 };
private:
	void updateScrollIndicator();
	sf::RectangleShape m_centreBar;
	sf::RectangleShape m_scrollIndicator;
	sf::CircleShape m_endpoints[2];

	Label m_label;

	float m_length;

	BarOrientation m_orientation{ BarOrientation::Horizontal };

	bool m_prevIsHighlighted{ false }, m_highlightOnAnimation{ false }, m_highlightOffAnimation{false};


	float m_barLength;

	
};
#endif//!SCROLL_BAR