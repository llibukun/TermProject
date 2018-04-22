/*
 * Deli.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Robert
 */

#ifndef DELI_H_
#define DELI_H_

#include <iostream> // cin and cout
#include <string> // for the string class
#include <stdlib.h>  // for random number generator //srand
#include <time.h> // for random number generator //time

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Deli
{
  friend class Store;

  private:

    sf::RectangleShape button;
    sf::Text nameText;

    const std::string name; // Item name
    double pricePerLlb; // the price per pound
    double pricePerUnit; // the price per unit
    //double quantity; // Quantity in store
    //void updatePricePerLlb(double newPrice); // Change the Price per pound
    //void updatePricePerUnit(double newPrice); // Change the Price per unit
    //void decQuantity(double newQty); // Decrement the quantity in store

    sf::Text typeText;
    sf::Text pricePerLlbText;
    sf::Text pricePerUnitText;

  public:
    Deli(std::string name, double pricePerLlb, double pricePerUnit, sf::Vector2f dimensions,  sf::Font &font, std::string initText);

    void changeButtonPosition(float x, float y);
    void changeTextPosition(float x, float y);

    std::string getButtonNameStr();
    sf::RectangleShape getButton();
    sf::Text getButtonName();
    sf::Text getPPPText();
    sf::Text getPPUText();

    bool clicked(sf::Vector2f mousePosF);


    std::string getName();
    double getPricePerLlb();
    double getPricePerUnit();
    //double getQuantity();

};

// CONSTRUCTOR
Deli::Deli(std::string name, double pricePerLlb, double pricePerUnit, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{
    button.setSize(dimensions);
    button.setOutlineThickness(5);
    button.setOutlineColor(sf::Color::Black);

    nameText.setFont(font);
    nameText.setString(initText);
    nameText.setCharacterSize(15);
    nameText.setColor(sf::Color::Black);

    this->pricePerLlb = pricePerLlb;
    this->pricePerUnit = pricePerUnit;

    this -> pricePerLlbText.setString( std::to_string(pricePerLlb) );
    this -> pricePerUnitText.setString( std::to_string(pricePerUnit) );


}

void Deli::changeButtonPosition(float x, float y)
{
    button.setPosition(x, y);
}

std::string Deli::getButtonNameStr()
{
    return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Deli::getButton()
{
    return this -> button;
}

sf::Text Deli::getButtonName()
{
    return this -> nameText;
}

bool Deli::clicked(sf::Vector2f mousePosF)
{
    if(button.getGlobalBounds().contains(mousePosF))
    {
        return true;
    }else{
        return false;
    }
}



void Deli::changeTextPosition(float x, float y)
{
    nameText.setPosition(x, y);
}


double Deli::getPricePerLlb()
{
    return this -> pricePerLlb;
}

double Deli::getPricePerUnit()
{
    return this -> pricePerUnit;
}

sf::Text Deli::getPPPText()						//get pricePerLlb value in sf::Text form
{
    return this ->pricePerLlbText;
}

sf::Text Deli::getPPUText()						//get pricePerLlb value in sf::Text form
{
    return this ->pricePerUnitText;
}




#endif /* DELI_H_ */
