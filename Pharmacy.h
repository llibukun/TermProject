// Pharmacy.h - Pharmacy Aisle Header File
// Author: David Espantoso
// COP3503 Final Project: Mr. Djald's Supermarket
// Due: Monday, April 23rd, 2018.

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

// CONSTRUCTOR
Pharmacy::Pharmacy(std::string name, double pricePerCapsules,  sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{

	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this->pricePerCapsules = pricePerCapsules;

	this -> pricePerCapsulesText.setString( std::to_string(pricePerCapsules) );

}

// SETTERS
void Pharmacy::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

void Pharmacy::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}


// GETTERS
std::string Pharmacy::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Pharmacy::getButton()
{
	return this -> button;
}

sf::Text Pharmacy::getButtonName()
{
	return this -> nameText;
}

bool Pharmacy::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

double Pharmacy::getPricePerCapsules()
{
	return this -> pricePerCapsules;
}

std::string Pharmacy::getName()
{
	return this -> name;
}

sf::Text Pharmacy::getPPCText()						//get pricePerLlb value in sf::Text form
{
	return this ->pricePerCapsulesText;
}



#endif /* PHARMACY_H_ */
