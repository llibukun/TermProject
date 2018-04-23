/*
 * Snacks.h
 *
 *  Created on: Apr 22, 2018
 *      Author: User
 */

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

Snacks::Snacks(std::string name, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this -> price = price;
}

void Snacks::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Snacks::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Snacks::getButton()
{
	return this -> button;
}

sf::Text Snacks::getButtonName()
{
	return this -> nameText;
}

bool Snacks::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Snacks::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

double Snacks::getPrice()
{
	return this -> price;
}

std::string Snacks::getName()
{
	return this -> name;
}

sf::Text Snacks::getPriceText()						//get pricePerLlb value in sf::Text form
{
	return this ->priceText;
}

#endif /* SNACKS_H_ */
