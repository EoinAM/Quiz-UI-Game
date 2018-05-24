#ifndef RADIO_BUTTONS
#define RADIO_BUTTONS

#include <memory>

#include "Button.h"

class RadioButton : Button
{
public:
	RadioButton();
	void createButtons(int t_numberOfButtons = 2);
	void initButtons(int buttonNum = 0, Button &button = Button());
	void update(sf::Time &t_dTime, const Xbox360Controller &t_controller, const int &t_animationScalar);
	void render(sf::RenderWindow &t_window);
	void resetRemember();
	void fullReset();
	bool isPressed(int t_buttonNum);

	void position(int t_buttonNum, sf::Vector2f &t_pos);
	sf::Vector2f position(const int t_buttonNum);
	void size(int t_buttonNum, sf::Vector2f &t_size);
	sf::Vector2f size(int t_buttonNum);
	void color(int t_buttonNum, const sf::Color &t_color);
	sf::Color color(int t_buttonNum);
	void isHighlighted(int t_buttonNum, const bool t_boolean);
	bool isHighlighted(int t_buttonNum);

	int MAX_BUTTONS = 0;

	std::vector<Button*> m_buttons;
};

#endif//!RADIO_BUTTONS