//#include "Include/sources.hpp"
//#include "Include/button.hpp"
#include "Include/mainmenubtn.hpp"
#include <SFML/graphics.hpp>
//#include "include/debug.h"
using namespace std;


void MenuButtonLOL::init()
{
	configButton = new Button(SOURCES->AssetRoot + "icon/icon.png", "", "", 0, 0);
    DEBUG->Log("BOUTON CHARGER");  
	configButton->load();
    
}

void MenuButtonLOL::handleInput(sf::Event & e, sf::RenderWindow & window)
{
	for (Button* button : buttons)
	{
		button->handleInput(e, window);
	}
}



void MenuButtonLOL::cleanup()
{
	for (Button* button : buttons)
	{
		delete button;
	}
	buttons.clear();
}


void MenuButtonLOL::render(sf::RenderWindow* window)
{
	for (Button* button : buttons)
	{
		window->draw(*button);
        
        DEBUG->Log("BOUTON CREER"); 
     
	}
}


void MenuButtonLOL::update(float delta_t)
{
	for (Button* button : buttons)
	{
		button->update(delta_t);
	}
}


MenuButtonLOL::MenuButtonLOL()
{
	init();
}

MenuButtonLOL::~MenuButtonLOL()
{
	cleanup();
}