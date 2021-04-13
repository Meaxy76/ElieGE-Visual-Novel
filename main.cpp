#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{   
        
        sf::RenderWindow window(sf::VideoMode(1024, 768), "ElieGE Visual Novel ");
        
        sf::Image image;
        if (!(image.loadFromFile("scenes/background/backtest.png")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture;
        texture.loadFromImage(image);  //Load Texture from image

        sf::Sprite sprite;
        sprite.setTexture(texture);  

        sf::Image image1;
        if (!(image1.loadFromFile("characters/Aiko/aiko1.png")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture1;
        texture1.loadFromImage(image1);  //Load Texture from image

        sf::Sprite sprite1;
        sprite1.setTexture(texture1);      
        sprite1.setPosition(100,45);

        sf::Image image2;
        if (!(image2.loadFromFile("characters/Kaori/kaori.png")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture2;
        texture2.loadFromImage(image2);  //Load Texture from image

        sf::Sprite sprite2;
        sprite2.setTexture(texture2);
        sprite2.setPosition(-200,45);
 

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
                window.draw(sprite1);
                window.draw(sprite2);
                window.display();
                }


        return 0;
}

