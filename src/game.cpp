
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
#include <stdio.h>
#include "include/SDL_Base.h"
#include "include/Script.h"
#include "include/Button.h"
#include "include/media.h"
#include "include/SmartPhone.h"
int init();
int MainMenu();

int game()
{
    init();
    bool running = true;
    //double delta = .0001;
    //double TimeClock = SDL_GetTicks();

    while (running){
        //delta = (SDL_GetTicks() - TimeClock)/1000;
        //TimeClock = SDL_GetTicks();
        MainMenu();
    }

    SDL_Quit();
    return 0;
}