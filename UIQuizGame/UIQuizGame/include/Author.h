#ifndef AUTHORSCREEN
#define AUTHORSCREEN

#include "Global.h"
#include "Xbox360Controller.h"
#include "Animation.h"
#include "AnimationEnums.h"
#include <SFML\Graphics.hpp>

class AuthorScreen
{
public:
	AuthorScreen(sf::RenderWindow & t_window, sf::Font & t_font);
	~AuthorScreen();


	void update();
	void render();


	bool m_finished{ false };
	bool m_madeMove{ false };

private:
	void moveArray();
	
	sf::Font & m_font;

	AnimationState m_currentState{ AnimationState::APPEAR };

	sf::Text m_madeByText;
	sf::Text m_nameText;

	sf::Vector2f m_madePosition{ -100,250 }; //Position that the first string starts on
	sf::Vector2f m_finalmadePosition{ ScreenSize::s_width * .3,250 }; //Position to move the first string to 
	sf::Vector2f m_namePosition{ ScreenSize::s_width *.18,160 }; //Position the second string starts on
	sf::Vector2f m_finalnamePosition{ 160, 318 }; //position to move the second string to

	int m_exitTimer{ 0 };
	int m_textLenght{ 0 };

	float m_exitSpeed{ 1.0f }; // translation increment for exit animation
	float m_rotation{ 1.0f }; // step back to horiziontal
	float m_slideAmount{ 4.0f }; // amount of translation when leaving screen

	const char * First_MESSAGE{ "MADE BY" }; // message for appearance and main message
	const char * SECOND_MESSAGE{ "Eoin & JOHN" }; // message to display when exiting
	
	sf::RectangleShape m_coverSquare;

	sf::RenderWindow & m_window;
};


#endif // !AUTHORSCREEN
