#ifndef LABEL
#define LABEL

#include "SFML\Graphics.hpp"
#include <memory>
#include <iostream>

class Label
{
public:
	Label(std::string t_text = "", sf::Vector2f &t_pos = sf::Vector2f(0,0),sf::Font &t_font = sf::Font(), const sf::Color t_color = sf::Color::White, int t_characterSize = 20);
	void init(std::string t_text = std::string(), sf::Vector2f &t_pos = sf::Vector2f(0,0), sf::Font &t_font = sf::Font(), const sf::Color t_color = sf::Color::White, int t_characterSize = 20);

	void position(const sf::Vector2f &t_position);
	void string(const std::string &t_string);
	void render(sf::RenderWindow &t_window);
	sf::Text m_text;
private:
	

};

#endif//!LABEL