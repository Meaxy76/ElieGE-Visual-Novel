
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
#include "include/SDL_Base.h"
#include "include/Mouse.h"
SDL_Window * window = NULL;
SDL_Renderer* renderer = NULL;

  SDL_Texture* MouseTexture = NULL;
  
  SDL_Rect MouseRect;
  SDL_Rect MousePoint;
int game()
{
    Mouse mouse;
    mouse.MouseMain();
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    window = SDL_CreateWindow("Heroes of the Aura",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1366,768,SDL_WINDOW_OPENGL);
    IMG_Init(IMG_INIT_PNG);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_Renderer* SDL_GetRenderer(SDL_Window* window);
        SDL_RenderPresent(renderer);

    bool running = true;
    double delta = .0001;
    double TimeClock = SDL_GetTicks();

    while (running){
        mouse.MouseUpdate();
        delta = (SDL_GetTicks() - TimeClock)/1000;
        TimeClock = SDL_GetTicks();

        SDL_Event event;

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
            }// end switch
        }// end loop

        auto KeyB = SDL_GetKeyboardState(0);

        if(KeyB[SDL_SCANCODE_ESCAPE]){
            running = false;
        }

        //mouse.Mouse();
        mouse.MouseDraw();
        SDL_Texture* character = IMG_LoadTexture(renderer, "back.png");
        SDL_RenderCopy(renderer, character, NULL,NULL);
        SDL_RenderPresent(renderer);

    }

    SDL_Quit();
    return 0;
}