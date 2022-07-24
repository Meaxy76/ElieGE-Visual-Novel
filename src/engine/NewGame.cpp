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
#include "../include/SDL_Base.h"
#include "../include/resources.h"
#include "../include/media.h"
#include "../include/Mouse.h"
#include "../include/Game.h"
#include "../include/SmartPhone.h"
#include "../include/dialog.h"
#include "../include/ElieGEVN.h"
#include "../include/Script.h"

ElieEngine::NewGame()
{
    Mouse mouse;
    bool Play = true;
    SmartPhone phone;
    MediaGEVN Media;
    GameGEVN game;
    Dialogbox diag;


	//Error check
//	printf("test here\n");
//	if (!script.open(RESOURCES->ScriptRoot + "script.gevn")) {
//		DEBUG->Log("ERROR: script file cannot be opened!");
//		return 1;
//	}

//	statements = script.parse();
    //Song = Media.load_sound("NightSky.wav");
    printf("And there?\n");
//	GameGEVN gamegevn(&statements);
    game.Start();
    diag.DialogUpdate();
    //diag.DialogDraw();

    while(Play){
        mouse.MouseUpdate();
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                    //running = false;
                    SDL_Quit();
            }
            
        }// end loop
        
        update(renderer);
    // Oh my we are starting a new game!
    // after we load the  first script and start new songs


    }
        

}