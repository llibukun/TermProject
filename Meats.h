/*
 * Meats.h
 *
 *  Created on: Apr 22, 2018
 *      Author: User
 */

#ifndef MEATS_H_
#define MEATS_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Meats
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
		Meats(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
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


Meats::Meats(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), type(type)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this -> pricePerLlb = pricePerLlb;
	this -> supermarketQuantity = 100;

	this -> typeText.setString(type);

	this -> pricePerLlbText.setString( std::to_string(pricePerLlb) );
}

void Meats::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Meats::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Meats::getButton()
{
	return this -> button;
}

sf::Text Meats::getButtonName()
{
	return this -> nameText;
}

bool Meats::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Meats::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

std::string Meats::getType()
{
	return this -> type;
}

double Meats::getPricePerLlb()
{
	return this -> pricePerLlb;
}

std::string Meats::getName()
{
	return this -> name;
}

sf::Text Meats::getPPPText()						//get pricePerLlb value in sf::Text form
{
	return this ->pricePerLlbText;
}

sf::Text Meats::getTypeText()
{
	return this -> typeText;
}

std::string Meats::getButtonTypeStr()
{
	return this -> type;
}



#endif /* MEATS_H_ */
