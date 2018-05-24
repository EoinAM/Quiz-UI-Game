/// <summary>
/// @Author: Eoin Abbey-Maher
/// @Date: 9/10/17
/// 
/// Controller Header
/// </summary>

#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include <SFML\Graphics.hpp>
#include <iostream>

/// <summary>
/// Constant value for total amount of buttons
/// </summary>
int const BUTTONS{ 18 };

/// <summary>
/// Struct of booleans for if the button is being pressed
/// </summary>
struct GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbStickClick;
	bool RightThumbStickClick;
	bool DpadUp;
	bool DpadDown;
	bool DpadLeft;
	bool DpadRight;
	bool Start;
	bool Back;
	float RTrigger;
	float LTrigger;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;
};

/// <summary>
/// Xbox 360 Controller class
/// </summary>
class Xbox360Controller
{
public:
	/// <summary>
	/// Xbox controller Default constructor
	/// </summary>
	Xbox360Controller();

	/// /// <summary>
	/// Xbox controller Deconstructor
	/// </summary>
	~Xbox360Controller();

	/// <summary>
	/// The Controllers Index Number
	/// </summary>
	int sf_Joystick_Index;

	/// <summary>
	/// Current button being pressed
	/// </summary>
	GamePadState m_currentState;

	/// <summary>
	/// Last Button to be pressed
	/// </summary>
	GamePadState m_previousState;

	/// <summary>
	/// Bool to check if controller is connected
	/// </summary>
	/// <returns></returns>
	bool isConnected();

	/// <summary>
	/// Function to check if controller is being connected
	/// </summary>
	/// <returns></returns>
	bool connect();

	/// <summary>
	/// Boolean to Quit game
	/// </summary>
	bool Quit;

	/// <summary>
	/// Controller Update Function
	/// </summary>
	void Xbox360Controller::update();

	/// <summary>
	/// Functoin to check what buttons are being pressed
	/// </summary>
	void buttonCheck();


private:
	/// <summary>
	/// Thresholds for the Dpad and the Thumbstick
	/// </summary>
	const int dpadTreshold{ 50 };
	const int thumbstickThreshold{ 15 };

};

#endif 

