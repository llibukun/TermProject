#ifndef PHARMACY_H_
#define PHARMACY_H_

#include <iostream> // cin and cout
#include <string> // for the string class
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Pharmacy
{
    friend class Store;

    private:

		sf::RectangleShape button;
		sf::Text nameText;

		const std::string name;
        double pricePerCapsules;

		sf::Text pricePerCapsulesText;

    public:
        Pharmacy(std::string name, double pricePerCapsules,  sf::Vector2f dimensions,  sf::Font &font, std::string initText);
        std::string getName();

		void changeButtonPosition(float x, float y);
		void changeTextPosition(float x, float y);
		std::string getButtonNameStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();				//or getNameText()
		sf::Text getPPCText();					//get pricePerCapsule value in sf::Text form


	bool clicked(sf::Vector2f mousePosF);

	double getPricePerCapsules();
};

#endif /* PHARMACY_H_ */
