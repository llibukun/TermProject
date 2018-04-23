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

#endif /* DELI_H_ */
