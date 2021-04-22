#include "Include/button.hpp"

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