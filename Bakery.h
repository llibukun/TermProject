#ifndef BAKERY_H_
#define BAKERY_H_

#include <iostream> // cin and cout
#include <string> // for the string class

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Bakery
{
    friend class Store;

//Fields
    private:
		sf::RectangleShape button;
		sf::Text nameText;

		const std::string name; // Item name
		double pricePerBox; // the price per box

		sf::Text pricePerBoxText;

//Declaration of Bakery Functions
    public:
		Bakery(std::string name, double pricePerBox, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void changeButtonPosition(float x, float y);
		void changeTextPosition(float x, float y);
		std::string getButtonNameStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();

		sf::Text getPPBText();
		bool clicked(sf::Vector2f mousePosF);

		std::string getName();
		double getPricePerBox();
};

#endif /* BAKERY_H_ */
