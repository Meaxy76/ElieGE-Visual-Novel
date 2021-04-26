#pragma once
#include "Include/sources.hpp"
#include "Include/button.hpp"
#include "Include/mainmenubtn.hpp"
#include "include/debug.h"

class MenuButtonLOL
{
public:

     void handleInput(sf::Event& e, sf::RenderWindow& window);
     void render(sf::RenderWindow& window);
     void update(float delta_t);	
     void init();
	 void cleanup();
     MenuButtonLOL();
	 ~MenuButtonLOL();


private:

	Button * configButton;

    vector<Button*> buttons;

};

