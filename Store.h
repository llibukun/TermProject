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

		bool searchEngine(std::string item);

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



#endif /* STORE_H_ */
