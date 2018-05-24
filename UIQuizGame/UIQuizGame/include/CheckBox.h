#ifndef CHECK_BOX
#define CHECK_BOX

#include "UIElements.h"
#include "Button.h"



class CheckBox : UIElements
{
public:
	Button m_button;

	void update(const sf::Time &t_dTime, const Xbox360Controller &t_controller, const int &t_animationScalar);
	/// <summary>
	/// draws all relevant objects to the screen
	/// </summary>
	/// <param name="t_window">render window in the game class</param>

	void render(sf::RenderWindow &t_window);

	void reset();
	/// <summary>
	/// returns wether the button has been fully pressed
	/// </summary>
	/// <returns></returns>

	bool isPressed();

	//getter/setter functions
	void size(sf::Vector2f &t_size);
	sf::Vector2f size();
	void position(sf::Vector2f &t_pos);
	sf::Vector2f position();
	void color(const sf::Color &t_color);
	sf::Color color();
	void isHighlighted(const bool t_boolean);
	bool isHighlighted();
	sf::RectangleShape body();
	/// <summary>
	/// keeps track if last frame the button was highlighted or not
	/// </summary>
	bool m_prevIsHighlighted = false;

	/// <summary>
	/// keeps track of wether an animation for the highlight appearing should be happening
	/// </summary>
	bool m_highlightOnAnimation = false;
	/// <summary>
	/// Used to initialise a button
	/// defaults specified as below
	/// </summary>
	/// <param name="t_pos">the position of the button(centre point of the body)</param>
	/// <param name="t_size">the size of the button body</param>
	/// <param name="t_isHighlighed">wether the button is initialised as highlighted</param>
	/// <param name="t_texture">the texture of the button(the image)</param>
	/// <param name="t_label">the words printed on the button(another ui element found in Label.h)</param>
	/// <param name="t_color">the colour of the button</param>
	void init(sf::Vector2f &t_pos = sf::Vector2f(0, 0), sf::Vector2f &t_size = sf::Vector2f(1, 1), const bool &t_isHighlighed = false, sf::Texture &t_texture = sf::Texture(), Label &t_label = Label(), const sf::Color &t_color = sf::Color::White);

	void init(Button &button);
private:

};

#endif