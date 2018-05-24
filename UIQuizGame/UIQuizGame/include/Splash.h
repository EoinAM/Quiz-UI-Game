#ifndef SPLASHSCREEN
#define SPLASHSCREEN

#include "Global.h"
#include "Xbox360Controller.h"
#include "Animation.h"
#include "AnimationEnums.h"
#include <SFML\Graphics.hpp>

class SplashScreen
{
public:
	SplashScreen(sf::RenderWindow & t_window, Xbox360Controller & t_controller, sf::Font & t_font);
	~SplashScreen();


	void update();
	void render();

	sf::RectangleShape m_logoShape;
	sf::IntRect m_logoRect{ 0,0,622,460};
	sf::Texture m_logoTexture;
	Animation m_logoAnimation;

	bool m_finished{ false };

private:
	Xbox360Controller & m_controller;
	sf::Font & m_font;

	AnimationState m_currentState{ AnimationState::APPEAR };

	sf::Text m_pressText;
	sf::Text m_AText;
	sf::Text m_keyText;

	bool m_hit{ false };

	int m_opacity{ 245 };
	int m_opacityOffset{ 2 };

	
	
	sf::RenderWindow & m_window;
};


#endif // !SPLASHSCREEN
