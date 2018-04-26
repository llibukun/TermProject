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

sf::RenderWindow window(sf::VideoMode(1200, 800), "Mr. Djald's Supermarket", sf::Style::Close^sf::Style::Titlebar);	//Intialize window object
sf::Font font;		//Initialize font with Arial font
sf::Font erasFont;	//Initialize erasFont with Eras Demi ITC
sf::Text total;

std::string line;	//Line received from input file stream

//Position of selected object
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
int cnt;

int searchFlag = 0;			//Flag if search
int windowDepth = 0;		//Depth of frame

//Variables for truncating trailing zeros (double to string)
std::string priceUnformatted;
int characterPos;
std:: string priceFormatted;

//Declaration of textures used
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

std::string appendStr(std::string str1, std::string str2);	//Function declaration to append 2 strings together

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
	//The following boolean expressions check what sections the each entry belongs to, and initializes objects accordingly, with their respective class
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

		lineVec.clear();	//Clear contents of lineVec
	}
		productDataFile.close();	//Closes the stream of productDataFile when the eof has been reached.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Load pre-declared textures with images, and fonts with different font styles.  If load fail, error message will print.
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Initialize sprites to point to initialized textures
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
//Loading more pre-declared textures with images.  If load fail, error message will print.

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Initializing more sprites to point to initialized textures
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

//Initialize all TextBox.(s)
	TextBox nameBox = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 700.0f) ,5, font, "Enter Full Name");
	TextBox box = TextBox(sf::Vector2f(400,50), sf::Vector2f(window.getSize().x/2 - 400/2, 6.0f) ,5, font, "Search");
	TextBox success = TextBox(sf::Vector2f(810.0f, 10.0f) , font, "Found Item", 30, sf::Color::Magenta);
	TextBox failure = TextBox(sf::Vector2f(810.0f, 10.0f) , font, "Item Not Found", 30, sf::Color::Red);

//Initialize all Button.(s) for program
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
	Button goBack = Button(sf::Vector2f(100, 45), sf::Vector2f(1090.0f, 10.0f), font, "Go Back", 9, 22, sf::Color::Black, sf::Color::Red);
	Button cartButton = Button(sf::Vector2f(125.0f, 45.0f), sf::Vector2f(1065.0f, 10.0f) , font, "Checkout", 9, 22, sf::Color::Black, sf::Color::Red);
	Button addToCart = Button(sf::Vector2f(150.0f, 50.0f), sf::Vector2f(1045.0f, 100.0f) , font, "Add to Cart", 3, 25, sf::Color::Black, sf::Color::Black);
	Button backButton = Button(sf::Vector2f(100.0f, 45.0f), sf::Vector2f(1090.0f, 10.0f) , font, "MENU", 9, 22, sf::Color::Black, sf::Color::Red);

	TextBox customerName;	//Declare customerName TextBox
	TextBox amount;

//While loop that detects if program GUI is open
    while (window.isOpen())
    {

//Vector types to track mouse cursor posisition within window
    	sf::Vector2i mousePos = sf::Mouse::getPosition( window );
    	sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

    	sf::Event event;	//Declare event type


    	if(windowDepth == 0) //Detects if program is within first Frame
    	{
//Loop creates first frame, and detects user input.  In this window, user enters full name.
    	while(window.pollEvent(event) )
    	{
    			switch(event.type)	//Switch statement used to handle different events polled.
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
    								customerName = TextBox(sf::Vector2f(550.0f, 720.0f), erasFont, appendStr("Welcome ", nameBox.getBoxTextStr()), 27, sf::Color::Blue);
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

//Loop renders second frame, detecting user input.  In this window, user will can click displayed button options, and utitlize search bar.
    	while(window.pollEvent(event) )
        {
        	switch(event.type)	//Switch statement used to handle different events polled.
        	{
        		case(sf::Event::Closed):
				{
        			window.close();
        			break;
				}
        		case(sf::Event::MouseButtonPressed):
				{
        			if ( box.clicked( mousePosF) )	//detect if box (search bar) was clicked
        			{
        				std::cout << "Clicked SearchBox" << std::endl;
        				window.clear(sf::Color::White);
        				window.draw(background);
        				window.draw(box.getTextBox());
        				window.draw(box.getBoxText());
        				window.display();
        				std::cout<<box.getBoxTextStr()<<std::endl;
        				while(window.waitEvent(event))
        				{
        					if(event.type == sf::Event::TextEntered)
        					{
        						box.textEntered(event.text.unicode);
        						window.clear(sf::Color::White);
        						window.draw(background);
        						window.draw(box.getTextBox());
        						window.draw(box.getBoxText());
        						window.display();
        						if(event.text.unicode == 13)	//Must have a particular action be a break statement (<enter> key)
        						{
        							if(supermarket.searchEngine(box.getBoxTextStr()))
        								searchFlag = 1;
        							else
        								searchFlag = 2;

        							break;
        						}
        					}
        				}
        			}
        			if(cartButton.clicked(mousePosF))		//if cart is clicked, program jumps to last frame (end frame)
        			{
        				windowDepth = 37;
        				break;
        			}
        			if(produceButton.clicked(mousePosF))	//User may select different produce items
        			{
        				std::cout<<"Produce Button Clicked"<<std::endl;
        				while(window.waitEvent(event))					//Program will rest in this while loop until produce item is selected.
        				{
        					mousePos = sf::Mouse::getPosition( window );
     					    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

     					    supermarket.produceGrid(); //creates produce items grid (sets locations for buttons)

     					    //Draw all the buttons
        			        window.clear(sf::Color::White);
                            window.draw(produceAisles);
                            window.draw(goBack.getButton());
                            window.draw(goBack.getButtonName());
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
        					if(event.type == sf::Event::MouseButtonPressed)	//Checks if button has been pressed
        					{
        						selectedProduce = supermarket.checkProduceButtonPressed(mousePosF);
        						if(selectedProduce != 444)		//Produce item is selected then program is sent to Produce Frame
        						{
        							cnt = 0;
        							windowDepth++;
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(meatsButton.clicked(mousePosF))	//User may select different meat items
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
                            window.draw(goBack.getButton());
                            window.draw(goBack.getButtonName());
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
        					if(event.type == sf::Event::MouseButtonPressed)		//Checks if button has been pressed
        					{
        						selectedMeat = supermarket.checkMeatButtonPressed(mousePosF);
        						if(selectedMeat != 444)							//If meat button pressed, program jumps to Meat Frame
        						{
        							cnt = 0;
        							windowDepth = windowDepth+2;				//equal 3
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}
        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(deliButton.clicked(mousePosF)) 	//User may select different Deli Items
        			{
        				std::cout<<"Deli Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.deliGrid(); //Creates deli items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
                            window.draw(deliAisles);
                            window.draw(goBack.getButton());
                            window.draw(goBack.getButtonName());
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
        							cnt = 0;
        							windowDepth = windowDepth+3;	//equal 4
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(drinksButton.clicked(mousePosF))		//User can select different drink items
        			{
        				std::cout<<"Drinks Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.drinksGrid(); 		//Creates produce items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(drinksAisles);
        					window.draw(goBack.getButton());
        					window.draw(goBack.getButtonName());
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
        						if(selectedDrink != 444)			//If drink button is pressed, program jumps to Drink Frame
        						{
        							cnt = 0;
        							windowDepth = windowDepth+4;	//equal 5
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}

        					}
        					if(windowDepth != 1)
        						break;
        				}
        			}
        			if(bakeryButton.clicked(mousePosF))	//User can select different bakery items
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
        					window.draw(goBack.getButton());
        					window.draw(goBack.getButtonName());
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
        						if(selectedBakery != 444)			// if drink button is selected, program jumps to Bakery Frame
        						{
        							cnt = 0;
        							windowDepth = windowDepth+5;	//equal 6
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}
        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(cosmeticsButton.clicked(mousePosF))	//User can select different cosmetic items
        			{
        				std::cout<<"Cosmetics Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.cosmeticsGrid(); //creates cosmetics items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(cosmeticsAisles);
        					window.draw(goBack.getButton());
        					window.draw(goBack.getButtonName());
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
        						if(selectedCosmetic!= 444)		//if cosmetic item is selected, then program jumps to Cosmetics frame
        						{
        							cnt = 0;
        							windowDepth = windowDepth+6;	//equal 7
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
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

        					supermarket.hygieneGrid(); //creates hygiene items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(hygieneAisles);
        					window.draw(goBack.getButton());
        					window.draw(goBack.getButtonName());
        					for(int i = 0, max = supermarket.amountOfCosmeticsItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getHygieneItem(i).getButton());
        						window.draw(supermarket.getHygieneItem(i).getButtonName());
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
        							cnt = 0;
        							windowDepth = windowDepth+7;	//equal 8
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        							std::cout<<"yep"<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}
        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(pharmacyButton.clicked(mousePosF))		//Detects if Pharmacy button is clicked
        			{
        				std::cout<<"Pharmacy Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.pharmacyGrid(); //creates Pharmacy items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(pharmacyAisles);
        					window.draw(goBack.getButton());
        					window.draw(goBack.getButtonName());
        					for(int i = 0, max = supermarket.amountOfPharmacyItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getPharmacyItem(i).getButton());
        						window.draw(supermarket.getPharmacyItem(i).getButtonName());
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
        							cnt = 0;
        							windowDepth = windowDepth+8;	//equal 9
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}
        					}
        					if(windowDepth != 1)
        						break;
        				}
        			}
        			if(dairyButton.clicked(mousePosF))	//Detects if diary button is pressed
        			{
        				std::cout<<"Dairy Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.dairyGrid(); //creates dairy items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(dairyAisles);
        					window.draw(goBack.getButton());
        					window.draw(goBack.getButtonName());
        					for(int i = 0, max = supermarket.amountOfDairyItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getDairyItem(i).getButton());
        						window.draw(supermarket.getDairyItem(i).getButtonName());
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
        							cnt = 0;
        							windowDepth = windowDepth+9;	//equal 10
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}
        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(grainsButton.clicked(mousePosF))		//Detects if grains button is pressed
        			{
        				std::cout<<"Grains Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.grainsGrid(); //creates grains items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(grainsAisles);
        					window.draw(goBack.getButton());
        					window.draw(goBack.getButtonName());
        					for(int i = 0, max = supermarket.amountOfGrainsItems(); i!=max;++i)
        					{
        						window.draw(supermarket.getGrainsItem(i).getButton());
        						window.draw(supermarket.getGrainsItem(i).getButtonName());
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
        							cnt = 0;
        							windowDepth = windowDepth+10;	//equal 11
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
        						}
        					}
        					if(windowDepth != 1)
        						break;
        				}

        			}
        			if(snacksButton.clicked(mousePosF))		//Detects if snacks button is pressed
        			{
        				std::cout<<"Snacks Button Clicked"<<std::endl;
        				while(window.waitEvent(event))
        				{
        					mousePos = sf::Mouse::getPosition( window );
        					sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

        					supermarket.snacksGrid(); //creates snacks items grid (sets locations for buttons)

        					//Draw all the buttons
        					window.clear(sf::Color::White);
        					window.draw(snacksAisles);
        					window.draw(goBack.getButton());
        					window.draw(goBack.getButtonName());
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
        							cnt = 0;
        							windowDepth = windowDepth+11;	//equal 12
        							std::cout<<"windowDepth: "<<windowDepth<<std::endl;
        						}else if(goBack.clicked(mousePosF)){
        							break;
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
        	//Draws all Buttons, Sprites, and TextBoxes
        	window.clear(sf::Color::White);
        	window.draw(background);
        	window.draw(backdrop);

        	if(searchFlag == 1)
        		window.draw(success.getBoxText());
        	if(searchFlag == 2)
        		window.draw(failure.getBoxText());

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
			//Initializes TextBox.(s) to diplay item information
    		TextBox produceName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getProduceItem(selectedProduce).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox produceType = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Produce"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price Per Llb: $",(std::to_string(supermarket.getProduceItem(selectedProduce).getPricePerLlb())));
    		characterPos = priceUnformatted.find(".");
			priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox producePrice = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    						cnt++;
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

    			//Display all Sprites, Buttons, TextBoxes
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
    			window.draw(amount.getBoxText());
    			window.display();
    		}
    	}

    	//Meat Frame
    	if(windowDepth == 3)
    	    {
			//Initializes TextBox.(s) to display item information
    	    		TextBox meatName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getMeatItem(selectedMeat).getButtonNameStr())), 50, sf::Color::Black);
    	    		TextBox meatType = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Meats"), 35, sf::Color::Black);
    	    		priceUnformatted = appendStr("Price Per Llb: $",(std::to_string(supermarket.getMeatItem(selectedMeat).getPricePerLlb())));
    	    		characterPos = priceUnformatted.find(".");
    				priceFormatted = priceUnformatted.erase(characterPos+3);
    	    		TextBox meatPrice = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    	    		while(window.pollEvent(event) )
    	    		{
    	        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    	    						cnt++;
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

    	    			//Display all Sprites, Buttons, TextBoxes
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
    	    			window.draw(amount.getBoxText());
    	    			window.display();
    	    		}
    	    	}
    	//Render Deli Frame
    	if(windowDepth == 4)
    	{
		//Initializes TextBox.(s) to display item information
    		TextBox deliName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getDeliItem(selectedDeli).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox deliType = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Deli"), 35, sf::Color::Black);
    		priceUnformatted = appendStr("Price Per Llb: $",(std::to_string(supermarket.getDeliItem(selectedDeli).getPricePerLlb())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox deliPricePerPound = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    						cnt++;
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

    			//Display all Sprites, Buttons, TextBoxes
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
    			window.draw(amount.getBoxText());
    			window.display();
    		}
    	}

    	//Render Drinks Frame
    	if(windowDepth == 5)
    	{
    		//Initializes TextBox.(s) to display item information
    		TextBox drinkName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getDrinksItem(selectedDrink).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox drinkAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Drinks"), 35, sf::Color::Black);
    		TextBox drinkCategory = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, appendStr("Category:  ", supermarket.getDrinksItem(selectedDrink).getCategory()), 35, sf::Color::Black);
    		priceUnformatted = appendStr("Price Per Container (8 Oz): $",(std::to_string(supermarket.getDrinksItem(selectedDrink).getPricePerContainer())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox drinkPricePerOz = TextBox(sf::Vector2f(0.0f,150.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    						cnt++;
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
    			//Display all Sprites, Buttons, TextBoxes
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
    			window.draw(amount.getBoxText());
    			window.display();
    		}
    	}

    	//Render Bakery Frame
    	if(windowDepth == 6)
    	{
    		//Initializes TextBox.(s) to display item information
    		TextBox bakeryName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getBakeryItem(selectedBakery).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox bakeryAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Bakery"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price Per Box: $",(std::to_string(supermarket.getBakeryItem(selectedBakery).getPricePerBox())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox bakeryPricePerBox = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    						cnt++;
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
    			//Display all Sprites, Buttons, TextBoxes
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
    			window.draw(amount.getBoxText());
    			window.display();
    		}
    	}

    	//Render Cosmetics Frame
    	if(windowDepth == 7)
    	{
    		//Initializes TextBox.(s) to display item information
    		TextBox cosmeticName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getCosmeticsItem(selectedCosmetic).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox cosmeticAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Cosmetics"), 35, sf::Color::Black);
    		TextBox cosmeticBrand = TextBox(sf::Vector2f(0.0f,95.0f), erasFont, appendStr("Brand: ", supermarket.getCosmeticsItem(selectedCosmetic).getBrand()), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price: $",(std::to_string(supermarket.getCosmeticsItem(selectedCosmetic).getPrice())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox cosmeticPrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    						cnt++;
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
    			//Display all Sprites, Buttons, TextBoxes
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
    			window.draw(amount.getBoxText());
    			window.display();
    		}
    	}

    	//Render Hygiene Frame
    	if(windowDepth == 8)
    	{
    		//Initializes TextBox.(s) to display item information
    		TextBox hygieneName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getHygieneItem(selectedHygiene).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox hygieneAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Hygiene"), 35, sf::Color::Black);
    		priceUnformatted = appendStr("Price: $",(std::to_string(supermarket.getHygieneItem(selectedHygiene).getPricePerUnit())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox hygienePrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    						cnt++;
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
    			//Display all Sprites, Buttons, TextBoxes
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
    			window.draw(amount.getBoxText());
    			window.display();
    		}
    	}

    	//Construct Pharmacy Frame
    	if(windowDepth == 9)
    	{
    		//Initializes TextBox.(s) to display item information
    		TextBox pharmacyName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getPharmacyItem(selectedPharmacy).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox pharmacyAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Pharmacy"), 35, sf::Color::Black);

    		priceUnformatted = appendStr("Price: $",(std::to_string( supermarket.getPharmacyItem(selectedPharmacy).getPricePerCapsules())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox pharmacyPrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    						cnt++;
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
    			//Display all Sprites, Buttons, TextBoxes
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
    			window.draw(amount.getBoxText());
    			window.display();
    		}
    	}

    	//Render Dairy Frame
    	if(windowDepth == 10)
    	{
    		//Initializes TextBox.(s) to display item information
    		TextBox dairyName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getDairyItem(selectedDairy).getButtonNameStr())), 50, sf::Color::Black);
    		TextBox dairyAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Dairy"), 35, sf::Color::Black);
    		TextBox dairyBrand = TextBox(sf::Vector2f(0.0f,90.0f), erasFont, appendStr("Brand: ", (supermarket.getDairyItem(selectedDairy).getBrand())), 35, sf::Color::Black);
    		priceUnformatted = appendStr("Price: $",(std::to_string( supermarket.getDairyItem(selectedDairy).getPrice())));
    		characterPos = priceUnformatted.find(".");
    		priceFormatted = priceUnformatted.erase(characterPos+3);
    		TextBox dairyPrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

    		while(window.pollEvent(event) )
    		{
        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
    						cnt++;
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
    			//Display all Sprites, Buttons, TextBoxes
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
    			window.draw(amount.getBoxText());
    			window.display();
    		}
    	}


    	//Render Grains Frame
    	if(windowDepth == 11)
			{
    			//Initializes TextBox.(s) to display item information
				TextBox grainsName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getGrainsItem(selectedGrains).getButtonNameStr())), 50, sf::Color::Black);
				TextBox grainsAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Grains"), 35, sf::Color::Black);
				TextBox grainsBrand = TextBox(sf::Vector2f(0.0f,90.0f), erasFont, appendStr("Brand: ", (supermarket.getGrainsItem(selectedGrains).getBrand())), 35, sf::Color::Black);
				priceUnformatted = appendStr("Price: $",(std::to_string( supermarket.getGrainsItem(selectedGrains).getPrice())));
				characterPos = priceUnformatted.find(".");
				priceFormatted = priceUnformatted.erase(characterPos+3);
				TextBox grainsPrice = TextBox(sf::Vector2f(0.0f,130.0f), erasFont, priceFormatted, 30, sf::Color::Black);

				while(window.pollEvent(event) )
				{
	        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
								cnt++;
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
	    			//Display all Sprites, Buttons, TextBoxes
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
					window.draw(amount.getBoxText());
					window.display();
				}
			}
    	//Render Snacks Frame
    	if(windowDepth == 12)
			{
			//Initializes TextBox.(s) to display item information
				TextBox snacksName = TextBox(sf::Vector2f(0.0f,0.0f), erasFont, appendStr("Name: ",(supermarket.getSnacksItem(selectedSnacks).getButtonNameStr())), 50, sf::Color::Black);
				TextBox snacksAisle = TextBox(sf::Vector2f(0.0f,60.0f), erasFont, appendStr("Aisle: ","Snacks"), 35, sf::Color::Black);
				priceUnformatted = appendStr("Price: $",(std::to_string( supermarket.getSnacksItem(selectedSnacks).getPrice())));
				characterPos = priceUnformatted.find(".");
				priceFormatted = priceUnformatted.erase(characterPos+3);
				TextBox snacksPrice = TextBox(sf::Vector2f(0.0f,100.0f), erasFont, priceFormatted, 30, sf::Color::Black);

				while(window.pollEvent(event) )
				{
	        		amount = TextBox(sf::Vector2f(900.0f, 160.0f), erasFont, appendStr("Amount in Cart: x", std::to_string(cnt)), 30, sf::Color::Blue);
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
								cnt++;
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
	    			//Display all Sprites, Buttons, TextBoxes
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
					window.draw(amount.getBoxText());
					window.display();
				}
			}

    	//Render Cart Window
    	if(windowDepth == 37)
    	{
			//Initializes TextBox.(s) to display item information
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
//Main Ends
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string appendStr(std::string str1, std::string str2)
{
	return (str1.append(str2));
}

Store::Store(){
}

bool Store::searchEngine(std::string item)
{
	for(int i = 0, max = produceItems.size(); i!=max; ++i)
	{
		if(item.compare( produceItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = meatItems.size(); i!=max; ++i)
	{
		if(item.compare( meatItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = deliItems.size(); i!=max; ++i)
	{
		if(item.compare( deliItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = drinkItems.size(); i!=max; ++i)
	{
		if(item.compare( drinkItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = bakeryItems.size(); i!=max; ++i)
	{
		if(item.compare( bakeryItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = cosmeticsItems.size(); i!=max; ++i)
	{
		if(item.compare( cosmeticsItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = dairyItems.size(); i!=max; ++i)
	{
		if(item.compare( dairyItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = grainsItems.size(); i!=max; ++i)
	{
		if(item.compare( grainsItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = hygieneItems.size(); i!=max; ++i)
	{
		if(item.compare( hygieneItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = pharmacyItems.size(); i!=max; ++i)
	{
		if(item.compare( pharmacyItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}
	for(int i = 0, max = snacksItems.size(); i!=max; ++i)
	{
		if(item.compare( snacksItems.at(i).getButtonNameStr()) == 0 )
			return true;
	}



	return false;
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
    for(int i = 0, max = pharmacyItems.size(); i!=max;++i)
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
	item.setCharacterSize(20);
	item.setColor(sf::Color::Black);

	cartPrice.push_back(cost);

	cartItems.push_back(item);
}

void Store::organizeCartContents()
{
		float x = 350.0f;
		float y = 135.0f;
		int cnt = 0;
		for(int i = 0, max = cartItems.size(); i!=max; ++i )
		{
			cartItems.at(i).setPosition(x, y);
			y+=20.0f;
			cnt++;
			if(cnt == 19)
			{
				cnt = 0;
				x+= 300;
				y = 135.0f;
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
//Constructor
Bakery::Bakery(std::string name, double pricePerBox, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{
		button.setSize(dimensions);
		button.setOutlineThickness(5);
		button.setOutlineColor(sf::Color::Black);

		nameText.setFont(font);
		nameText.setString(initText);
		nameText.setCharacterSize(15);
		nameText.setColor(sf::Color::Black);

		this->pricePerBox = pricePerBox;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Bakery  Class
void Bakery::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Bakery::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Bakery::getButton()
{
	return this -> button;
}

sf::Text Bakery::getButtonName()
{
	return this -> nameText;
}

bool Bakery::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Bakery::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

double Bakery::getPricePerBox()
{
	return this -> pricePerBox;
}
std::string Bakery::getName()
{
	return this -> name;
}

sf::Text Bakery::getPPBText()						//get pricePerLlb value in sf::Text form
{
	return this ->pricePerBoxText;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
Button::Button(sf::Vector2f dimensions, sf::Vector2f location, sf::Font &font, std::string initText, int boxThickness, int characterSize, sf::Color colorText, sf::Color colorBoxOutline)
{
	button.setSize(dimensions);
	button.setPosition(location);
	button.setOutlineThickness(boxThickness);
	button.setOutlineColor(colorBoxOutline);

	nameText.setPosition(location.x + 8, location.y + 8);
	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(characterSize);
	nameText.setColor(colorText);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Button  Class
void Button::changePosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Button::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Button::getButton()
{
	return this -> button;
}

sf::Text Button::getButtonName()
{
	return this -> nameText;
}

bool Button::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR
Cosmetics::Cosmetics (std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), brand(brand){

	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this->price = price; // set Price

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Cosmetics  Class
void Cosmetics::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Cosmetics::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Cosmetics::getButton()
{
	return this -> button;
}

sf::Text Cosmetics::getButtonName()
{
	return this -> nameText;
}
bool Cosmetics::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Cosmetics::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

std::string Cosmetics::getBrand(){
	return this->brand;
}

double Cosmetics::getPrice()
{
	return this->price;
}

std::string Cosmetics::getName()
{
	return this->name;
}


std::string Cosmetics::getButtonBrandStr()
{
	return this -> brand;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// CONSTRUCTOR
Dairy::Dairy(std::string name, std::string brand, double price, sf::Vector2f dimensions, sf::Font &font, std::string initText):name(name), brand(brand)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this -> price = price;
	this -> brandText.setString(brand);
	this -> priceText.setString( std::to_string(price));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Dairy  Class
void Dairy::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Dairy::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Dairy::getButton()
{
	return this -> button;
}

sf::Text Dairy::getButtonName()
{
	return this -> nameText;
}

bool Dairy::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Dairy::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

std::string Dairy::getBrand()
{
	return this -> brand;
}

double Dairy::getPrice()
{
	return this -> price;
}

std::string Dairy::getName()
{
	return this -> name;
}

sf::Text Dairy::getPriceText()						//get pricePerLlb value in sf::Text form
{
	return this ->priceText;
}

sf::Text Dairy::getBrandText()
{
	return this -> brandText;
}

std::string Dairy::getButtonBrandStr()
{
	return this -> brand;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// CONSTRUCTOR
Deli::Deli(std::string name, double pricePerLlb, double pricePerUnit, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{
    button.setSize(dimensions);
    button.setOutlineThickness(5);
    button.setOutlineColor(sf::Color::Black);

    nameText.setFont(font);
    nameText.setString(initText);
    nameText.setCharacterSize(15);
    nameText.setColor(sf::Color::Black);

    this->pricePerLlb = pricePerLlb;
    this->pricePerUnit = pricePerUnit;

    this -> pricePerLlbText.setString( std::to_string(pricePerLlb) );
    this -> pricePerUnitText.setString( std::to_string(pricePerUnit) );


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Deli  Class
void Deli::changeButtonPosition(float x, float y)
{
    button.setPosition(x, y);
}

std::string Deli::getButtonNameStr()
{
    return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Deli::getButton()
{
    return this -> button;
}

sf::Text Deli::getButtonName()
{
    return this -> nameText;
}

bool Deli::clicked(sf::Vector2f mousePosF)
{
    if(button.getGlobalBounds().contains(mousePosF))
    {
        return true;
    }else{
        return false;
    }
}

void Deli::changeTextPosition(float x, float y)
{
    nameText.setPosition(x, y);
}


double Deli::getPricePerLlb()
{
    return this -> pricePerLlb;
}

double Deli::getPricePerUnit()
{
    return this -> pricePerUnit;
}

sf::Text Deli::getPPPText()						//get pricePerLlb value in sf::Text form
{
    return this ->pricePerLlbText;
}

sf::Text Deli::getPPUText()						//get pricePerLlb value in sf::Text form
{
    return this ->pricePerUnitText;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// CONSTRUCTOR
Drinks::Drinks (std::string name, std::string category, double pricePerContainer, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), category(category)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this->pricePerContainer = pricePerContainer;
	this ->quantity = 100;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Drinks  Class
void Drinks::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Drinks::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Drinks::getButton()
{
	return this -> button;
}

sf::Text Drinks::getButtonName()
{
	return this -> nameText;
}

bool Drinks::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Drinks::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}


double Drinks::getPricePerContainer()
{
	return this->pricePerContainer;
}

std::string Drinks::getName()
{
	return this -> name;
}

std::string Drinks::getCategory()
{
	return this->category;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Constructor
Grains::Grains(std::string name, std::string brand, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), brand(brand)
{
    button.setSize(dimensions);
    button.setOutlineThickness(5);
    button.setOutlineColor(sf::Color::Black);

    nameText.setFont(font);
    nameText.setString(initText);
    nameText.setCharacterSize(15);
    nameText.setColor(sf::Color::Black);

    this -> price = price;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Grains  Class
void Grains::changeButtonPosition(float x, float y)
{
    button.setPosition(x, y);
}

std::string Grains::getButtonNameStr()
{
    return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Grains::getButton()
{
    return this -> button;
}

sf::Text Grains::getButtonName()
{
    return this -> nameText;
}

bool Grains::clicked(sf::Vector2f mousePosF)
{
    if(button.getGlobalBounds().contains(mousePosF))
    {
        return true;
    }else{
        return false;
    }
}

void Grains::changeTextPosition(float x, float y)
{
    nameText.setPosition(x, y);
}

std::string Grains::getBrand()
{
    return this -> brand;
}

double Grains::getPrice()
{
    return this -> price;
}

std::string Grains::getName()
{
    return this -> name;
}

std::string Grains::getButtonBrandStr()
{
    return this -> brand;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Constructor
Hygiene::Hygiene(std::string name, double pricePerUnit, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{
    button.setSize(dimensions);
    button.setOutlineThickness(5);
    button.setOutlineColor(sf::Color::Black);

    nameText.setFont(font);
    nameText.setString(initText);
    nameText.setCharacterSize(15);
    nameText.setColor(sf::Color::Black);

    this -> pricePerUnit = pricePerUnit;
    this -> supermarketQuantity = 100;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Hygiene  Class
void Hygiene::changeButtonPosition(float x, float y)
{
    button.setPosition(x, y);
}

std::string Hygiene::getButtonNameStr()
{
    return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Hygiene::getButton()
{
    return this -> button;
}

bool Hygiene::clicked(sf::Vector2f mousePosF)
{
    if(button.getGlobalBounds().contains(mousePosF))
    {
        return true;
    }else{
        return false;
    }
}

void Hygiene::changeTextPosition(float x, float y)
{
    nameText.setPosition(x, y);
}

double Hygiene::getPricePerUnit()
{
    return this -> pricePerUnit;
}

std::string Hygiene::getName()
{
    return this -> name;
}

sf::Text Hygiene::getButtonName()
{
	return this -> nameText;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Constructor
Meats::Meats(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), type(type)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this -> pricePerLlb = pricePerLlb;
	this -> supermarketQuantity = 100;

	this -> typeText.setString(type);

	this -> pricePerLlbText.setString( std::to_string(pricePerLlb) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Meats  Class
void Meats::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Meats::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Meats::getButton()
{
	return this -> button;
}

sf::Text Meats::getButtonName()
{
	return this -> nameText;
}

bool Meats::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Meats::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

std::string Meats::getType()
{
	return this -> type;
}

double Meats::getPricePerLlb()
{
	return this -> pricePerLlb;
}

std::string Meats::getName()
{
	return this -> name;
}

sf::Text Meats::getPPPText()						//get pricePerLlb value in sf::Text form
{
	return this ->pricePerLlbText;
}

sf::Text Meats::getTypeText()
{
	return this -> typeText;
}

std::string Meats::getButtonTypeStr()
{
	return this -> type;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// CONSTRUCTOR
Pharmacy::Pharmacy(std::string name, double pricePerCapsules,  sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{

	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this->pricePerCapsules = pricePerCapsules;

	this -> pricePerCapsulesText.setString( std::to_string(pricePerCapsules) );

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Pharmacy  Class
void Pharmacy::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

void Pharmacy::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}


// GETTERS
std::string Pharmacy::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Pharmacy::getButton()
{
	return this -> button;
}

sf::Text Pharmacy::getButtonName()
{
	return this -> nameText;
}

bool Pharmacy::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

double Pharmacy::getPricePerCapsules()
{
	return this -> pricePerCapsules;
}

std::string Pharmacy::getName()
{
	return this -> name;
}

sf::Text Pharmacy::getPPCText()						//get pricePerLlb value in sf::Text form
{
	return this ->pricePerCapsulesText;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
Produce::Produce(std::string name, std::string type, double pricePerLlb, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name), type(type)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this -> pricePerLlb = pricePerLlb;
	this -> supermarketQuantity = 100;

	this -> typeText.setString(type);

	this -> pricePerLlbText.setString( std::to_string(pricePerLlb) );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Produce  Class
void Produce::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Produce::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Produce::getButton()
{
	return this -> button;
}

sf::Text Produce::getButtonName()
{
	return this -> nameText;
}

bool Produce::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Produce::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

std::string Produce::getType()
{
	return this -> type;
}

double Produce::getPricePerLlb()
{
	return this -> pricePerLlb;
}

std::string Produce::getName()
{
	return this -> name;
}

sf::Text Produce::getPPPText()						//get pricePerLlb value in sf::Text form
{
	return this ->pricePerLlbText;
}

sf::Text Produce::getTypeText()
{
	return this -> typeText;
}

std::string Produce::getButtonTypeStr()
{
	return this -> type;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructor
Snacks::Snacks(std::string name, double price, sf::Vector2f dimensions,  sf::Font &font, std::string initText):name(name)
{
	button.setSize(dimensions);
	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color::Black);

	nameText.setFont(font);
	nameText.setString(initText);
	nameText.setCharacterSize(15);
	nameText.setColor(sf::Color::Black);

	this -> price = price;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for Snacks  Class
void Snacks::changeButtonPosition(float x, float y)
{
	button.setPosition(x, y);
}

std::string Snacks::getButtonNameStr()
{
	return this -> nameText.getString().toAnsiString();
}

sf::RectangleShape Snacks::getButton()
{
	return this -> button;
}

sf::Text Snacks::getButtonName()
{
	return this -> nameText;
}

bool Snacks::clicked(sf::Vector2f mousePosF)
{
	if(button.getGlobalBounds().contains(mousePosF))
	{
		return true;
	}else{
		return false;
	}
}

void Snacks::changeTextPosition(float x, float y)
{
	nameText.setPosition(x, y);
}

double Snacks::getPrice()
{
	return this -> price;
}

std::string Snacks::getName()
{
	return this -> name;
}

sf::Text Snacks::getPriceText()						//get pricePerLlb value in sf::Text form
{
	return this ->priceText;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Constructor
TextBox::TextBox(){}

//Constructor
TextBox::TextBox(sf::Vector2f location, sf::Font &font, std::string text, int characterSize, sf::Color color)		//No box
{
	boxText.setPosition(location.x, location.y);
	boxText.setFont(font);
	boxText.setString(text);
	boxText.setCharacterSize(characterSize);
	boxText.setColor(color);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setter/Getter Methods for TextBox  Class
TextBox::TextBox(sf::Vector2f dimensions, sf::Vector2f location, int outlineThickness, sf::Font &font,std::string initText )
{
	textBox.setSize(dimensions);
	textBox.setPosition(location);
	textBox.setOutlineThickness(outlineThickness);
	textBox.setOutlineColor(sf::Color::Black);

	boxText.setPosition(location.x + 2, location.y + 8);
	boxText.setFont(font);
	boxText.setString(initText);
	boxText.setCharacterSize(25);
	boxText.setColor(sf::Color::Red);
}


void TextBox::changePosition(float x, float y)
{
	textBox.setPosition(x, y);
}

sf::RectangleShape TextBox::getTextBox()
{
	return this->textBox;
}

sf::Text TextBox::getBoxText()
{

	return this -> boxText;
}


std::string TextBox::getBoxTextStr()
{
	return this -> boxText.getString().toAnsiString();
}



bool TextBox::clicked(sf::Vector2f mousePosF)
{
	if(textBox.getGlobalBounds().contains(mousePosF ))
	{
		boxInput.clear();
		boxText.setString(boxInput);
		return true;
	}else{
	return false;
	}
}

void TextBox::textEntered(sf::Uint32 unicode)
{
	if(unicode<123 && unicode > 31 && (boxText.getLocalBounds().width < textBox.getLocalBounds().width - 25))	//Take in characters
	{
		boxInput += unicode;
		boxText.setString(boxInput);
		boxTextStr = boxText.getString().toAnsiString();
	}
	if(unicode == 8)
	{
		boxTextStr = boxText.getString().toAnsiString();
		if(boxTextStr.size() > 0)
		 {
			boxTextStr = boxText.getString().toAnsiString();
			boxTextStr.pop_back();
			boxText.setString(boxTextStr);
			boxInput.erase(boxInput.getSize()-1, 1);
		 }
	}
	if(unicode == 13)
	{
		boxTextStr = boxText.getString().toAnsiString();
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
