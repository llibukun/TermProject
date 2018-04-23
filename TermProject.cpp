#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <array>

#include "Store.h"
#include "TextBox.h"
#include "Button.h"

sf::RenderWindow window(sf::VideoMode(1200, 800), "Mr. Djald's Supermarket", sf::Style::Close^sf::Style::Titlebar);
sf::Font font;
sf::Font erasFont;
sf::Text total;
std::vector<std::string> names = {"Dave" , "Dean", "Jon"};

sf::Texture produceImageTexture;
sf::Sprite produceImageSprite;

std::string line;

int selectedProduce;
int selectedMeat;
int selectedDeli;
int selectedDrink;
int selectedBakery;
int selectedCosmetic;
int selectedHygiene;
int selectedPharmacy;
int selectedDairy;
int selectedGrains;
int selectedSnacks;
int windowDepth = 0;

std::string priceUnformatted;
int characterPos;
std:: string priceFormatted;

sf::Texture backdropTexture;

sf::Texture initial;
sf::Texture second;
sf::Texture produceTexture;
sf::Texture meatsTexture;
sf::Texture drinksTexture;
sf::Texture pharmacyTexture;
sf::Texture grainsTexture;
sf::Texture cosmeticsTexture;
sf::Texture dairyTexture;
sf::Texture bakeryTexture;
sf::Texture snacksTexture;
sf::Texture deliTexture;
sf::Texture hygieneTexture;
sf::Texture exitTexture;

sf::Texture produceAisleTexture;
sf::Texture meatsAisleTexture;
sf::Texture drinksAisleTexture;
sf::Texture pharmacyAisleTexture;
sf::Texture grainsAisleTexture;
sf::Texture cosmeticsAisleTexture;
sf::Texture dairyAisleTexture;
sf::Texture bakeryAisleTexture;
sf::Texture snacksAisleTexture;
sf::Texture deliAisleTexture;
sf::Texture hygieneAisleTexture;

std::string appendStr(std::string str1, std::string str2);

int main()
{
	std::cout<< std::fixed << std::setprecision(2);	//Sets cout to output numbers with 2 decimal places

	Store supermarket = Store();		//Creates object <supermarket>

	std::ifstream productDataFile;		//Initializes productDataFile as a istream object
	productDataFile.open("FOOD.txt");	//Data will be streamed from the <FOOD.txt> file

	// Saves one line of the text file into "line", until eof (end of file) is reached.
	while(std::getline(productDataFile, line))
	{

		std::vector<std::string> lineVec;			//<lineVec> is a vector that will be used to store the split strings
													//from the string "line"
		std::istringstream iss(line);				//create a string stream "iss" to operate on the string line.

	//While-loop will split "line" by the spaces it contains.  It will store the splitted strings into "lineVec"
		while( iss >> line )
		{
			replace( line.begin(), line.end(), '_', ' ' );	//remove underscores from strings
		    lineVec.push_back(line);
		}
	//The following bool expressions check what sections the each entry belongs to.
		if (lineVec.at(0).compare("Produce") == 0){
			supermarket.addProduce(lineVec.at(1), lineVec.at(2), stod(lineVec.at(3)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Meat")==0){
			supermarket.addMeat(lineVec.at(1), lineVec.at(2), stod(lineVec.at(3)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Deli")==0){
			supermarket.addDeli(lineVec.at(1), stod(lineVec.at(2)), stod(lineVec.at(3)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Drinks")==0){
			supermarket.addDrinks(lineVec.at(1), lineVec.at(2), stod(lineVec.at(3)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Bakery") == 0){
			supermarket.addBakery(lineVec.at(1), stod(lineVec.at(2)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if(lineVec.at(0).compare("Cosmetics") == 0){
			supermarket.addCosmetics(lineVec.at(1), lineVec.at(2), stod(lineVec.at(3)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Hygiene")==0){
			supermarket.addHygiene(lineVec.at(1), stod(lineVec.at(2)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Pharmacy")==0){
			supermarket.addPharmacy(lineVec.at(1), stod(lineVec.at(2)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Dairy")==0 ){
			supermarket.addDairy( lineVec.at(1), lineVec.at(2), stod(lineVec.at(3)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Grains")==0 ){
			supermarket.addGrains( lineVec.at(1), lineVec.at(2), stod(lineVec.at(3)), sf::Vector2f(150,30), font, lineVec.at(1));
		}else if (lineVec.at(0).compare("Snacks") == 0){
			supermarket.addSnacks(lineVec.at(1), stod(lineVec.at(2)), sf::Vector2f(150,30), font, lineVec.at(1));
		}

		lineVec.clear();
	}
		productDataFile.close();	//Closes the stream of productDataFile when the eof has been reached.

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
		if (!font.loadFromFile("arial.ttf"))
			return EXIT_FAILURE;

		if (!erasFont.loadFromFile("ErasITC-DEMI.ttf"))
			return EXIT_FAILURE;

	    if(!initial.loadFromFile("Images/Entrance.jpg"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!second.loadFromFile("Images/Background.jpg"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }
	    if (!backdropTexture.loadFromFile("Images/Introduction.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }
	    if (!produceTexture.loadFromFile("Images/Produce.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!meatsTexture.loadFromFile("Images/Meats.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!drinksTexture.loadFromFile("Images/Drinks.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!pharmacyTexture.loadFromFile("Images/Pharmacy.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!grainsTexture.loadFromFile("Images/Grains.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!cosmeticsTexture.loadFromFile("Images/Cosmetics.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!dairyTexture.loadFromFile("Images/Dairy.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!bakeryTexture.loadFromFile("Images/Bakery.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!snacksTexture.loadFromFile("Images/Snacks.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!deliTexture.loadFromFile("Images/Deli.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!hygieneTexture.loadFromFile("Images/Hygiene.png"))
	    {
	        std::cout<<"Load failed"<<std::endl;
	        system("pause");
	    }

	    if (!exitTexture.loadFromFile("Images/Exit.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	    sf::Sprite entrance;
	    entrance.setPosition(window.getSize().x/2 - 600.0f, 0.0f);
	    entrance.setTexture(initial);

	    sf::Sprite background;
	    background.setTexture(second);

	    sf::Sprite backdrop;
	    backdrop.setTexture(backdropTexture);

	    sf::Sprite exit;
	    exit.scale(1.1,1.1);
	    exit.setTexture(exitTexture);

	    sf::Sprite produce;
	    produce.setPosition(window.getSize().x/2 - 500.0f, 500.0f);
	    produce.setTexture(produceTexture);

	    sf::Sprite meats;
	    meats.setPosition(window.getSize().x/2 - 650.0f, 400.0f);
	    meats.setTexture(meatsTexture);

	    sf::Sprite drinks;
	    drinks.setPosition(window.getSize().x/2 - 200.0f, 450.0f);
	    drinks.setTexture(drinksTexture);

	    sf::Sprite pharmacy;
	    pharmacy.setPosition(window.getSize().x/2 - 450.0f, 450.0f);
	    pharmacy.setTexture(pharmacyTexture);

	    sf::Sprite grains;
	    grains.setPosition(window.getSize().x/2 - 225.0f, 450.0f);
	    grains.setTexture(grainsTexture);

	    sf::Sprite cosmetics;
	    cosmetics.scale(0.7,0.7);
	    cosmetics.setPosition(window.getSize().x/2 - 775.0f, 350.0f);
	    cosmetics.setTexture(cosmeticsTexture);

	    sf::Sprite dairy;
	    dairy.scale(1.2,1.2);
	    dairy.setPosition(window.getSize().x/2 - 230.0f, 450.0f);
	    dairy.setTexture(dairyTexture);

	    sf::Sprite bakery;
	    bakery.setPosition(window.getSize().x/2 - 475.0f, 375.0f);
	    bakery.setTexture(bakeryTexture);

	    sf::Sprite snacks;
	    dairy.scale(0.6,0.6);
	    snacks.setPosition(window.getSize().x/2 - 650.0f, 280.0f);
	    snacks.setTexture(snacksTexture);

	    sf::Sprite deli;
	    deli.setPosition(window.getSize().x/2 - 300.0f, 400.0f);
	    deli.setTexture(deliTexture);

	    sf::Sprite hygiene;
	    hygiene.scale(0.8,0.8);
	    hygiene.setPosition(window.getSize().x/2 - 250.0f, 350.0f);
	    hygiene.setTexture(hygieneTexture);

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
	    if (!produceAisleTexture.loadFromFile("Images/Aisles/Produce.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            return 0;
	        }

	        if (!meatsAisleTexture.loadFromFile("Images/Aisles/Meats.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!drinksAisleTexture.loadFromFile("Images/Aisles/Drinks.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!pharmacyAisleTexture.loadFromFile("Images/Aisles/Pharmacy.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!grainsAisleTexture.loadFromFile("Images/Aisles/Grains.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!cosmeticsAisleTexture.loadFromFile("Images/Aisles/Cosmetics.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!dairyAisleTexture.loadFromFile("Images/Aisles/Dairy.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!bakeryAisleTexture.loadFromFile("Images/Aisles/Bakery.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!snacksAisleTexture.loadFromFile("Images/Aisles/Snacks.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!deliAisleTexture.loadFromFile("Images/Aisles/Deli.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }

	        if (!hygieneAisleTexture.loadFromFile("Images/Aisles/Hygiene.png"))
	        {
	            std::cout<<"Load failed"<<std::endl;
	            system("pause");
	        }


	        sf::Sprite produceAisles;
	        produceAisles.setTexture(produceAisleTexture);

	        sf::Sprite meatsAisles;
	        meatsAisles.setTexture(meatsAisleTexture);

	        sf::Sprite pharmacyAisles;
	        pharmacyAisles.setTexture(pharmacyAisleTexture);

	        sf::Sprite cosmeticsAisles;
	        cosmeticsAisles.setTexture(cosmeticsAisleTexture);

	        sf::Sprite deliAisles;
	        deliAisles.setTexture(deliAisleTexture);

	        sf::Sprite bakeryAisles;
	        bakeryAisles.setTexture(bakeryAisleTexture);

	        sf::Sprite grainsAisles;
	        grainsAisles.setTexture(grainsAisleTexture);

	        sf::Sprite hygieneAisles;
	        hygieneAisles.setTexture(hygieneAisleTexture);

	        sf::Sprite dairyAisles;
	        dairyAisles.setTexture(dairyAisleTexture);

	        sf::Sprite snacksAisles;
	        snacksAisles.setTexture(snacksAisleTexture);

	        sf::Sprite drinksAisles;
	        drinksAisles.setTexture(drinksAisleTexture);

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

	TextBox nameBox = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 700.0f) ,5, font, "Enter Full Name");
	TextBox box = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 6.0f) ,5, font, "Search");

	Button produceButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 5.0f) , font, "Produce", 5, 25, sf::Color::Black, sf::Color::Black );
	Button meatsButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 72.0f) , font, "Meats", 5, 25, sf::Color::Black, sf::Color::Black);
	Button grainsButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 139.0f) , font, "Grains", 5, 25, sf::Color::Black, sf::Color::Black);
	Button dairyButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 206.0f) , font, "Dairy", 5, 25, sf::Color::Black, sf::Color::Black);
	Button drinksButton = Button(sf::Vector2f(200,57), sf::Vector2f(5.0f, 273.0f) , font, "Drinks", 5, 25, sf::Color::Black, sf::Color::Black);
	Button deliButton = Button(sf::Vector2f(200, 57), sf::Vector2f(5.0f, 340.0f), font, "Deli", 5, 25, sf::Color::Black, sf::Color::Black);
	Button bakeryButton = Button(sf::Vector2f(200, 57), sf::Vector2f(5.0f, 407.0f), font, "Bakery", 5, 25, sf::Color::Black, sf::Color::Black);
	Button cosmeticsButton = Button(sf::Vector2f(200, 57), sf::Vector2f(5.0f, 474.0f), font, "Cosmetics", 5, 25, sf::Color::Black, sf::Color::Black);
	Button hygieneButton = Button(sf::Vector2f(200, 57), sf::Vector2f(5.0f, 541.0f), font, "Hygiene", 5, 25, sf::Color::Black, sf::Color::Black);
	Button pharmacyButton = Button(sf::Vector2f(200, 57), sf::Vector2f(5.0f, 608.0f), font, "Pharmacy", 5, 25, sf::Color::Black, sf::Color::Black);
	Button snacksButton = Button(sf::Vector2f(200, 57), sf::Vector2f(5.0f, 675.0f), font, "Snacks", 5, 25, sf::Color::Black, sf::Color::Black);
	Button cartButton = Button(sf::Vector2f(125.0f, 45.0f), sf::Vector2f(1080.0f, 20.0f) , font, "Checkout", 9, 22, sf::Color::Black, sf::Color::Red);

	Button addToCart = Button(sf::Vector2f(150.0f, 50.0f), sf::Vector2f(600.0f, 100.0f) , font, "Add to Cart", 3, 25, sf::Color::Black, sf::Color::Black);
	Button backButton = Button(sf::Vector2f(100.0f, 45.0f), sf::Vector2f(1095.0f, 20.0f) , font, "MENU", 9, 22, sf::Color::Black, sf::Color::Red);

	TextBox customerName;
    while (window.isOpen())
    {

    	sf::Vector2i mousePos = sf::Mouse::getPosition( window );
    	sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

    	sf::Event event;

    	if(windowDepth == 0)
    	{
    	while(window.pollEvent(event) )
    	{
    			switch(event.type)
    			{
    			case(sf::Event::Closed):
    			{
    				window.close();
    				break;
    			}

    			case(sf::Event::MouseButtonPressed):
    			{

    				if ( nameBox.clicked( mousePosF) )	//detect if an object of TextBox was clicked
    				{
    					std::cout << "Clicked nameBox" << std::endl;
    					window.clear(sf::Color::White);
                        window.draw(entrance);
    					window.draw(nameBox.getTextBox());
    					window.draw(nameBox.getBoxText());
    					window.display();
    					while(window.waitEvent(event))
    					{
    						if(event.type == sf::Event::TextEntered)
    						{
    							nameBox.textEntered(event.text.unicode);
    							window.clear(sf::Color::White);
                                window.draw(entrance);
    							window.draw(nameBox.getTextBox());
    							window.draw(nameBox.getBoxText());
    							window.display();
    							if(event.text.unicode == 13)	//Must have a particular action be a break statement (<enter> key)
    							{
    								std::cout<<nameBox.getBoxTextStr()<<std::endl;
    								customerName = TextBox(sf::Vector2f(800.0f, 720.0f), erasFont, appendStr("Welcome ", nameBox.getBoxTextStr()), 30, sf::Color::Blue);
    								windowDepth++;
    								std::cout<<windowDepth<<std::endl;
    								break;
    							}
    						}
    					}
    				}
    			}
    		}
    			window.clear(sf::Color::White);
                window.draw(entrance);
    			window.draw(nameBox.getTextBox());
    			window.draw(nameBox.getBoxText());
    			window.display();
    	}
    	continue;
    	}


//Window depth 1 (Menu)
    	if(windowDepth == 1)
    	{
    	while(window.pollEvent(event) )
        {
        	switch(event.type)
        	{
        		case(sf::Event::Closed):
				{
        			window.close();
        			break;
				}
        		case(sf::Event::MouseButtonPressed):
				{
        			if ( box.clicked( mousePosF) )	//detect if an object of TextBox was clicked
        			{
        				std::cout << "Clicked textBox" << std::endl;
        				window.clear(sf::Color::White);
        				window.draw(box.getTextBox());
        				window.draw(box.getBoxText());
        				window.display();
        				while(window.waitEvent(event))
        				{
        					if(event.type == sf::Event::TextEntered)
        					{
        						box.textEntered(event.text.unicode);
        						window.clear(sf::Color::White);
        						window.draw(box.getTextBox());
        						window.draw(box.getBoxText());
        						window.display();
        						if(event.text.unicode == 13)	//Must have a particular action be a break statement (<enter> key)
        						{
        							std::cout<<box.getBoxTextStr()<<std::endl;
        							for(int i = 0, max = names.size(); i<max; ++i)
									{
        								if(box.getBoxTextStr().compare(names.at(i)) == 0)
        									std::cout<<"found person" << std::endl;
									}
        							break;
        						}
        					}
        				}
        			}
        			if(cartButton.clicked(mousePosF))
        			{
        				windowDepth = 37;
        			break;
        			}
        			if(produceButton.clicked(mousePosF))
        			{
        				std::cout<<"Produce Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
     					    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

     					    supermarket.produceGrid(); //creates produce items grid (sets locations for buttons)

     					    //Draw all the buttons
        			        window.clear(sf::Color::White);
                            window.draw(produceAisles);


        			        for(int i = 0, max = supermarket.amountOfProduceItems(); i!=max;++i)
        			        {
        			        	window.draw(supermarket.getProduceItem(i).getButton());
        			        	window.draw(supermarket.getProduceItem(i).getButtonName());
        			        }

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						std::cout<<supermarket.getProduceItem(0).getName()<<std::endl;

        						selectedProduce = supermarket.checkProduceButtonPressed(mousePosF);
        						if(selectedProduce != 444)
        						{
        							windowDepth++;
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(meatsButton.clicked(mousePosF))
        			{
        				std::cout<<"Meat Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.meatGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
                            window.draw(meatsAisles);

        					for(int i = 0, max = supermarket.amountOfMeatItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getMeatItem(i).getButton());
        						window.draw(supermarket.getMeatItem(i).getButtonName());
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedMeat = supermarket.checkMeatButtonPressed(mousePosF);
        						if(selectedMeat != 444)
        						{
        							windowDepth = windowDepth+2;	//equal 3
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(deliButton.clicked(mousePosF))
        			{
        				std::cout<<"Deli Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.deliGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
                            window.draw(deliAisles);

        					for(int i = 0, max = supermarket.amountOfDeliItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getDeliItem(i).getButton());
        						window.draw(supermarket.getDeliItem(i).getButtonName());
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedDeli = supermarket.checkDeliButtonPressed(mousePosF);
        						if(selectedDeli != 444)
        						{
        							windowDepth = windowDepth+3;	//equal 4
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(drinksButton.clicked(mousePosF))
        			{
        				std::cout<<"Drinks Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.drinksGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(drinksAisles);
        					for(int i = 0, max = supermarket.amountOfDrinksItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getDrinksItem(i).getButton());
        						window.draw(supermarket.getDrinksItem(i).getButtonName());
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedDrink = supermarket.checkDrinksButtonPressed(mousePosF);
        						if(selectedDrink != 444)
        						{
        							windowDepth = windowDepth+4;	//equal 5
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(bakeryButton.clicked(mousePosF))
        			{
        				std::cout<<"Bakery Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.bakeryGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(bakeryAisles);
        					for(int i = 0, max = supermarket.amountOfBakeryItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getBakeryItem(i).getButton());
        						window.draw(supermarket.getBakeryItem(i).getButtonName());
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedBakery = supermarket.checkBakeryButtonPressed(mousePosF);
        						if(selectedDrink != 444)
        						{
        							windowDepth = windowDepth+5;	//equal 6
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(cosmeticsButton.clicked(mousePosF))
        			{
        				std::cout<<"Cosmetics Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.cosmeticsGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(cosmeticsAisles);
        					for(int i = 0, max = supermarket.amountOfCosmeticsItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getCosmeticsItem(i).getButton());
        						window.draw(supermarket.getCosmeticsItem(i).getButtonName());
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedCosmetic = supermarket.checkCosmeticsButtonPressed(mousePosF);
        						if(selectedCosmetic!= 444)
        						{
        							windowDepth = windowDepth+6;	//equal 7
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(hygieneButton.clicked(mousePosF))
        			{
        				std::cout<<"Hygiene Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.hygieneGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(hygieneAisles);
        					for(int i = 0, max = supermarket.amountOfCosmeticsItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getHygieneItem(i).getButton());
        						window.draw(supermarket.getHygieneItem(i).getButtonName());///////////////////////////////////////////////////////////////////////////
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedHygiene = supermarket.checkHygieneButtonPressed(mousePosF);
        						if(selectedHygiene!= 444)
        						{
        							windowDepth = windowDepth+7;	//equal 8
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(pharmacyButton.clicked(mousePosF))
        			{
        				std::cout<<"Pharmacy Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.pharmacyGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(pharmacyAisles);

        					for(int i = 0, max = supermarket.amountOfPharmacyItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getPharmacyItem(i).getButton());
        						window.draw(supermarket.getPharmacyItem(i).getButtonName());///////////////////////////////////////////////////////////////////////////
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedPharmacy = supermarket.checkPharmacyButtonPressed(mousePosF);
        						if(selectedPharmacy!= 444)
        						{
        							windowDepth = windowDepth+8;	//equal 9
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(dairyButton.clicked(mousePosF))
        			{
        				std::cout<<"Dairy Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.dairyGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(dairyAisles);

        					for(int i = 0, max = supermarket.amountOfDairyItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getDairyItem(i).getButton());
        						window.draw(supermarket.getDairyItem(i).getButtonName());///////////////////////////////////////////////////////////////////////////
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedDairy = supermarket.checkDairyButtonPressed(mousePosF);
        						if(selectedDairy!= 444)
        						{
        							windowDepth = windowDepth+9;	//equal 10
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(grainsButton.clicked(mousePosF))
        			{
        				std::cout<<"Grains Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.grainsGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(grainsAisles);

        					for(int i = 0, max = supermarket.amountOfGrainsItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getGrainsItem(i).getButton());
        						window.draw(supermarket.getGrainsItem(i).getButtonName());///////////////////////////////////////////////////////////////////////////
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedGrains = supermarket.checkGrainsButtonPressed(mousePosF);
        						if(selectedGrains!= 444)
        						{
        							windowDepth = windowDepth+10;	//equal 11
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(snacksButton.clicked(mousePosF))
        			{
        				std::cout<<"Snacks Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.snacksGrid(); //creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(snacksAisles);

        					for(int i = 0, max = supermarket.amountOfSnacksItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getSnacksItem(i).getButton());
        						window.draw(supermarket.getSnacksItem(i).getButtonName());///////////////////////////////////////////////////////////////////////////
        					}

        					window.display();
        					if(event.type == sf::Event::KeyPressed)
        					{
        						if(event.key.code == sf::Keyboard::M)
        							break;
        					}
        					if(event.type == sf::Event::MouseButtonPressed)
        					{
        						selectedSnacks = supermarket.checkSnacksButtonPressed(mousePosF);
        						if(selectedSnacks!= 444)
        						{
        							windowDepth = windowDepth+11;	//equal 12
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}
        			}
        			break;
				}
        	}
        if(windowDepth == 1)
        {
        	window.clear(sf::Color::White);
        	window.draw(background);
        	window.draw(backdrop);
        	window.draw(produceButton.getButton());
        	window.draw(produceButton.getButtonName());
        	window.draw(meatsButton.getButton());
        	window.draw(meatsButton.getButtonName());
        	window.draw(grainsButton.getButton());
        	window.draw(grainsButton.getButtonName());
        	window.draw(dairyButton.getButton());
        	window.draw(dairyButton.getButtonName());
        	window.draw(drinksButton.getButton());
        	window.draw(drinksButton.getButtonName());
        	window.draw(deliButton.getButton());
        	window.draw(deliButton.getButtonName());
        	window.draw(box.getTextBox());
        	window.draw(box.getBoxText());
        	window.draw(bakeryButton.getButton());
        	window.draw(bakeryButton.getButtonName());
        	window.draw(cosmeticsButton.getButton());
        	window.draw(cosmeticsButton.getButtonName());
        	window.draw(hygieneButton.getButton());
        	window.draw(hygieneButton.getButtonName());
        	window.draw(pharmacyButton.getButton());
        	window.draw(pharmacyButton.getButtonName());
        	window.draw(snacksButton.getButton());
        	window.draw(snacksButton.getButtonName());
        	window.draw(cartButton.getButton());
        	window.draw(cartButton.getButtonName());
        	window.draw(customerName.getBoxText());
        	window.display();
        }
        }

    	}

    	//Construct Produce Frame
    	if(windowDepth == 2)
    	{
    		TextBox produceName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getProduceItem(selectedProduce).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox produceType = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Produce"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price Per Llb: $",(std::to_string(supermarket.getProduceItem(selectedProduce).getPricePerLlb())));
    		characterPos = priceUnformatted.find(".");
			priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox producePrice = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    				{
    					window.close();
    					break;
    				}
    				case(sf::Event::MouseButtonPressed):
					{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getProduceItem(selectedProduce).getPricePerLlb() , supermarket.getProduceItem(selectedProduce).getButtonNameStr(), font);
    					}
    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth--;
    					}
    					break;
					}
    				case(sf::Event::KeyPressed):		//Go back to menu
    				{
    					if(event.key.code == sf::Keyboard::M)
    					windowDepth--;
    					break;
    				}
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);
    			window.draw(background);
    		    window.draw(produce);
    			window.draw(produceName.getBoxText());
    		    window.draw(produceType.getBoxText());
    			window.draw(producePrice.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}

    	//Meat Frame
    	if(windowDepth == 3)
    	    	{
    	    		TextBox meatName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getMeatItem(selectedMeat).getButtonNameStr())), 50, sf::Color::Black);
    	    		TextBox meatType = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Meats"), 35, sf::Color::Black);

    	    		priceUnformatted = appendStr("Price Per Llb: $",(std::to_string(supermarket.getMeatItem(selectedMeat).getPricePerLlb())));
    	    		characterPos = priceUnformatted.find(".");
    				priceFormatted = priceUnformatted.erase(characterPos+3);
    	    		TextBox meatPrice = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    	    		while(window.pollEvent(event) )
    	    		{
    	    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    	    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    	    			switch(event.type)
    	    			{
    	    				case(sf::Event::Closed):
    	    				{
    	    					window.close();
    	    					break;
    	    				}
    	    				case(sf::Event::MouseButtonPressed):
    						{
    	    					if(addToCart.clicked(mousePosF))
    	    					{
    	    						supermarket.addToCart(supermarket.getMeatItem(selectedMeat).getPricePerLlb() , supermarket.getMeatItem(selectedMeat).getButtonNameStr(), font);
    	    					}

    	    					if(backButton.clicked(mousePosF))
    	    					{
    	    						windowDepth--;
    	    						windowDepth--;
    	    					}
    	    					break;
    						}


    	    				case(sf::Event::KeyPressed):		//Go back to menu
    	    				{
    	    					if(event.key.code == sf::Keyboard::M)
    	    					windowDepth--;
    	    					windowDepth--;
    	    					break;
    	    				}
    	    				default:
    	    					break;
    	    			}

    	    			window.clear(sf::Color::White);
    	    			window.draw(background);
    	    		    window.draw(meats);
    	    			window.draw(meatName.getBoxText());
    	    		    window.draw(meatType.getBoxText());
    	    			window.draw(meatPrice.getBoxText());
    	    			window.draw(addToCart.getButton());
    	    			window.draw(addToCart.getButtonName());
    	    			window.draw(backButton.getButton());
    	    			window.draw(backButton.getButtonName());

    	    			window.display();
    	    		}
    	    	}
    	//Deli Frame
    	if(windowDepth == 4)
    	{
    		TextBox deliName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getDeliItem(selectedDeli).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox deliType = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Deli"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price Per Llb: $",(std::to_string(supermarket.getDeliItem(selectedDeli).getPricePerLlb())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox deliPricePerPound = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    	    		{
    					window.close();
    					break;
    	    		}
    				case(sf::Event::MouseButtonPressed):
    	    		{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getDeliItem(selectedDeli).getPricePerLlb() , supermarket.getDeliItem(selectedDeli).getButtonNameStr(), font);
    					}

    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth = windowDepth - 3;
    					}
    					break;
    	    		}

    				case(sf::Event::KeyPressed):		//Go back to menu
    	    	    {
    					if(event.key.code == sf::Keyboard::M)
    						windowDepth = windowDepth - 3;
    					break;
    	    	    }
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);
    			window.draw(background);
    			window.draw(deli);
    			window.draw(deliName.getBoxText());
    			window.draw(deliType.getBoxText());
    			window.draw(deliPricePerPound.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}

    	//Drinks Frame
    	if(windowDepth == 5)
    	{
    		TextBox drinkName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getDrinksItem(selectedDrink).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox drinkAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Drinks"), 35, sf::Color::Black);

    		TextBox drinkCategory = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, appendStr("Category:  ", supermarket.getDrinksItem(selectedDrink).getCategory()), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price Per Container (8 Oz): $",(std::to_string(supermarket.getDrinksItem(selectedDrink).getPricePerContainer())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox drinkPricePerOz = TextBox(sf::Vector2f(0.0f,150.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    	    		{
    					window.close();
    					break;
    	    		}
    				case(sf::Event::MouseButtonPressed):
    	    		{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getDrinksItem(selectedDrink).getPricePerContainer() , supermarket.getDrinksItem(selectedDrink).getButtonNameStr(), font);
    					}

    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth = windowDepth - 4;
    					}
    					break;
    	    		}


    				case(sf::Event::KeyPressed):		//Go back to menu
    	    	    {
    					if(event.key.code == sf::Keyboard::M)
    						windowDepth = windowDepth - 4;
    					break;
    	    	    }
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);
    			window.draw(background);
    			window.draw(drinks);
    			window.draw(drinkName.getBoxText());
    			window.draw(drinkCategory.getBoxText());
    			window.draw(drinkAisle.getBoxText());
    			window.draw(drinkPricePerOz.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}

    	//Bakery Frame
    	if(windowDepth == 6)
    	{
    		TextBox bakeryName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getBakeryItem(selectedBakery).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox bakeryAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Bakery"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price Per Box: $",(std::to_string(supermarket.getBakeryItem(selectedBakery).getPricePerBox())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox bakeryPricePerBox = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    	    		{
    					window.close();
    					break;
    	    		}
    				case(sf::Event::MouseButtonPressed):
    	    		{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getBakeryItem(selectedBakery).getPricePerBox() , supermarket.getBakeryItem(selectedBakery).getButtonNameStr(), font);
    					}

    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth = windowDepth - 5;
    					}
    					break;
    	    		}


    				case(sf::Event::KeyPressed):		//Go back to menu
    	    	    {
    					if(event.key.code == sf::Keyboard::M)
    						windowDepth = windowDepth - 5;
    					break;
    	    	    }
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);
    			window.draw(background);
    			window.draw(bakery);
    			window.draw(bakeryName.getBoxText());
    			window.draw(bakeryAisle.getBoxText());
    			window.draw(bakeryPricePerBox.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}

    	//Cosmetics Frame
    	if(windowDepth == 7)
    	{
    		TextBox cosmeticName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getCosmeticsItem(selectedCosmetic).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox cosmeticAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Cosmetics"), 35, sf::Color::Black);
    		TextBox cosmeticBrand = TextBox(sf::Vector2f(0.0f,95.0f), erasFont, appendStr("Brand: ", supermarket.getCosmeticsItem(selectedCosmetic).getBrand()), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price: $",(std::to_string(supermarket.getCosmeticsItem(selectedCosmetic).getPrice())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox cosmeticPrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    	    		{
    					window.close();
    					break;
    	    		}
    				case(sf::Event::MouseButtonPressed):
    	    		{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getCosmeticsItem(selectedCosmetic).getPrice() , supermarket.getCosmeticsItem(selectedCosmetic).getName(), font);
    					}

    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth = windowDepth - 6;
    					}
    					break;
    	    		}


    				case(sf::Event::KeyPressed):		//Go back to menu
    	    	    {
    					if(event.key.code == sf::Keyboard::M)
    						windowDepth = windowDepth - 6;
    					break;
    	    	    }
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);
    			window.draw(background);
    			window.draw(cosmetics);
    			window.draw(cosmeticName.getBoxText());
    			window.draw(cosmeticAisle.getBoxText());
    			window.draw(cosmeticBrand.getBoxText());
    			window.draw(cosmeticPrice.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}

    	//Construct Hygiene Frame
    	if(windowDepth == 8)
    	{
    		TextBox hygieneName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getHygieneItem(selectedHygiene).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox hygieneAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Hygiene"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price: $",(std::to_string(supermarket.getHygieneItem(selectedHygiene).getPricePerUnit())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox hygienePrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    	    		{
    					window.close();
    					break;
    	    		}
    				case(sf::Event::MouseButtonPressed):
    	    		{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getHygieneItem(selectedHygiene).getPricePerUnit() , supermarket.getHygieneItem(selectedHygiene).getName(), font);
    					}

    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth = windowDepth - 7;
    					}
    					break;
    	    		}


    				case(sf::Event::KeyPressed):		//Go back to menu
    	    	    {
    					if(event.key.code == sf::Keyboard::M)
    						windowDepth = windowDepth - 7;
    					break;
    	    	    }
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);
    			window.draw(background);
    			window.draw(hygiene);
    			window.draw(hygieneName.getBoxText());
    			window.draw(hygieneAisle.getBoxText());
    			window.draw(hygienePrice.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}

    	//Construct Pharmacy Frame
    	if(windowDepth == 9)
    	{
    		TextBox pharmacyName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getPharmacyItem(selectedPharmacy).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox pharmacyAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Pharmacy"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price: $",(std::to_string( supermarket.getPharmacyItem(selectedPharmacy).getPricePerCapsules())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox pharmacyPrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    	    		{
    					window.close();
    					break;
    	    		}
    				case(sf::Event::MouseButtonPressed):
    	    		{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getPharmacyItem(selectedPharmacy).getPricePerCapsules(), supermarket.getPharmacyItem(selectedPharmacy).getName(), font);
    					}

    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth = windowDepth - 8;
    					}
    					break;
    	    		}


    				case(sf::Event::KeyPressed):		//Go back to menu
    	    	    {
    					if(event.key.code == sf::Keyboard::M)
    						windowDepth = windowDepth - 8;
    					break;
    	    	    }
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);
    			window.draw(background);
    			window.draw(pharmacy);
    			window.draw(pharmacyName.getBoxText());
    			window.draw(pharmacyAisle.getBoxText());
    			window.draw(pharmacyPrice.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}

    	//Construct Dairy Frame
    	if(windowDepth == 10)
    	{
    		TextBox dairyName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getDairyItem(selectedDairy).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox dairyAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Dairy"), 35, sf::Color::Black);
    		TextBox dairyBrand = TextBox(sf::Vector2f(0.0f,90.0f), erasFont, appendStr("Brand: ", (supermarket.getDairyItem(selectedDairy).getBrand())), 35, sf::Color::Black);
    		priceUnformatted = appendStr("Price: $",(std::to_string( supermarket.getDairyItem(selectedDairy).getPrice())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox dairyPrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
    			std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
    	    		{
    					window.close();
    					break;
    	    		}
    				case(sf::Event::MouseButtonPressed):
    	    		{
    					if(addToCart.clicked(mousePosF))
    					{
    						supermarket.addToCart(supermarket.getDairyItem(selectedDairy).getPrice(), supermarket.getDairyItem(selectedDairy).getName(), font);
    					}

    					if(backButton.clicked(mousePosF))
    					{
    						windowDepth = windowDepth - 9;
    					}
    					break;
    	    		}


    				case(sf::Event::KeyPressed):		//Go back to menu
    	    	    {
    					if(event.key.code == sf::Keyboard::M)
    						windowDepth = windowDepth - 9;
    					break;
    	    	    }
    				default:
    					break;
    			}

    			window.clear(sf::Color::White);
    			window.draw(background);
    			window.draw(dairy);
    			window.draw(dairyName.getBoxText());
    			window.draw(dairyAisle.getBoxText());
    			window.draw(dairyBrand.getBoxText());
    			window.draw(dairyPrice.getBoxText());
    			window.draw(addToCart.getButton());
    			window.draw(addToCart.getButtonName());
    			window.draw(backButton.getButton());
    			window.draw(backButton.getButtonName());

    			window.display();
    		}
    	}


    	//Construct Grains Frame
    	if(windowDepth == 11)
			{
				TextBox grainsName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getGrainsItem(selectedGrains).getButtonNameStr())), 50, sf::Color::Black);
				TextBox grainsAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Grains"), 35, sf::Color::Black);
				TextBox grainsBrand = TextBox(sf::Vector2f(0.0f,90.0f), erasFont, appendStr("Brand: ", (supermarket.getGrainsItem(selectedGrains).getBrand())), 35, sf::Color::Black);
				priceUnformatted = appendStr("Price: $",(std::to_string( supermarket.getGrainsItem(selectedGrains).getPrice())));
				characterPos = priceUnformatted.find(".");
				priceFormatted = priceUnformatted.erase(characterPos+3);
				TextBox grainsPrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

				while(window.pollEvent(event) )
				{
					std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
					std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
					switch(event.type)
					{
						case(sf::Event::Closed):
						{
							window.close();
							break;
						}
						case(sf::Event::MouseButtonPressed):
						{
							if(addToCart.clicked(mousePosF))
							{
								supermarket.addToCart(supermarket.getGrainsItem(selectedGrains).getPrice(), supermarket.getGrainsItem(selectedGrains).getName(), font);
							}

							if(backButton.clicked(mousePosF))
							{
								windowDepth = windowDepth - 10;
							}
							break;
						}


						case(sf::Event::KeyPressed):		//Go back to menu
						{
							if(event.key.code == sf::Keyboard::M)
								windowDepth = windowDepth - 10;
							break;
						}
						default:
							break;
					}

					window.clear(sf::Color::White);
					window.draw(background);
					window.draw(grains);
					window.draw(grainsName.getBoxText());
					window.draw(grainsAisle.getBoxText());
					window.draw(grainsBrand.getBoxText());
					window.draw(grainsPrice.getBoxText());
					window.draw(addToCart.getButton());
					window.draw(addToCart.getButtonName());
					window.draw(backButton.getButton());
					window.draw(backButton.getButtonName());

					window.display();
				}
			}
    	//Construct Snacks Frame
    	if(windowDepth == 12)
			{
				TextBox snacksName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getSnacksItem(selectedSnacks).getButtonNameStr())), 50, sf::Color::Black);
				TextBox snacksAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Snacks"), 35, sf::Color::Black);
				priceUnformatted = appendStr("Price: $",(std::to_string( supermarket.getSnacksItem(selectedSnacks).getPrice())));
				characterPos = priceUnformatted.find(".");
				priceFormatted = priceUnformatted.erase(characterPos+3);
				TextBox snacksPrice = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

				while(window.pollEvent(event) )
				{
					std::cout<< "Mouse Pos X: "<<mousePosF.x <<std::endl;
					std::cout<< "Mouse Pos Y: " <<mousePosF.y <<std::endl;
					switch(event.type)
					{
						case(sf::Event::Closed):
						{
							window.close();
							break;
						}
						case(sf::Event::MouseButtonPressed):
						{
							if(addToCart.clicked(mousePosF))
							{
								supermarket.addToCart(supermarket.getSnacksItem(selectedSnacks).getPrice(), supermarket.getSnacksItem(selectedSnacks).getName(), font);
							}

							if(backButton.clicked(mousePosF))
							{
								windowDepth = windowDepth - 11;
							}
							break;
						}


						case(sf::Event::KeyPressed):		//Go back to menu
						{
							if(event.key.code == sf::Keyboard::M)
								windowDepth = windowDepth - 11;
							break;
						}
						default:
							break;
					}

					window.clear(sf::Color::White);
					window.draw(background);
					window.draw(snacks);
					window.draw(snacksName.getBoxText());
					window.draw(snacksAisle.getBoxText());
					window.draw(snacksPrice.getBoxText());
					window.draw(addToCart.getButton());
					window.draw(addToCart.getButtonName());
					window.draw(backButton.getButton());
					window.draw(backButton.getButtonName());

					window.display();
				}
			}

    	if(windowDepth == 37)
    	{
    		supermarket.organizeCartContents();

    		priceUnformatted = appendStr("$",(std::to_string(supermarket.calculateCost())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);

    		TextBox total = TextBox( sf::Vector2f(520.0f,530.0f), erasFont, priceFormatted, 40, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
    			switch(event.type)
    			{
    				case(sf::Event::Closed):
					{
    					window.close();
    					break;
					}
    			}
    			window.clear(sf::Color::White);
                window.draw(background);
                window.draw(exit);
    			for(int i = 0, max = supermarket.getCartSize(); i!=max; ++i)
    			{
    				window.draw(supermarket.getCartItem(i));
    			}

    			window.draw(total.getBoxText());
    			window.display();
    		}
    	}
    }
    return 0;
}

std::string appendStr(std::string str1, std::string str2)
{
	return (str1.append(str2));
}
