
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ResourcePath.hpp"
#include "include/debug.h"
#elif _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "../include/debug.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/debug.h"
#endif
#include "../include/Game.h"
#include "../include/Script.h"
#include "../include/SDL_Base.h"
#include "../include/resources.h"
#include "../include/dialog.h"
#include "../include/SmartPhone.h"
#include "../include/Media.h"
#include "../include/Mouse.h"
#include "../include/Event.h"
SDL_Texture * BackgroundTexture;
void Command(std::string cmd);
SmartPhone phone;
MediaGEVN media;
Dialogbox dialog;

bool PhoneAction = true;

GameGEVN::GameGEVN(){

}

GameGEVN::Start(){
    printf("And in this?\n");
	std::vector<std::string> vecOfStr;
    // Get the contents of file in a vector
    bool result = LoadScript("Content/Resources/Scripts/script.gevn", vecOfStr);
    if(result)
    {
        // Print the vector contents


        for(std::string & line : vecOfStr){
			//dialog.DialogUpdate();
            Command(line);

		}
            //std::cout<<line<<std::endl;
    }
		//dialog.DialogDraw();
}
//Normally should be in VNScript.cpp
GameGEVN::LoadScript(std::string fileName, std::vector<std::string> & vecOfStrs){
    std::ifstream in(fileName.c_str());
	dialog.DialogUpdate();
    // Check if object is valid
    if(!in)
    {
        std::cerr << "Cannot open the File : "<<fileName<<std::endl;
        return false;
    }
    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0)
            vecOfStrs.push_back(str);
    }
    //Close The File
    in.close();
    return true;
}


void GameGEVN::NextStatement(std::string command, const char* content){
	if(command == "background"){
		std::string str = std::string(RESOURCES->BackRoot) + content; // ok
        const char* pathback = str.c_str();
        SDL_Texture* BackGround = IMG_LoadTexture(renderer, pathback);
        SDL_RenderCopy(renderer, BackGround, NULL,NULL);
        SDL_RenderPresent(renderer);
		return;
	}
	if(command == "text"){
        //SDL_Texture* BackGround = IMG_LoadTexture(renderer, content);
        //SDL_RenderCopy(renderer, BackGround, NULL,NULL);
        //SDL_RenderPresent(renderer);
        //SDL_RenderClear(renderer);
		//dialog.DialogUpdate();
		//dialog.dialog_text(content);
		printf("%s", content);
        SDL_RenderPresent(renderer);
		MySleep(5000);
	}
	if(command == "phone"){
        //SDL_Texture* BackGround = IMG_LoadTexture(renderer, content);
        //SDL_RenderCopy(renderer, BackGround, NULL,NULL);
		phone.SmartPhoneOpen();
		phone.SmartPhoneDraw();
		//phone.IncommingCall();
		phone.PhoneOS();
		//SmartPhone Dialer;
    	//Dialer.PhoneOSSource.y = 50;
    	//Dialer.PhoneOSDest.y = 0;
    	//Dialer.PhoneOSDest.x = 0;

		//	SmartPhone Contacts;
    	//	Contacts.PhoneOSSource.y = 0;
    	//	Contacts.PhoneOSDest.y = 10;
    	//	Contacts.PhoneOSDest.x = 10;
		//	phone.PhoneOSUpdate();
		//	phone.PhoneOSDraw();
        //SDL_RenderPresent(renderer);

		//SmartPhone Contacts;
    	//Contacts.PhoneOSSource.y = 0;
    	//Contacts.PhoneOSDest.y = 50;
    	//Contacts.PhoneOSDest.x = 100;
		


		//phone.PhoneOSRender();

        SDL_RenderPresent(renderer);
	}
	if(command == "character"){
        //SDL_Texture* charac = IMG_LoadTexture(renderer, content);
        //SDL_RenderCopy(renderer, charac, NULL,NULL);
        SDL_RenderPresent(renderer);
	}
	if(command == "actor"){
		std::string str2 = std::string(RESOURCES->CharactersRoot) + content; // ok
        const char* pathactor = str2.c_str();
        SDL_Texture* Actor = IMG_LoadTexture(renderer, pathactor);
        SDL_RenderCopy(renderer, Actor, NULL,NULL);
        SDL_RenderPresent(renderer);
	}
	if(command == "track"){
		media.load_sound(RESOURCES->TrackRoot + content);
       // SDL_Texture* Actor = IMG_LoadTexture(renderer, content);
       // SDL_RenderCopy(renderer, Actor, NULL,NULL);
       // SDL_RenderPresent(renderer);
	}
		//NextStatement();
		//return;

}

void update(SDL_Renderer* renderer){
    SDL_RenderPresent(renderer);
}