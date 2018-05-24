#ifndef OPTIONS
#define OPTIONS

#include <iostream>
#include "SFML\Graphics.hpp"
#include <SFML\Audio.hpp>
#include "Label.h"
#include "Button.h"
#include "ScrollBar.h"
#include "RadioButton.h"
#include "CheckBox.h"
#include "Xbox360Controller.h"
#include "Global.h"

class Options
{
public:
	Options(sf::Font &t_font, sf::Texture &t_texture);

	void update(sf::Time &t_dTime, Xbox360Controller &t_controller, float &t_animationScalar, CurrentScreen &t_currentScreen, sf::RenderWindow &t_window);

	void render(sf::RenderWindow &t_window);
private:
	ScrollBar m_musicScroll;
	ScrollBar m_sfxScroll;
	CheckBox m_musicMute;
	CheckBox m_sfxMute;
	ScrollBar m_animationScroll;

	RadioButton m_muteAll;
	Button m_returnButton;

	Label m_optionLabel;

	sf::SoundBuffer m_backgroundBuffer;
	sf::Sound m_backgroundSound;

};

#endif