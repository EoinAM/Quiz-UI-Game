#ifndef HELP_MENU
#define HELP_MENU

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Xbox360Controller.h"
#include "Button.h"
#include "Global.h"

class HelpMenu
{
public:
	HelpMenu(sf::Font &t_font, sf::Texture &t_buttonTexture);
	void update(sf::Time t_dTime, Xbox360Controller &t_controller, CurrentScreen &t_currentScreen, const int &t_animationScalar);
	void render(sf::RenderWindow &t_window);
private:
	Button m_returnButton;
};

#endif