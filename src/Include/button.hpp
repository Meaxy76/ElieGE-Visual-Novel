#pragma once


#include "Include/EEffect.hpp"
#include <string>



class Button : public EEffect
{
public:
	// in case there's no frag shader or vert shader, just pass in empty string "" respectively
	Button(std::string texPath, std::string vertShaderPath, 
		std::string fragShaderPath, float xPos, float yPos) :
		EEffect("Button")
	{
		this->texPath = texPath;
		this->xPos = xPos;
		this->yPos = yPos;
		this->vertShaderPath = vertShaderPath;
		this->fragShaderPath = fragShaderPath;
	}

	sf::Texture& getTexure();
	sf::Sprite& getSprite();
	bool isPressed(bool reset);
	bool isClicked(bool reset);
	void move(float x, float y);

	float xPos, yPos;
	int texWidth, texHeight;		// actual texture width and height


protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Shader shader;

	std::string texPath;
	std::string vertShaderPath;
	std::string fragShaderPath;
	bool hasShader;

	bool pressed;	// if the button is currently being pressed
	bool clicked;	// if the button is being clicked (fully pressed then released)
	bool hovered;	// if the button is hovered

	bool onLoad();
	void onUpdate(float delta_t);
	void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
	void onHandleInput(sf::Event&e, sf::RenderWindow& window);

};