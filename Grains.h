/*
 * Grains.h
 *
 *  Created on: Apr 22, 2018
 *      Author: User
 */

#ifndef GRAINS_H_
#define GRAINS_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Grains
{
    friend class Store;

private:
    sf::RectangleShape button;
    sf::Text nameText;

    const std::string name;
    const std::string brand;
    double price;

public:
    Grains(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
    void changeButtonPosition(float x, float y);
    void changeTextPosition(float x, float y);
    std::string getButtonNameStr();
    std::string getButtonBrandStr();
    sf::RectangleShape getButton();
    sf::Text getButtonName();				//or getNameText()
    sf::Text getBrandText();

    bool clicked(sf::Vector2f mousePosF);


    std::string getBrand();
    std::string getName();
    double getPrice();
};


Grains::Grains(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), brand(brand)
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

void Grains::changeButtonPosition(float x, float y)
{
    button.setPosition(x, y);
}

std::string Grains::getButtonNameStr()
{
    return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Grains::getButton()
{
    return this -> button;
}

sf::Text Grains::getButtonName()
{
    return this -> nameText;
}

bool Grains::clicked(sf::Vector2f mousePosF)
{
    if(button.getGlobalBounds().contains(mousePosF))
    {
        return true;
    }else{
        return false;
    }
}

void Grains::changeTextPosition(float x, float y)
{
    nameText.setPosition(x, y);
}

std::string Grains::getBrand()
{
    return this -> brand;
}

double Grains::getPrice()
{
    return this -> price;
}

std::string Grains::getName()
{
    return this -> name;
}



std::string Grains::getButtonBrandStr()
{
    return this -> brand;
}

#endif /* GRAINS_H_ */
