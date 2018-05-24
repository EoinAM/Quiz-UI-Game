#ifndef UI_ELEMENTS
#define UI_ELEMENTS

#include "Xbox360Controller.h"
#include "Global.h"
#include "Label.h"

class UIElements
{
public:
	bool m_isHighlighted{ false };


	virtual void update(const sf::Time &t_dTime, const Xbox360Controller &t_controller, const int &t_animationScalar) {};
	virtual void size(sf::Vector2f &t_size) {};
	virtual sf::Vector2f size() { return sf::Vector2f(0,0); };
	virtual void position(sf::Vector2f &t_pos) {};
	virtual sf::Vector2f position() { return sf::Vector2f(0, 0); };
	virtual void color(const sf::Color &t_color) {};
	virtual sf::Color color() { return sf::Color(0, 0, 0, 0); };
	virtual void reset() {};
	virtual void isHighlighted(const bool t_boolean) {};
	virtual bool isHighlighted() { return m_isHighlighted; };
};

#endif//!UI_ELEMENTS