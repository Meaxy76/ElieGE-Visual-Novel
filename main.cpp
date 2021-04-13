#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{   
        
        sf::RenderWindow window(sf::VideoMode(1024, 768), "ElieGE Visual Novel ");
        
        sf::Image image;
        if (!(image.loadFromFile("characters/kaori2.JPG")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture;
        texture.loadFromImage(image);  //Load Texture from image

        sf::Sprite sprite;
        sprite.setTexture(texture);    


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
                window.display();
                }


        return 0;
}

