/// <summary>
/// @Author : Eoin Abbey-Maher
/// 
/// @Date : 9/10/17
/// </summary>

#include "Xbox360Controller.h"

/// <summary>
/// Xbox Controller Default Constructor
/// </summary>
Xbox360Controller::Xbox360Controller()
{
	connect();
}

/// <summary>
/// Xbox Controller default deconstructor
/// </summary>
Xbox360Controller::~Xbox360Controller()
{
}

/// <summary>
/// Function to check if controller is connected 
/// and assign the controller nimber to the index
/// </summary>
/// <returns>Boolean if controller is connected</returns>
bool Xbox360Controller::isConnected()
{
	for (int i = 0; i < 8; i++)
	{
		if (sf::Joystick::isConnected(i))
		{
			sf_Joystick_Index = i;
			return true;

		}
		else
		{
			return false;
		}
	}

}

bool Xbox360Controller::connect()
{
	if (isConnected())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Controller update
/// </summary>
void Xbox360Controller::update()
{

	/// /// <summary>
	/// Set the previous Button press to be the current button press
	/// </summary>
	m_previousState = m_currentState;

	/// <summary>
	/// Function to see what buttons are being pressed
	/// </summary>
	buttonCheck();
}

/// <summary>
/// Function to check what controller buttons are being pressed
/// </summary>
void Xbox360Controller::buttonCheck()
{
	/// <summary>
	/// If the Joystick button is being pressed then set the text to be shown,
	/// set the current state to be true
	/// 
	/// if the previous state isnt false then the last button pressed is set to the name
	/// </summary>
	if (isConnected())
	{
		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 1)) //B
		{
			m_currentState.B = true;
		}
		else
		{
			m_currentState.B = false;
		}

		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 0)) //A
		{
			m_currentState.A = true;
		}
		else
		{
			m_currentState.A = false;
		}

		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 2)) //X
		{
			m_currentState.X = true;
		}
		else
		{
			m_currentState.X = false;
		}

		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 3)) //Y
		{
			m_currentState.Y = true;
		}
		else
		{
			m_currentState.Y = false;
		}

		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 5)) //RB
		{
			m_currentState.RB = true;
		}
		else
		{
			m_currentState.RB = false;
		}

		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 4)) //LB
		{
			m_currentState.LB = true;
		}
		else
		{
			m_currentState.LB = false;
		}

		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 6)) //Back;
		{
			m_currentState.Back = true;
		}
		else
		{
			m_currentState.Back = false;
		}

		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 7)) //Start
		{
			m_currentState.Start = true;
		}
		else
		{
			m_currentState.Start = false;
		}



		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 8)) //left thumb click
		{
			m_currentState.LeftThumbStickClick = true;
		}
		else
		{
			m_currentState.LeftThumbStickClick = false;
		}

		if (sf::Joystick::isButtonPressed(sf_Joystick_Index, 9)) //right thumb click
		{
			m_currentState.RightThumbStickClick = true;
		}
		else
		{
			m_currentState.RightThumbStickClick = false;
		}

		/// <summary>
		/// If the PovX Axis and PovY Axis position changes then the Dpad is being pressed.
		/// Use of a dpad Threshold is to ensure that there is not a misclick on the Dpad.
		/// </summary>
		if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::PovX) > dpadTreshold) //dpad Right
		{
			m_currentState.DpadRight = true;
		}
		else
		{
			m_currentState.DpadRight = false;
		}

		if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::PovX) < (dpadTreshold * -1)) //dpad Left
		{
			m_currentState.DpadLeft = true;
		}
		else
		{
			m_currentState.DpadLeft = false;
		}

		if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::PovY) > (dpadTreshold)) //dpad Up
		{
			m_currentState.DpadUp = true;
		}
		else
		{
			m_currentState.DpadUp = false;
		}

		if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::PovY) < (dpadTreshold * -1)) // dpad Down
		{
			m_currentState.DpadDown = true;
		}
		else
		{
			m_currentState.DpadDown = false;
		}

		/// <summary>
		/// the triggers are dealt with on one axis, when it enters the negative the Right trigger is being pressed. When 
		/// it enters the Positive of the Axis the Left trigger is being pressed
		/// </summary>
		if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::Z) > 5) //Left Trigger
		{
			m_currentState.LTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
		}
		else
		{
			m_currentState.LTrigger = false;
		}

		if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::Z) < -5) //Right Trigger
		{
			m_currentState.RTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
		}
		else
		{
			m_currentState.RTrigger = false;
		}


		/// <summary>
		/// When thumbsticks are moved the Coords are set to the Axis Position. Threshold is used because the Analogs dont settle perfectkly on 0
		/// </summary>
		if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::U) > thumbstickThreshold || sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::U) < (thumbstickThreshold * -1)
			|| sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::R) > thumbstickThreshold || sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::R) < (thumbstickThreshold * -1)) //Right Thumb Stick move
		{
			m_currentState.RightThumbStick.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
			m_currentState.RightThumbStick.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R);
		}
		else
		{
			m_currentState.RightThumbStick = (sf::Vector2f(0, 0));
		}

		if (sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::X) > 15 || sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::X) < -15
			|| sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::Y) > 15 || sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::Y) < -15) //Left Thumb stick move
		{
			m_currentState.LeftThumbStick.x = sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::X);
			m_currentState.LeftThumbStick.y = sf::Joystick::getAxisPosition(sf_Joystick_Index, sf::Joystick::Axis::Y);
		}
		else
		{
			m_currentState.LeftThumbStick = (sf::Vector2f(0, 0));
		}


	}
}

