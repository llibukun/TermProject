#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Button
{
//Fields
	private:
		sf::RectangleShape button;
		sf::Text nameText;
		//Produce &object;

//Declaration of Button Functions
	public:
		Button(sf::Vector2f dimensions, sf::Vector2f location, sf::Font &font, std::string initText, int thickness, int characterSize, sf::Color colorText, sf::Color colorBoxOutline);
		void changePosition(float x, float y);
		std::string getButtonNameStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();
		bool clicked(sf::Vector2f mousePosF);

};
#endif /* BUTTON_H_ */
