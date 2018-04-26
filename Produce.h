#ifndef PRODUCE_H_
#define PRODUCE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Produce
{
	friend class Store;
	private:
		sf::RectangleShape button;
		sf::Text nameText;

		const std::string name;
		const std::string type;
		double pricePerLlb;
		double supermarketQuantity;

		sf::Text typeText;
		sf::Text pricePerLlbText;

	public:
		Produce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void changeButtonPosition(float x, float y);
		void changeTextPosition(float x, float y);
		std::string getButtonNameStr();
		std::string getButtonTypeStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();				//or getNameText()
		sf::Text getPPPText();						//get pricePerLlb value in sf::Text form
		sf::Text getTypeText();

		bool clicked(sf::Vector2f mousePosF);

		std::string getType();
		std::string getName();
		double getPricePerLlb();
};


#endif /* PRODUCE_H_ */
