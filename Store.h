/*
 * Store.h
 *
 *  Created on: Apr 22, 2018
 *      Author: User
 */

#ifndef STORE_H_
#define STORE_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Button.h"

#include "Produce.h"
#include "Meats.h"
#include "Deli.h"
#include "Drinks.h"

class Store{
	private:
		std::vector<Produce> produceItems;
		std::vector<Meats> meatItems;
		std::vector<Deli> deliItems;

		std::vector<Drinks> drinkItems;

		std::vector<double> cartPrice;
		std::vector<sf::Text> cartItems;

	public:
		Store();

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Produce Function Declarations
		void addProduce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void produceGrid();
		int amountOfProduceItems();
		//void addProduce(std::string name, std::string type, double pricePerLlb, Button button );
		int checkProduceButtonPressed(sf::Vector2f mousePosF);
		Produce getProduceItem(int pos);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Meat Function Declarations
		void addMeat(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void meatGrid();
		int amountOfMeatItems();
		int checkMeatButtonPressed(sf::Vector2f mousePosF);
		Meats getMeatItem(int pos);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Deli Function Declarations
		void addDeli(std::string name, double pricePerLlb, double pricePerUnit, sf::Vector2f dimensions, sf::Font &font, std::string initText);
		void deliGrid();
		int amountOfDeliItems();
		int checkDeliButtonPressed(sf::Vector2f mousePosF);
		Deli getDeliItem(int pos);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Drinks Function Declarations
		void addDrinks(std::string name, std::string category, double pricePerOz, sf::Vector2f dimensions, sf::Font &font, std::string initText);
		void drinksGrid();
		int amountOfDrinksItems();
		int checkDrinksButtonPressed(sf::Vector2f mousePosF);
		Drinks getDrinksItem(int pos);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Cashier Function Declaration
		void addToCart(double cost, std::string itemName, sf::Font &font);
		double calculateCost();
		sf::Text getCartItem(int pos);
		void organizeCartContents();
		int getCartSize();
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


};

Store::Store(){
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Produce Functions
void Store::addProduce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions, sf::Font &font, std::string initText)
{
	produceItems.push_back(Produce( name,  type,  pricePerLlb,  dimensions, font, initText));
}

void Store::produceGrid()
{
	float x = 350.0f;
	float y = 150.0f;
	int cnt = 0;
	for(int i = 0, max = produceItems.size(); i!=max; ++i )
	{
		produceItems.at(i).changeButtonPosition(x, y);
		produceItems.at(i).changeTextPosition(x+5, y+5);
		x+=200.0f;
		cnt++;

		if(cnt == 4)
		{
			cnt = 0;
			x = 350.0f;
			y += 100.0f;
		}
	}
}

int Store::checkProduceButtonPressed(sf::Vector2f mousePosF)
{
	for(int i = 0, max = produceItems.size(); i!=max;++i)
	{
		if(produceItems.at(i).clicked(mousePosF))
			return i;
	}
		return 444;
}

int Store::amountOfProduceItems()
{
	return produceItems.size();
}

Produce Store::getProduceItem(int pos)
{
	return produceItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Meat Functions
void Store::addMeat(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText)
{
	meatItems.push_back(Meats( name, type,  pricePerLlb, dimensions, font, initText));
}

void Store::meatGrid()
{
		float x = 350.0f;
		float y = 150.0f;
		int cnt = 0;
		for(int i = 0, max = meatItems.size(); i!=max; ++i )
		{
			meatItems.at(i).changeButtonPosition(x, y);
			meatItems.at(i).changeTextPosition(x+5, y+5);
			x+=200.0f;
			cnt++;

			if(cnt == 4)
			{
				cnt = 0;
				x = 350.0f;
				y += 100.0f;
			}
		}
}

int Store::amountOfMeatItems()
{
	return meatItems.size();
}

int Store::checkMeatButtonPressed(sf::Vector2f mousePosF)
{
	for(int i = 0, max = meatItems.size(); i!=max;++i)
		{
			if(meatItems.at(i).clicked(mousePosF))
				return i;
		}
			return 444;
}

Meats Store::getMeatItem(int pos)
{
	return meatItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Deli Function Implementations
void Store::addDeli(std::string name, double pricePerLlb,  double pricePerUnit, sf::Vector2f dimensions,  sf::Font &font, std::string initText)
{
    deliItems.push_back(Deli( name, pricePerLlb, pricePerUnit,  dimensions, font, initText));
}

void Store::deliGrid()
{
    float x = 350.0f;
    float y = 150.0f;
    int cnt = 0;
    for(int i = 0, max = deliItems.size(); i!=max; ++i )
    {
        deliItems.at(i).changeButtonPosition(x, y);
        deliItems.at(i).changeTextPosition(x+5, y+5);
        x+=200.0f;
        cnt++;

        if(cnt == 4)
        {
            cnt = 0;
            x = 350.0f;
            y += 100.0f;
        }
    }
}

int Store::checkDeliButtonPressed(sf::Vector2f mousePosF)
{
    for(int i = 0, max = deliItems.size(); i!=max;++i)
    {
        if(deliItems.at(i).clicked(mousePosF))
            return i;
    }
    return 444;
}

int Store::amountOfDeliItems()
{
    return deliItems.size();
}

Deli Store::getDeliItem(int pos)
{
    return deliItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Drinks Function Implementations
void Store::addDrinks(std::string name, std::string category, double pricePerOz, sf::Vector2f dimensions,  sf::Font &font, std::string initText)
{
	drinkItems.push_back(Drinks( name, category, pricePerOz, dimensions, font, initText));
}
void Store::drinksGrid()
{
	float x = 350.0f;
	float y = 150.0f;
	int cnt = 0;
	for(int i = 0, max = drinkItems.size(); i!=max; ++i )
	{
		drinkItems.at(i).changeButtonPosition(x, y);
		drinkItems.at(i).changeTextPosition(x+5, y+5);
		x+=200.0f;
		cnt++;

		if(cnt == 4)
		{
			cnt = 0;
			x = 350.0f;
			y += 100.0f;
		}
	}
}

int Store::amountOfDrinksItems()
{
	return drinkItems.size();
}

int Store::checkDrinksButtonPressed(sf::Vector2f mousePosF)
{
	for(int i = 0, max = drinkItems.size(); i!=max;++i)
	{
		if(drinkItems.at(i).clicked(mousePosF))
			return i;
	}
		return 444;
}
Drinks Store::getDrinksItem(int pos)
{
    return drinkItems.at(pos);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Cashier Functions
double Store::calculateCost()
{
	double totalPrice = 0;

	for(int i = 0, max = cartPrice.size(); i!=max;++i)
	{
		totalPrice += cartPrice.at(i);
	}
	return totalPrice;
}

void Store::addToCart(double cost, std::string itemName, sf::Font &font)
{
	sf::Text item;
	item.setString(itemName);
	item.setFont(font);
	item.setCharacterSize(35);
	item.setColor(sf::Color::Black);

	cartPrice.push_back(cost);

	cartItems.push_back(item);
}

void Store::organizeCartContents()
{
		float x = 400.0f;
		float y = 150.0f;
		int cnt = 0;
		for(int i = 0, max = cartItems.size(); i!=max; ++i )
		{
			cartItems.at(i).setPosition(x, y);
			y+=40.0f;
		}
}

sf::Text Store::getCartItem(int pos)
{
	return cartItems.at(pos);
}

int Store::getCartSize()
{
	return cartItems.size();
}
//////////////////////////////////////////////////////////////////////////////////////////////////



#endif /* STORE_H_ */
