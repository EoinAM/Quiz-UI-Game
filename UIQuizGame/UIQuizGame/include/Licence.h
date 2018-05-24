#ifndef LICENCESCREEN
#define LICENCESCREEN


#include "Global.h"
#include "Xbox360Controller.h"
#include "Animation.h"
#include "AnimationEnums.h"
#include <SFML\Graphics.hpp>

const int MAXCHARACTERS{ 10 };

class LicenseScreen
{
public:
	LicenseScreen(sf::RenderWindow & t_window, sf::Font & t_font);
	~LicenseScreen();


	void update();
	void render();

	bool m_finished{ false };

private:
	void moveArray();
	void setupArrays();

	bool m_madeDrawn{ true };

	sf::Font & m_font;

	AnimationState m_currentState{ AnimationState::APPEAR };

	float m_scale{ .5f };
	float m_scaleoffset{ 0.05f };

	int m_rotation;
	int m_waitTimer{ 0 };
	int m_exitTimer{ 0 };
	int m_textLenght{ 0 };

	float m_logoOpacity{ 0.0f }; //The Starting opacity of the logo

	sf::Vector2f m_startTextPosition{ 500,ScreenSize::s_height};
	sf::Vector2f m_finalTextPosition{ 500, 700};

	sf::Text m_sfmlText;

	sf::Texture m_sfmlTexture;
	sf::Sprite m_sfmlLogo;

	sf::String m_madeUsingString[MAXCHARACTERS] = { "M", "A", "D", "E", " ", "U", "S", "I", "N", "G" }; // Array of letters for the word
	sf::Text m_madeUsingText[MAXCHARACTERS]; //array of text for the letters

	sf::RenderWindow & m_window;
};


#endif // !LICENCESCREEN

