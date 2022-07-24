#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ResourcePath.hpp"
#include "include/debug.h"
#elif _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "Include/SDL_ttf.h"
//#include "include/debug.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/debug.h"
#endif
#include <stdio.h>
#include "../include/SDL_Base.h"
SDL_Window * window = NULL;
SDL_Renderer* renderer = NULL;

int init(){
    TTF_Init();
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    window = SDL_CreateWindow("Heroes of the Aura",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1366,768,SDL_WINDOW_OPENGL);
    IMG_Init(IMG_INIT_PNG);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Renderer* SDL_GetRenderer(SDL_Window* window);
    update(renderer);

}