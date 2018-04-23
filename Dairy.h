/*
 * Dairy.h
 *
 *  Created on: Apr 22, 2018
 *      Author: User
 */

#ifndef DAIRY_H_
#define DAIRY_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> // cin and cout

#include <string> // for the string class
#include <vector>

class Dairy // Dairy Products
{
	friend class Store;
		private:
			sf::RectangleShape button;
			sf::Text nameText;

			const std::string name; // E.g. Milk, Yogurt, Eggs
			const std::string brand; // President, Silk, Orville, Blue Diamond
			double price; // Price per bottle

			sf::Text brandText;
			sf::Text priceText;

		public:

			Dairy(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
			void changeButtonPosition(float x, float y);
			void changeTextPosition(float x, float y);
			std::string getButtonNameStr();
			std::string getButtonBrandStr();
			sf::RectangleShape getButton();
			sf::Text getButtonName();				//or getNameText()
			sf::Text getPriceText();						//get pricePerLlb value in sf::Text form
			sf::Text getBrandText();

			bool clicked(sf::Vector2f mousePosF);

			std::string getName(); // E.g. Milk, Yogurt, Eggs
			std::string getBrand(); // President, Silk, Orville, Blue Diamond
			double getPrice(); // Price per bottle
};

#endif /* DAIRY_H_ */
