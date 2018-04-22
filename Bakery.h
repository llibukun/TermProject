/*
 * Bakery.h
 *
 *  Created on: Apr 22, 2018
 *      Author: User
 */

#ifndef BAKERY_H_
#define BAKERY_H_

#include <iostream> // cin and cout
#include <string> // for the string class

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Bakery
{
    friend class Store;

    private:
		sf::RectangleShape button;
		sf::Text nameText;

		const std::string name; // Item name
		double pricePerBox; // the price per box

		sf::Text pricePerBoxText;

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
Bakery::Bakery(std::string name, double pricePerBox, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{
		button.setSize(dimensions);
		button.setOutlineThickness(5);
		button.setOutlineColor(sf::Color::Black);

		nameText.setFont(font);
		nameText.setString(initText);
		nameText.setCharacterSize(15);
		nameText.setColor(sf::Color::Black);

		this->pricePerBox = pricePerBox;
}

void Bakery::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Bakery::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Bakery::getButton()
{
	return this -> button;
}

sf::Text Bakery::getButtonName()
{
	return this -> nameText;
}

bool Bakery::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Bakery::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

double Bakery::getPricePerBox()
{
	return this -> pricePerBox;
}
std::string Bakery::getName()
{
	return this -> name;
}

sf::Text Bakery::getPPBText()						//get pricePerLlb value in sf::Text form
{
	return this ->pricePerBoxText;
}

#endif /* BAKERY_H_ */
