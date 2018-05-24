#include "..\include\Help.h"

HelpMenu::HelpMenu(sf::Font & t_font, sf::Texture & t_buttonTexture)
{
	m_returnButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 300), sf::Vector2f(400,50), true, t_buttonTexture, Label("Return", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 300), t_font));
}

void HelpMenu::update(sf::Time t_dTime, Xbox360Controller & t_controller, CurrentScreen & t_currentScreen, const int &t_animationScalar)
{
	if (m_returnButton.isPressed() || (!t_controller.m_currentState.Back && t_controller.m_previousState.Back))
	{
		m_returnButton.reset();
		m_returnButton.isHighlighted(true);
		t_currentScreen = CurrentScreen::MAINMENU;
		return;
	}
	m_returnButton.update(t_dTime, t_controller, t_animationScalar);
}

void HelpMenu::render(sf::RenderWindow & t_window)
{
	//needs to be a controller image with all of the controls here
	m_returnButton.render(t_window);
}
