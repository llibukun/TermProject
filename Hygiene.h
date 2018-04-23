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

#endif /* HYGIENE_H_ */
