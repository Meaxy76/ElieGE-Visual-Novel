//
//  game.cpp
//  ElieGE Visual Novel
//
//  Created by Meaxy Kusama on 21-04-19.
//  Copyright © 2021 Meaxy Kusama. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//#include "ResourcePath.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void game()
{
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ElieGE Visual Novel",sf::Style::Fullscreen);    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("scenes/background/stars.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    
    
    sf::Texture texture1;
    if (!texture1.loadFromFile("scenes/menu/test1.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite1(texture1);
    
    sf::Texture texture2;
    if (!texture2.loadFromFile("scenes/logo/test.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite2(texture2);
    
    sf::Texture texture3;
    if (!texture3.loadFromFile("characters/Aiko/aiko1.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite3(texture3);
    sprite3.setPosition(400,367);
    
    sf::Texture texture4;
    if (!texture4.loadFromFile("characters/Kaori/kaori.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite4(texture4);
    sprite4.setPosition(150,367);
    
    sf::Texture texture5;
    if (!texture5.loadFromFile("characters/Mikie/mikie.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite5(texture5);
    sprite5.setPosition(1270,630);
    
    
    sf::Texture texture6;
    if (!texture6.loadFromFile("characters/Mitsuki/mitsuki.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite6(texture6);
    sprite6.setPosition(900,450);
    
    sf::Font font;
    if (!font.loadFromFile("font/weigl.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Minasan, ohayo!", font, 25);
    text.setFillColor(sf::Color::Black);
    text.setPosition(190,450);
    
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound/happy.wav"))
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    
    while (window.isOpen())
    {
        
        
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }//Event handling done
        
        
        window.clear();
        window.draw(sprite);  // Background
        window.draw(sprite1); // Menu bar
        window.draw(sprite2); // Logo
        window.draw(sprite3); // Aiko
        window.draw(sprite4); // Kaori
        window.draw(sprite5); // Mikie
        window.draw(sprite6); // Mitsuki (Devse-chan)
        window.draw(text); // Custom text
        window.display();
    }
    
}
