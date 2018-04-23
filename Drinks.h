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

#endif /* DRINKS_H_ */
