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


#endif /* GRAINS_H_ */
