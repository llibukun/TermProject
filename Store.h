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
#include "Bakery.h"
#include "Cosmetics.h"
#include "Hygiene.h"
#include "Pharmacy.h"
#include "Dairy.h"
#include "Grains.h"
#include "Snacks.h"

class Store{
	private:
		std::vector<Produce> produceItems;
		std::vector<Meats> meatItems;
		std::vector<Deli> deliItems;
		std::vector<Drinks> drinkItems;
		std::vector<Bakery> bakeryItems;
		std::vector<Cosmetics> cosmeticsItems;
		std::vector<Hygiene> hygieneItems;
		std::vector<Pharmacy> pharmacyItems;
		std::vector<Dairy> dairyItems;
		std::vector<Grains> grainsItems;
		std::vector<Snacks> snacksItems;
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
		void addDrinks(std::string name, std::string category, double pricePerContianer, sf::Vector2f dimensions, sf::Font &font, std::string initText);
		void drinksGrid();
		int amountOfDrinksItems();
		int checkDrinksButtonPressed(sf::Vector2f mousePosF);
		Drinks getDrinksItem(int pos);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Bakery Function Declarations
		void addBakery(std::string name, double pricePerBox, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		void bakeryGrid();
		int amountOfBakeryItems();
		int checkBakeryButtonPressed(sf::Vector2f mousePosF);
		Bakery getBakeryItem(int pos);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 //Cosmetics Function Declarations
		        void addCosmetics(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		        void cosmeticsGrid();
		        int amountOfCosmeticsItems();
		        int checkCosmeticsButtonPressed(sf::Vector2f mousePosF);
		        Cosmetics getCosmeticsItem(int pos);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Dairy Function Declarations
		        void addDairy(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		        void dairyGrid();
		        int amountOfDairyItems();
		        int checkDairyButtonPressed(sf::Vector2f mousePosF);
		        Dairy getDairyItem(int pos);
	    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Hygiene Function Declarations
		        void addHygiene(std::string name, double pricePerUnit, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		        void hygieneGrid();
		        int amountOfHygieneItems();
		        int checkHygieneButtonPressed(sf ::Vector2f mousePosF);
		        Hygiene getHygieneItem(int pos);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	    ///////////////////////////////////////////////////////////////////////////////////
		//Pharmacy Function Declarations
		        void addPharmacy(std::string name, double pricePerCapsules, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		        void pharmacyGrid();
		        int amountOfPharmacyItems();
		        int checkPharmacyButtonPressed(sf::Vector2f mousePosF);
		        Pharmacy getPharmacyItem(int pos);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//Grains Function Declarations
			void addGrains(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
			void grainsGrid();
			int amountOfGrainsItems();
			int checkGrainsButtonPressed(sf::Vector2f mousePosF);
			Grains getGrainsItem(int pos);
	    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Snacks Function Declarations
		   void addSnacks(std::string name, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText);
		   void snacksGrid();
		   int amountOfSnacksItems();
		   int checkSnacksButtonPressed(sf::Vector2f mousePosF);
		   Snacks getSnacksItem(int pos);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	float x = 110.0f;
	float y = 160.0f;
	int cnt = 0;
	for(int i = 0, max = produceItems.size(); i!=max; ++i )
	{
		produceItems.at(i).changeButtonPosition(x, y);
		produceItems.at(i).changeTextPosition(x+5, y+5);
		x+=200.0f;
		cnt++;

		if(cnt == 5)
		{
			cnt = 0;
			x = 110.0f;
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
		float x = 110.0f;
		float y = 160.0f;
		int cnt = 0;
		for(int i = 0, max = meatItems.size(); i!=max; ++i )
		{
			meatItems.at(i).changeButtonPosition(x, y);
			meatItems.at(i).changeTextPosition(x+5, y+5);
			x+=200.0f;
			cnt++;

			if(cnt == 5)
			{
				cnt = 0;
				x = 110.0f;
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
    float x = 110.0f;
    float y = 160.0f;
    int cnt = 0;
    for(int i = 0, max = deliItems.size(); i!=max; ++i )
    {
        deliItems.at(i).changeButtonPosition(x, y);
        deliItems.at(i).changeTextPosition(x+5, y+5);
        x+=200.0f;
        cnt++;

        if(cnt == 5)
        {
            cnt = 0;
            x = 110.0f;
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
void Store::addDrinks(std::string name, std::string category, double pricePerContainer, sf::Vector2f dimensions,  sf::Font &font, std::string initText)
{
	drinkItems.push_back(Drinks( name, category, pricePerContainer, dimensions, font, initText));
}
void Store::drinksGrid()
{
	float x = 110.0f;
	float y = 160.0f;
	int cnt = 0;
	for(int i = 0, max = drinkItems.size(); i!=max; ++i )
	{
		drinkItems.at(i).changeButtonPosition(x, y);
		drinkItems.at(i).changeTextPosition(x+5, y+5);
		x+=200.0f;
		cnt++;

		if(cnt == 5)
		{
			cnt = 0;
			x = 110.0f;
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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Bakery Functions
void Store::addBakery(std::string name, double pricePerBox, sf::Vector2f dimensions, sf::Font &font, std::string initText)
{
    bakeryItems.push_back(Bakery( name, pricePerBox,  dimensions, font, initText));
}

void Store::bakeryGrid()
{
    float x = 110.0f;
    float y = 160.0f;
    int cnt = 0;
    for(int i = 0, max = bakeryItems.size(); i!=max; ++i )
    {
        bakeryItems.at(i).changeButtonPosition(x, y);
        bakeryItems.at(i).changeTextPosition(x+5, y+5);
        x+=200.0f;
        cnt++;

        if(cnt == 5)
        {
            cnt = 0;
            x = 110.0f;
            y += 100.0f;
        }
    }
}

int Store::checkBakeryButtonPressed(sf::Vector2f mousePosF)
{
    for(int i = 0, max = bakeryItems.size(); i!=max;++i)
    {
        if(bakeryItems.at(i).clicked(mousePosF))
            return i;
    }
    return 444;
}

int Store::amountOfBakeryItems()
{
    return bakeryItems.size();
}

Bakery Store::getBakeryItem(int pos)
{
    return bakeryItems.at(pos);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Cosmetics Function Implementation
void Store::addCosmetics(std::string name, std::string brand, double price, sf::Vector2f dimensions, sf::Font &font, std::string initText)
{
    cosmeticsItems.push_back(Cosmetics( name,  brand,  price,  dimensions, font, initText));
}

void Store::cosmeticsGrid()
{
    float x = 110.0f;
    float y = 160.0f;
    int cnt = 0;
    for(int i = 0, max = cosmeticsItems.size(); i!=max; ++i )
    {
        cosmeticsItems.at(i).changeButtonPosition(x, y);
        cosmeticsItems.at(i).changeTextPosition(x+5, y+5);
        x+=200.0f;
        cnt++;

        if(cnt == 5)
        {
            cnt = 0;
            x = 110.0f;
            y += 100.0f;
        }
    }
}

int Store::checkCosmeticsButtonPressed(sf::Vector2f mousePosF)
{
    for(int i = 0, max = cosmeticsItems.size(); i!=max;++i)
    {
        if(cosmeticsItems.at(i).clicked(mousePosF))
            return i;
    }
    return 444;
}

int Store::amountOfCosmeticsItems()
{
    return cosmeticsItems.size();
}

Cosmetics Store::getCosmeticsItem(int pos)
{
    return cosmeticsItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////
//Hygiene Function Declarations
void Store::addHygiene(std::string name, double pricePerUnit, sf::Vector2f dimensions, sf::Font &font, std::string initText)
{
	hygieneItems.push_back(Hygiene( name,  pricePerUnit,  dimensions, font, initText));
}

void Store::hygieneGrid()
{
	float x = 110.0f;
	float y = 160.0f;
	int cnt = 0;
	for(int i = 0, max = hygieneItems.size(); i!=max; ++i )
	{
		hygieneItems.at(i).changeButtonPosition(x, y);
		hygieneItems.at(i).changeTextPosition(x+5, y+5);
		x+=200.0f;
		cnt++;

		if(cnt == 5)
		{
			cnt = 0;
			x = 110.0f;
			y += 100.0f;
		}
	}
}

int Store::checkHygieneButtonPressed(sf::Vector2f mousePosF)
{
	for(int i = 0, max = hygieneItems.size(); i!=max;++i)
	{
		if(hygieneItems.at(i).clicked(mousePosF))
			return i;
	}
	return 444;
}

int Store::amountOfHygieneItems()
{
	return hygieneItems.size();
}

Hygiene Store::getHygieneItem(int pos)
{
	return hygieneItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
//Pharmacy Function Implementation
void Store::addPharmacy(std::string name, double pricePerCapsules, sf::Vector2f dimensions,  sf::Font &font, std::string initText)
{
    pharmacyItems.push_back(Pharmacy( name, pricePerCapsules,  dimensions, font, initText));
}

void Store::pharmacyGrid()
{
    float x = 110.0f;
    float y = 160.0f;
    int cnt = 0;
    for(int i = 0, max = pharmacyItems.size(); i!=max; ++i )
    {
        pharmacyItems.at(i).changeButtonPosition(x, y);
        pharmacyItems.at(i).changeTextPosition(x+5, y+5);
        x+=200.0f;
        cnt++;

        if(cnt == 5)
        {
            cnt = 0;
            x = 110.0f;
            y += 100.0f;
        }
    }
}

int Store::checkPharmacyButtonPressed(sf::Vector2f mousePosF)
{
    for(int i = 0, max = deliItems.size(); i!=max;++i)
    {
        if(pharmacyItems.at(i).clicked(mousePosF))
            return i;
    }
    return 444;
}

int Store::amountOfPharmacyItems()
{
    return pharmacyItems.size();
}

Pharmacy Store::getPharmacyItem(int pos)
{
    return pharmacyItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Dairy Function Declarations
void Store::addDairy(std::string name, std::string brand, double price, sf::Vector2f dimensions, sf::Font &font, std::string initText)
{
    dairyItems.push_back(Dairy( name,  brand,  price,  dimensions, font, initText));
}

void Store::dairyGrid()
{
    float x = 110.0f;
    float y = 160.0f;
    int cnt = 0;
    for(int i = 0, max = dairyItems.size(); i!=max; ++i )
    {
        dairyItems.at(i).changeButtonPosition(x, y);
        dairyItems.at(i).changeTextPosition(x+5, y+5);
        x+=200.0f;
        cnt++;

        if(cnt == 5)
        {
            cnt = 0;
            x = 110.0f;
            y += 100.0f;
        }
    }
}

int Store::checkDairyButtonPressed(sf::Vector2f mousePosF)
{
    for(int i = 0, max = dairyItems.size(); i!=max;++i)
    {
        if(dairyItems.at(i).clicked(mousePosF))
            return i;
    }
    return 444;
}

int Store::amountOfDairyItems()
{
    return dairyItems.size();
}

Dairy Store::getDairyItem(int pos)
{
    return dairyItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Grains Functions
void Store::addGrains(std::string name, std::string brand, double price, sf::Vector2f dimensions, sf::Font &font, std::string initText)
{
    grainsItems.push_back(Grains( name,  brand,  price,  dimensions, font, initText));
}

void Store::grainsGrid()
{
    float x = 110.0f;
    float y = 160.0f;
    int cnt = 0;
    for(int i = 0, max = grainsItems.size(); i!=max; ++i )
    {
        grainsItems.at(i).changeButtonPosition(x, y);
        grainsItems.at(i).changeTextPosition(x+5, y+5);
        x+=200.0f;
        cnt++;

        if(cnt == 5)
        {
            cnt = 0;
            x = 110.0f;
            y += 100.0f;
        }
    }
}

int Store::checkGrainsButtonPressed(sf::Vector2f mousePosF)
{
    for(int i = 0, max = grainsItems.size(); i!=max;++i)
    {
        if(grainsItems.at(i).clicked(mousePosF))
            return i;
    }
    return 444;
}

int Store::amountOfGrainsItems()
{
    return grainsItems.size();
}

Grains Store::getGrainsItem(int pos)
{
    return grainsItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Snacks Functions
void Store::addSnacks(std::string name, double price, sf::Vector2f dimensions, sf::Font &font, std::string initText)
{
    snacksItems.push_back(Snacks( name, price,  dimensions, font, initText));
}

void Store::snacksGrid()
{
    float x = 110.0f;
    float y = 160.0f;
    int cnt = 0;
    for(int i = 0, max = snacksItems.size(); i!=max; ++i )
    {
        snacksItems.at(i).changeButtonPosition(x, y);
        snacksItems.at(i).changeTextPosition(x+5, y+5);
        x+=200.0f;
        cnt++;

        if(cnt == 5)
        {
            cnt = 0;
            x = 110.0f;
            y += 100.0f;
        }
    }
}

int Store::checkSnacksButtonPressed(sf::Vector2f mousePosF)
{
    for(int i = 0, max = snacksItems.size(); i!=max;++i)
    {
        if(snacksItems.at(i).clicked(mousePosF))
            return i;
    }
    return 444;
}

int Store::amountOfSnacksItems()
{
    return snacksItems.size();
}

Snacks Store::getSnacksItem(int pos)
{
    return snacksItems.at(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
			cnt++;
			if(cnt == 9)
			{
				x+= 400;
				y = 150.0f;
			}
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
