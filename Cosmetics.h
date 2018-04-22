// Cosmetics.h - Cosmetics Aisle Header File
// COP3503 Final Project: Mr. Djald's Supermarket
// Due: Monday, April 23rd, 2018.

#ifndef COSMETICS_H_
#define COSMETICS_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Cosmetics
{
    friend class Store;

    private:
		sf::RectangleShape button;
		sf::Text nameText;

        const std::string name; 	// Item name
        const std::string brand; // Brand name
        double price; 			 // store Price

    public:
        Cosmetics(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);

		void changeButtonPosition(float x, float y);
		void changeTextPosition(float x, float y);
		std::string getButtonNameStr();
		std::string getButtonBrandStr();
		sf::RectangleShape getButton();
		sf::Text getButtonName();				//or getNameText()
		sf::Text getPriceText();				//get pricePerLlb value in sf::Text form
		sf::Text getBrandText();

		bool clicked(sf::Vector2f mousePosF);

        std::string getName();
        std::string getBrand();
        double getPrice();
};

// CONSTRUCTOR
Cosmetics::Cosmetics (std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), brand(brand){

	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this->price = price; // set Price

}

// SETTERS

void Cosmetics::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Cosmetics::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Cosmetics::getButton()
{
	return this -> button;
}

sf::Text Cosmetics::getButtonName()
{
	return this -> nameText;
}
bool Cosmetics::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Cosmetics::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}


// GETTERS

std::string Cosmetics::getBrand(){
	return this->brand;
}

double Cosmetics::getPrice()
{
	return this->price;
}

std::string Cosmetics::getName()
{
	return this->name;
}


std::string Cosmetics::getButtonBrandStr()
{
	return this -> brand;
}

#endif /* COSMETICS_H_ */
