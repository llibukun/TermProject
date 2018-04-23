#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class TextBox
{
	private:
		sf::String boxInput;
		sf::Text boxText;
		std::string boxTextStr;
        sf::RectangleShape textBox;

	public:
        TextBox();
		TextBox(sf::Vector2f dimensions, sf::Vector2f location,int outlineThickness, sf::Font &font, std::string initText);
		TextBox(sf::Vector2f location, sf::Font &font, std::string text, int characterSize, sf::Color color);		//No box
		void changePosition(float x, float y);
		bool clicked(sf::Vector2f mousePosF);
		void textEntered(sf::Uint32 unicode);

		sf::RectangleShape getTextBox();
		sf::Text getBoxText();
		std::string getBoxTextStr();
};

#endif /* TEXTBOX_H_ */
