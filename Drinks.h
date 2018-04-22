// Drinks.h - Drinks Aisle Header File
// Author: Amanda Gonzalez
// COP3503 Final Project: Mr. Djald's Supermarket
// Due: Monday, April 23rd, 2018.

#ifndef DRINKS_H_
#define DRINKS_H_

#include <iostream> // cin and cout
#include <string> // for the string class
//#include <stdlib.h>  // for random number generator //srand
//#include <time.h> // for random number generator //time

class Drinks
{
    friend class Store;

    private:
      const std::string name;
      const std::string category;
      double pricePerOz;
//      double quantity;
//      void updatePricePerOz(double newPrice); // Change the Price per ounce
 //     void decQuantity(double newQty); // Decrement the quantity in store

    public:
      Drinks(std::string name, std::string category, double pricePerOz);
      std::string getName();
      std::string getCategory();
      double getPricePerOz();
      double getQuantity();
};

// CONSTRUCTOR
Drinks::Drinks (std::string name, std::string category, double pricePerOz):name(name), category(category){
  this->pricePerOz = pricePerOz;
}




// GETTERS
std::string Drinks::getName(){
	return this->name;
}

std::string Drinks::getCategory(){
	return this->category;
}

double Drinks::getPricePerOz(){
	return this->pricePerOz;
}



#endif /* DRINKS_H_ */
