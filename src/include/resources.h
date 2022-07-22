 #pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>

//#include "Include/debug.h"
//#include "Include/Utility.h"

using namespace std;

#define RESOURCES Resources::GetResources()

//class ScriptManager;
class Resources {
public:
	
	const std::string Root = "Content/";
	const std::string ResourceRoot = Root + "Resources/";
	const std::string ScriptRoot = ResourceRoot + "Scripts/";
	const std::string ConfigRoot = ResourceRoot + "Configs/";
	const std::string AssetRoot = ResourceRoot + "Assets/";
	const std::string CharactersRoot = AssetRoot + "Characters/";
	const std::string BackRoot = AssetRoot + "Backgrounds/";
	const std::string SplashRoot = AssetRoot + "Splash/";
	const std::string FontRoot = AssetRoot + "Fonts/";

	const std::string TrackRoot = AssetRoot + "Tracks/";
	const std::string MusicRoot = AssetRoot + "music/";

	static Resources* GetResources();
	static void CleanUp();

private:
	Resources();
	//~Resources();
	static Resources * resources_ptr;
};