#include "KeyBoardInput.h"

KeyBoardInput::KeyBoardInput(Xbox360Controller & t_controller, sf::Font & t_font, sf::Texture & t_buttonTexture):
	m_controller(t_controller), m_font(t_font), m_Buttontexture(t_buttonTexture)
{
	labelInit();
	buttonInit();

	highScores.open("highscores.txt");
	while (!highScores.eof())
	{
		std::string str;
		std::getline(highScores, str);

		m_oldScores.push_back(str);
	}
	highScores.close();
}


KeyBoardInput::~KeyBoardInput()
{
}

void KeyBoardInput::update(const sf::Time &t_dtime, const int &t_AnimationScalar, int t_scoreNum, CurrentScreen & t_currentScreen)
{
	if (m_isShown)
	{
		for (int i = 0; i < NOOFBUTTONS; i++)
		{
			m_buttons[i].update(t_dtime, m_controller, t_AnimationScalar);

			if (i == m_activeButton)
			{
				m_buttons[i].isHighlighted(true);
			}
		}

		handleInput();
		takeName(t_scoreNum, t_currentScreen);

		m_textBlock.m_text.setString(m_fullString);
	}
}

void KeyBoardInput::handleInput()
{

	if (m_controller.m_currentState.DpadDown && !m_controller.m_previousState.DpadDown)
	{
		if (m_activeButton >= 0 && m_activeButton < 10)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			if (m_activeButton == 9)
			{
				m_activeButton += 9;
			}
			else
			{
				m_activeButton += 10;
			}
		}
		else if (m_activeButton >= 10 && m_activeButton <= 18)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			if (m_activeButton >= 16)
			{
				m_activeButton += 7;
			}
			else
			{
				m_activeButton += 9;
			}
		}
		else if (m_activeButton >= 19 && m_activeButton < NOOFBUTTONS)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			m_activeButton = NOOFBUTTONS -1;
		}
	}

	if (m_controller.m_currentState.DpadUp && !m_controller.m_previousState.DpadUp)
	{
		if (m_activeButton >= 0 && m_activeButton < 10)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			m_activeButton = NOOFBUTTONS - 1;

		}
		else if (m_activeButton >= 10 && m_activeButton <= 18)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			if (m_activeButton >= 18)
			{
				m_activeButton -= 9;
			}
			else
			{
				m_activeButton -= 10;
			}
		}
		else if (m_activeButton >= 19 && m_activeButton < NOOFBUTTONS -1)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			m_activeButton -= 8;
		}
		else if (m_activeButton == NOOFBUTTONS-1)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			m_activeButton--;
		}
	}

	if (m_controller.m_currentState.DpadLeft && !m_controller.m_previousState.DpadLeft)
	{
		if (m_activeButton >= 0 && m_activeButton < NOOFBUTTONS)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			m_activeButton--;

			if (m_activeButton == -1)
			{
				m_activeButton = NOOFBUTTONS - 1;
			}

		}
		
	}
	
	if (m_controller.m_currentState.DpadRight && !m_controller.m_previousState.DpadRight)
	{
		if (m_activeButton >= 0 && m_activeButton <= NOOFBUTTONS)
		{
			m_buttons[m_activeButton].isHighlighted(false);
			
			m_activeButton++;

			if (m_activeButton == NOOFBUTTONS)
			{
				m_activeButton = 0;
			}

		}

	}
}

void KeyBoardInput::writeToFile(int t_scoreNum)
{
	std::string str = m_textBlock.m_text.getString();
	highScores.open("highscores.txt");
	for (int i = 0; i < m_oldScores.size(); i++)
	{
		highScores <<m_oldScores[i] + "\n";
	}
	for (int i = 0; i < m_scores.size(); i++)
	{
		highScores << m_scores[i] + "\t" + std::to_string(t_scoreNum) + "\n";
	}
	highScores.close();
}

void KeyBoardInput::labelInit()
{
	m_textBlock.init(m_fullString,sf::Vector2f(ScreenSize::s_width * .25, ScreenSize::s_height * .3), m_font, sf::Color::White, 50);
	
	for (int i = 0; i < NOOFBUTTONS; i++)
	{
		Label label;
		if (i < 10)
		{
			label.init("", sf::Vector2f((80 * i) + ScreenSize::s_width * .25, ScreenSize::s_height * .4), m_font, sf::Color::Black, 40);
		}
		if (i > 9 && i < 19)
		{
			label.init("", sf::Vector2f((80 * (i - 10)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .48), m_font, sf::Color::Black, 40);
		}
		if (i >= 19 && i < 26)
		{
			label.init("", sf::Vector2f((80 * (i - 18)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .56), m_font, sf::Color::Black, 40);
		}
		if (i == 26)
		{
			label.init("", sf::Vector2f((80 * (i - 25)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .64), m_font, sf::Color::Black, 30);
		}
		if (i == 27)
		{
			label.init("", sf::Vector2f((80 * (i - 23)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .64), m_font, sf::Color::Black, 40);
		}
		if (i == 28)
		{
			label.init("", sf::Vector2f((80 * (i - 21)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .64), m_font, sf::Color::Black, 30);
		}
		m_labels.push_back(label);
	}

	m_labels[0].string("Q");
	m_labels[1].string("W");
	m_labels[2].string("E");
	m_labels[3].string("R");
	m_labels[4].string("T");
	m_labels[5].string("Y");
	m_labels[6].string("U");
	m_labels[7].string("I");
	m_labels[8].string("O");
	m_labels[9].string("P");
	m_labels[10].string("A");
	m_labels[11].string("S");
	m_labels[12].string("D");
	m_labels[13].string("F");
	m_labels[14].m_text.setString("G");
	m_labels[15].m_text.setString("H");
	m_labels[16].m_text.setString("J");
	m_labels[17].m_text.setString("K");
	m_labels[18].m_text.setString("L");
	m_labels[19].m_text.setString("Z");
	m_labels[20].m_text.setString("X");
	m_labels[21].m_text.setString("C");
	m_labels[22].m_text.setString("V");
	m_labels[23].m_text.setString("B");
	m_labels[24].m_text.setString("N");
	m_labels[25].m_text.setString("M");
	m_labels[26].m_text.setString("CLR");
	m_labels[27].m_text.setString("");
	m_labels[28].m_text.setString("OK");
	for (int i = 0; i < NOOFBUTTONS; i++)
	{
		m_labels[i].m_text.setOrigin(m_labels[i].m_text.getLocalBounds().width / 2.0f, m_labels[i].m_text.getLocalBounds().height / 2.0f);
	}
}

void KeyBoardInput::takeName(int t_scoreNum, CurrentScreen & t_currentScreen)
{
	if (m_controller.m_currentState.A && !m_controller.m_previousState.A)
	{
		if (m_activeButton == 26)
		{
			m_fullString = "";
		}
		if (m_activeButton >= 0 && m_activeButton < NOOFBUTTONS-1 && m_activeButton != 26)
		{
			m_stringAddition = m_labels[m_activeButton].m_text.getString();
			m_fullString = m_fullString + m_stringAddition;
		}
		else if (m_activeButton == NOOFBUTTONS -1)
		{
			std::string str = m_fullString;
			m_scores.push_back(str);
			writeToFile(t_scoreNum);
			t_currentScreen = CurrentScreen::MAINMENU;
		}
	}
	
}

void KeyBoardInput::buttonInit()
{

	for (int i = 0; i < NOOFBUTTONS; i++)
	{
		Button button;
		if (i < 10)
		{
			button.init(sf::Vector2f((80 * i) + ScreenSize::s_width * .25, ScreenSize::s_height * .4), sf::Vector2f(75, 75), false, m_Buttontexture,m_labels[i]);
		}
		if (i > 9 && i < 19)
		{
			button.init(sf::Vector2f((80 * (i - 10)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .48), sf::Vector2f(75, 75), false, m_Buttontexture, m_labels[i]);
		}
		if (i >= 19 && i < 26)
		{
			button.init(sf::Vector2f((80 * (i - 18)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .56), sf::Vector2f(75, 75), false, m_Buttontexture, m_labels[i]);
		}
		if (i == 26)
		{
			button.init(sf::Vector2f((80 * (i -	25)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .64), sf::Vector2f(90, 75), false, m_Buttontexture, m_labels[i]);
		}
		if (i == 27)
		{
			button.init(sf::Vector2f((80 * (i -	23)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .64), sf::Vector2f(375, 75), false, m_Buttontexture, m_labels[i]);
		}
		if (i == 28)
		{
			button.init(sf::Vector2f((80 * (i - 21)) + ScreenSize::s_width * .25 + 40, ScreenSize::s_height * .64), sf::Vector2f(90, 75), false, m_Buttontexture, m_labels[i]);
		}
		m_buttons.push_back(button);
	}
}


void KeyBoardInput::render(sf::RenderWindow & t_window)
{
	if(m_isShown)
	{
		t_window.draw(m_body);
		for (int i = 0; i < NOOFBUTTONS; i++)
		{
			m_buttons[i].render(t_window);
			m_labels[i].render(t_window);
		}
		m_textBlock.render(t_window);
	}
}
