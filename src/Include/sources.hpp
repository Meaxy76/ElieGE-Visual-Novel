 #pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <SFML/Graphics.hpp>

#include "Include/debug.h"
//#include "Include/Utility.h"

using namespace std;

#define SOURCES Sources::GetSources()

//class ScriptManager;
class Sources {
public:

	// Define all the global variables to be passed between states
	//std::string selectedLoadFile = NewGameScriptFileLocation;
	
	const std::string ResourceRoot = "resources/";
	const std::string ImageRoot = "Content/";
	const std::string AssetRoot = ImageRoot + "assets/";

	const std::string SoundRoot = "sound/";
	const std::string MusicRoot = SoundRoot + "music/";

	const std::string TextBoxLocation = ImageRoot + "textbox/textboxMaster.png";
	const std::string TextBoxColorLocation = ResourceRoot + "TextboxColors.csv";
	const std::string NewGameScriptFileLocation = ResourceRoot + "ScriptLine.csv";

	std::string DisplayTextFont = ResourceRoot + "default.ttf";	// might make it changeable
	const std::string DisplayNameFont = ResourceRoot + "MATURASC.TTF";
	const std::string UserInterfaceFont = ResourceRoot + "default.TTF";
	const std::string UserInterfaceButtonFont = ResourceRoot + "MATURASC.TTF";
	const std::string ConfirmationPromptFont = ResourceRoot + "Alice.ttf";

	const std::string blurFragShaderPath = "resources/blur.frag";

	//std::string playerName;

	//bool autoMode = false;
	//bool skipMode = false;
	//bool ctrlSkipMode = false;

	//sf::RenderWindow* windowPtr = nullptr;
	//ScriptManager* scriptManagerPtr = nullptr;

	//sf::Color choiceboxColorSelected = sf::Color(255, 20, 150, 190);
	//sf::Color choiceboxColorUnselected = sf::Color(180, 0, 80, 190);

	//sf::Color getTextboxColor(const std::string& name);

	static Sources* GetSources();
	static void CleanUp();

private:
	Sources();
	~Sources();

	//void initTextboxColors(const std::string& filename);

	//std::map<std::string, sf::Color> textBoxColors;
	static Sources * sources_ptr;
};
