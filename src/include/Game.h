
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ResourcePath.hpp"
#include "include/debug.h"
#elif _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
//#include "include/debug.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/debug.h"
#endif
#include <vector>

#include "Script.h"

class GameGEVN
{
public:
	//void handleInput(sf::Event e);
	//void render(sf::RenderWindow& window);
	//void update();
	GameGEVN();
	Start();
	void NextStatement(std::string command, const char* content);
	LoadScript(std::string fileName, std::vector<std::string> & vecOfStrs);

private:
	//ConfigOptions opts;
	std::string root;
    SDL_Texture * BackgroundTexture;

	//sf::Music music;

	//sf::Texture backgroundTex;
	//sf::Sprite background;

	//sf::RectangleShape fadeRect;
	int fade; // if it is fade out, then fade < 0, if fade in - fade > 0

	//sf::RectangleShape textRect;
	//sf::RectangleShape test;

	//sf::Text text;
	//sf::Font textFont;

	//sf::Clock textClock;
	//sf::Clock delayClock;

	std::wstring textStr;
	bool hasPrintedText;
	std::string::size_type textPos;


	int delay;

	bool hideText;
	bool fadeOn;

	bool debug;
};
