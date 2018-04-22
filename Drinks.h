// Drinks.h - Drinks Aisle Header File
// Author: Amanda Gonzalez
// COP3503 Final Project: Mr. Djald's Supermarket
// Due: Monday, April 23rd, 2018.

#ifndef DRINKS_H_
#define DRINKS_H_

#include <iostream> // cin and cout
#include <string> // for the string class
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Drinks
{
    friend class Store;

    private:
    sf::RectangleShape button;
    sf::Text nameText;

    const std::string name;
    const std::string category;
    double pricePerContainer;
    int quantity;


    public:
      Drinks(std::string name, std::string category, double pricePerContainer, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
      std::string getName();
      std::string getCategory();
      double getPricePerContainer();
      double getQuantity();

      void changeButtonPosition(float x, float y);
      void changeTextPosition(float x, float y);
      std::string getButtonNameStr();
      std::string getButtonTypeStr();
      sf::RectangleShape getButton();
      sf::Text getButtonName();				//or getNameText()

      bool clicked(sf::Vector2f mousePosF);

};

// CONSTRUCTOR
Drinks::Drinks (std::string name, std::string category, double pricePerContainer, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), category(category)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this->pricePerContainer = pricePerContainer;
	this ->quantity = 100;
}

void Drinks::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Drinks::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Drinks::getButton()
{
	return this -> button;
}

sf::Text Drinks::getButtonName()
{
	return this -> nameText;
}

bool Drinks::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Drinks::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}


double Drinks::getPricePerContainer()
{
	return this->pricePerContainer;
}

std::string Drinks::getName()
{
	return this -> name;
}

std::string Drinks::getCategory()
{
	return this->category;
}

#endif /* DRINKS_H_ */
