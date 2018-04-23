/*
 * Dairy.h
 *
 *  Created on: Apr 22, 2018
 *      Author: User
 */

#ifndef DAIRY_H_
#define DAIRY_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> // cin and cout

#include <string> // for the string class
#include <vector>

class Dairy // Dairy Products
{
	friend class Store;
		private:
			sf::RectangleShape button;
			sf::Text nameText;

			const std::string name; // E.g. Milk, Yogurt, Eggs
			const std::string brand; // President, Silk, Orville, Blue Diamond
			double price; // Price per bottle

			sf::Text brandText;
			sf::Text priceText;

		public:

			Dairy(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
			void changeButtonPosition(float x, float y);
			void changeTextPosition(float x, float y);
			std::string getButtonNameStr();
			std::string getButtonBrandStr();
			sf::RectangleShape getButton();
			sf::Text getButtonName();				//or getNameText()
			sf::Text getPriceText();						//get pricePerLlb value in sf::Text form
			sf::Text getBrandText();

			bool clicked(sf::Vector2f mousePosF);

			std::string getName(); // E.g. Milk, Yogurt, Eggs
			std::string getBrand(); // President, Silk, Orville, Blue Diamond
			double getPrice(); // Price per bottle
};

// CONSTRUCTOR

Dairy::Dairy(std::string name, std::string brand, double price, sf::Vector2f dimensions, sf::Font &font, std::string initText):name(name), brand(brand)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this -> price = price;
	this -> brandText.setString(brand);
	this -> priceText.setString( std::to_string(price));
}

void Dairy::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Dairy::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Dairy::getButton()
{
	return this -> button;
}

sf::Text Dairy::getButtonName()
{
	return this -> nameText;
}

bool Dairy::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Dairy::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

std::string Dairy::getBrand()
{
	return this -> brand;
}

double Dairy::getPrice()
{
	return this -> price;
}

std::string Dairy::getName()
{
	return this -> name;
}

sf::Text Dairy::getPriceText()						//get pricePerLlb value in sf::Text form
{
	return this ->priceText;
}

sf::Text Dairy::getBrandText()
{
	return this -> brandText;
}

std::string Dairy::getButtonBrandStr()
{
	return this -> brand;
}

#endif /* DAIRY_H_ */
