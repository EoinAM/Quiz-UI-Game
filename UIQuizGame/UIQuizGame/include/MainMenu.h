#ifndef MAIN_MENU
#define MAIN_MENU

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Label.h"
#include "Button.h"
#include "Xbox360Controller.h"
#include "Global.h"
enum class MainStates
{
	MainMenu,
	Confirmation
};
class MainMenu
{
public:
	MainMenu(sf::Font &t_font, sf::Texture &t_texture);

	void update(const sf::Time &t_dTime, const Xbox360Controller &t_controller, const int &t_animationScalar, CurrentScreen &t_currentScreen, sf::RenderWindow &t_window);

	void render(sf::RenderWindow &t_window);
private:
	Label m_gameTitle;
	Label m_confirmTitle;
	static const int M_MAX_BUTTONS{5};
	Button m_mainMenuButtons[M_MAX_BUTTONS];
	Button m_confirmButtons[2];

	MainStates m_currentState{MainStates::MainMenu};
	sf::RectangleShape m_confirmBoard;
};

#endif