#ifndef SNACKS_H_
#define SNACKS_H_

#include <iostream> // cin and cout
#include <string> // for the string class
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Snacks
{
    friend class Store;

    private:

		sf::RectangleShape button;
		sf::Text nameText;

		const std::string name;
		double price;

		sf::Text priceText;

    public:

		Snacks(std::string name, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void changeButtonPosition(float x, float y);
		void changeTextPosition(float x, float y);
		std::string getButtonNameStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();				//or getNameText()
		sf::Text getPriceText();				//get pricePerLlb value in sf::Text form

		bool clicked(sf::Vector2f mousePosF);


		Snacks(std::string name, double price);
		std::string getName();
		double getPrice();
};


#endif /* SNACKS_H_ */
