#include "Include/button.hpp"
#include "include/debug.h"

bool Button::onLoad()
{
	if (!texture.loadFromFile(texPath))
	{
		DEBUG->Log("Button", "Error loading button texture");
		return false;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setPosition(xPos, yPos);
	texWidth = sprite.getLocalBounds().width;
	texHeight = sprite.getLocalBounds().height;
	hasShader = false;
	pressed = false;
	clicked = false;
	hovered = false;

	if (vertShaderPath != "" && fragShaderPath != "")
	{
		if (!shader.loadFromFile(vertShaderPath, fragShaderPath))
		{
			DEBUG->Log("Button", "Error loading vert/frag shaders");
		}
		else
		{
			hasShader = true;
		}
	}
	else if (vertShaderPath != "")
	{
		if (!shader.loadFromFile(vertShaderPath, sf::Shader::Vertex))
		{
			DEBUG->Log("Button", "Error loading vert shader");
		}
		else
		{
			hasShader = true;
		}
	}
	else if (fragShaderPath != "")
	{
		if (!shader.loadFromFile(fragShaderPath, sf::Shader::Fragment))
		{
			DEBUG->Log("Button", "Error loading frag shader");
		}
		else
		{
			hasShader = true;
		}
	}

	return true;
}

void Button::onUpdate(float delta_t)
{
}

void Button::onDraw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (hasShader)
	{
		states.shader = &shader;
	}

	target.draw(sprite, states);
}

void Button::onHandleInput(sf::Event & e, sf::RenderWindow & window)
{
}

sf::Texture& Button::getTexure()
{
	return texture;
}

sf::Sprite& Button::getSprite()
{
	return sprite;
}

bool Button::isPressed(bool reset)
{
	bool temp = pressed;
	if (reset) pressed = false;
	return temp;
}

bool Button::isClicked(bool reset)
{
	bool temp = clicked;
	if (reset) clicked = false;
	return temp;
}

void Button::move(float x, float y)
{
	this->xPos += x;
	this->yPos += y;
	sprite.setPosition(xPos, yPos);
}
