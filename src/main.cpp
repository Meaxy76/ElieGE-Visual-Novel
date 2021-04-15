#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iomanip>
#include <iostream>



void PlayMusic()
{
    // Load an ogg music file
    sf::Music Music;
    if (!Music.openFromFile("sound/test1.wav"))
        return;

    // Play it
    Music.play();

    // Loop while the music is playing
    std::cout << std::endl;
}


int main()
{   
        
        sf::RenderWindow window(sf::VideoMode(1920, 1080), "ElieGE Visual Novel ",sf::Style::Fullscreen);
        // Load background
        sf::Image image;
        if (!(image.loadFromFile("scenes/background/backtest.png")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture;
        texture.loadFromImage(image);  //Load Texture from image

        sf::Sprite sprite;
        sprite.setTexture(texture);  

        // load Aiko 

        sf::Image image1;
        if (!(image1.loadFromFile("characters/Aiko/aiko1.png")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture1;
        texture1.loadFromImage(image1);  //Load Texture from image

        sf::Sprite sprite1;
        sprite1.setTexture(texture1);      
        sprite1.setPosition(100,367);

        // Load Kaori

        sf::Image image2;
        if (!(image2.loadFromFile("characters/Kaori/kaori.png")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture2;
        texture2.loadFromImage(image2);  //Load Texture from image

        sf::Sprite sprite2;
        sprite2.setTexture(texture2);
        sprite2.setPosition(-200,367);

        // Load Elie

                sf::Image image3;
        if (!(image3.loadFromFile("characters/Mikie/mikie.png")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture3;
        texture3.loadFromImage(image3);  //Load Texture from image

        sf::Sprite sprite3;
        sprite3.setTexture(texture3);
        sprite3.setPosition(1020,630);

        // Load Mitsuki

                sf::Image image4;
        if (!(image4.loadFromFile("characters/Mitsuki/mitsuki.png")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture4;
        texture4.loadFromImage(image4);  //Load Texture from image

        sf::Sprite sprite4;
        sprite4.setTexture(texture4);
        sprite4.setPosition(600,450);

        // Load music

        PlayMusic();
                 

        // sf::SoundBuffer buffer;
         // if (!buffer.loadFromFile("sound/test1.wav"))
               // return -1;
        // sf::Sound sound;
        // sound.setBuffer(buffer);
        // sound.play();

        while (window.isOpen())
        {

       
                sf::Event event;
                
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();
                        
                        }//Event handling done
                        

                for (int i = 0; i < 1024; i++)
                {
                        for (int j = 0; j < 768; j++)
                                image.setPixel(i, j, sf::Color::Black);
                }

                window.clear();
                window.draw(sprite);
                window.draw(sprite3); 
                window.draw(sprite1);
                window.draw(sprite4); 
                window.draw(sprite2); 
                
                window.display();
                }


        return 0;
}

