/*
 * Hygiene.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Jayme
 */

#ifndef HYGIENE_H_
#define HYGIENE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Hygiene
{
    friend class Store;
	private:
    	sf::RectangleShape button;
    	sf::Text nameText;

    	const std::string name;
    	double pricePerUnit;
    	double supermarketQuantity;


	public:
    	Hygiene(std::string name, double pricePerUnit, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
    	void changeButtonPosition(float x, float y);
    	void changeTextPosition(float x, float y);
    	std::string getButtonNameStr();
    	std::string getButtonTypeStr();
    	sf::RectangleShape getButton();
    	sf::Text getButtonName();

    	bool clicked(sf::Vector2f mousePosF);

    	std::string getName();
    	double getPricePerUnit();
};


Hygiene::Hygiene(std::string name, double pricePerUnit, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{
    button.setSize(dimensions);
    button.setOutlineThickness(5);
    button.setOutlineColor(sf::Color::Black);

    nameText.setFont(font);
    nameText.setString(initText);
    nameText.setCharacterSize(15);
    nameText.setColor(sf::Color::Black);

    this -> pricePerUnit = pricePerUnit;
    this -> supermarketQuantity = 100;
}

void Hygiene::changeButtonPosition(float x, float y)
{
    button.setPosition(x, y);
}

std::string Hygiene::getButtonNameStr()
{
    return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Hygiene::getButton()
{
    return this -> button;
}

bool Hygiene::clicked(sf::Vector2f mousePosF)
{
    if(button.getGlobalBounds().contains(mousePosF))
    {
        return true;
    }else{
        return false;
    }
}

void Hygiene::changeTextPosition(float x, float y)
{
    nameText.setPosition(x, y);
}


double Hygiene::getPricePerUnit()
{
    return this -> pricePerUnit;
}

std::string Hygiene::getName()
{
    return this -> name;
}

sf::Text Hygiene::getButtonName()
{
	return this -> nameText;
}

#endif /* HYGIENE_H_ */
