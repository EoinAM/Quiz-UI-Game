#include "..\include\Options.h"

Options::Options(sf::Font & t_font, sf::Texture & t_texture)
{
	m_optionLabel.init("Option Menu", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) - 500), t_font, sf::Color::Blue, 40);
	m_musicScroll.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 400, (ScreenSize::s_height / 2.0f) - 300), Label("Music Volume", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) - 300), t_font), 400, true, 50, BarOrientation::Horizontal);

	m_sfxScroll.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 400, (ScreenSize::s_height / 2.0f) - 200), Label("SFX Volume", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) - 200), t_font), 400, false, 50, BarOrientation::Horizontal);
	m_musicMute.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) - 100), sf::Vector2f(20, 20), false, sf::Texture(), Label("Music Mute", sf::Vector2f(ScreenSize::s_width / 2.0f - 300, (ScreenSize::s_height / 2.0f) - 100), t_font));
	m_sfxMute.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f)), sf::Vector2f(20, 20), false, sf::Texture(), Label("SFX Mute", sf::Vector2f(ScreenSize::s_width / 2.0f - 300, (ScreenSize::s_height / 2.0f)), t_font));
	m_animationScroll.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 400, (ScreenSize::s_height / 2.0f + 100)), Label("Animation Scalar", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 100), t_font), 400, false, 0, BarOrientation::Horizontal);

	m_muteAll.createButtons();
	Button tempButton;
	tempButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 200), sf::Vector2f(20, 20), false, sf::Texture(), Label("Mute All", sf::Vector2f(ScreenSize::s_width / 2.0f - 300, (ScreenSize::s_height / 2.0f) + 200), t_font));
	m_muteAll.initButtons(0, Button(tempButton));
	tempButton.init(sf::Vector2f(-100, 100), sf::Vector2f(0, 0), false, sf::Texture());
	m_returnButton.init(sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 300), sf::Vector2f(400, 50), false, t_texture, Label("Return", sf::Vector2f(ScreenSize::s_width / 2.0f - 200, (ScreenSize::s_height / 2.0f) + 300), t_font));


	m_backgroundBuffer.loadFromFile("Assets\\OldVienna.wav");
	m_backgroundSound.setBuffer(m_backgroundBuffer);
	m_backgroundSound.setLoop(true);
	m_backgroundSound.setVolume(10);
	m_backgroundSound.play();
}

void Options::update(sf::Time & t_dTime, Xbox360Controller & t_controller, float & t_animationScalar, CurrentScreen & t_currentScreen, sf::RenderWindow & t_window)
{
	m_musicScroll.update(t_dTime, t_controller, t_animationScalar);
	m_sfxScroll.update(t_dTime, t_controller, t_animationScalar);
	m_animationScroll.update(t_dTime, t_controller, t_animationScalar);
	m_musicMute.update(t_dTime, t_controller, t_animationScalar);
	m_sfxMute.update(t_dTime, t_controller, t_animationScalar);
	m_returnButton.update(t_dTime, t_controller, t_animationScalar);
	m_muteAll.update(t_dTime, t_controller, t_animationScalar);


	if (m_musicScroll.isHighlighted())
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_musicScroll.isHighlighted(false);
			m_sfxScroll.isHighlighted(true);
		}
	}
	else if (m_sfxScroll.isHighlighted())
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_sfxScroll.isHighlighted(false);
			m_musicMute.isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_sfxScroll.isHighlighted(false);
			m_musicScroll.isHighlighted(true);
		}
	}
	else if (m_musicMute.isHighlighted())
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_musicMute.isHighlighted(false);
			m_sfxMute.isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_musicMute.isHighlighted(false);
			m_sfxScroll.isHighlighted(true);
		}
	}
	else if (m_sfxMute.isHighlighted())
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_sfxMute.isHighlighted(false);
			m_animationScroll.isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_sfxMute.isHighlighted(false);
			m_musicMute.isHighlighted(true);
		}
	}
	else if (m_animationScroll.isHighlighted())
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_animationScroll.isHighlighted(false);
			m_muteAll.isHighlighted(0,true);
		}
		else if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_animationScroll.isHighlighted(false);
			m_sfxMute.isHighlighted(true);
		}
	}
	else if (m_muteAll.isHighlighted(0))
	{
		if ((t_controller.m_currentState.DpadDown && !t_controller.m_previousState.DpadDown) || (t_controller.m_currentState.LeftThumbStick.y > 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_muteAll.isHighlighted(0, false);
			m_returnButton.isHighlighted(true);
		}
		else if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_muteAll.isHighlighted(0, false);
			m_animationScroll.isHighlighted(true);
		}
	}
	else if (m_returnButton.isHighlighted())
	{
		if ((t_controller.m_currentState.DpadUp && !t_controller.m_previousState.DpadUp) || (t_controller.m_currentState.LeftThumbStick.y < 0 && t_controller.m_previousState.LeftThumbStick.y == 0))
		{
			m_returnButton.isHighlighted(false);
			m_muteAll.isHighlighted(0,true);
		}
	}

	if (m_musicMute.isPressed())
	{
		m_musicScroll.m_currnetValue = 0;
	}
	if (m_sfxMute.isPressed())
	{
		m_sfxScroll.m_currnetValue = 0;
	}
	
	if (m_sfxMute.isPressed() && m_musicMute.isPressed())
	{
		m_muteAll.m_buttons.at(0)->m_isPressed = true;
	}
	if (m_muteAll.isPressed(0))
	{
		m_musicMute.m_button.m_isPressed = true;
		m_sfxMute.m_button.m_isPressed = true;
		m_sfxScroll.m_currnetValue = 0;
		m_musicScroll.m_currnetValue = 0;
	}
	
	if (m_returnButton.isPressed())
	{
		t_currentScreen = CurrentScreen::MAINMENU;
		m_musicScroll.reset();
		m_musicScroll.isHighlighted(true);
		m_sfxScroll.reset();
		m_musicMute.reset();
		m_sfxMute.reset();
		m_animationScroll.reset();

		m_muteAll.resetRemember();
		m_returnButton.reset();
	}
	if (10 * (m_animationScroll.m_currnetValue / 100) <= 1)
	{
		t_animationScalar = 1;
	}
	else
	{
		t_animationScalar = 10 * (m_animationScroll.m_currnetValue / 100);
	}
	if (m_musicMute.isPressed() == true)
	{
		m_backgroundSound.setVolume(0);
	}
	else
	{
		m_backgroundSound.setVolume(10);
	}
}

void Options::render(sf::RenderWindow & t_window)
{
	m_optionLabel.render(t_window);
	m_musicScroll.render(t_window);
	m_sfxScroll.render(t_window);
	m_sfxMute.render(t_window);
	m_musicMute.render(t_window);
	m_muteAll.render(t_window);
	m_returnButton.render(t_window);
	m_animationScroll.render(t_window);
}
