#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ResourcePath.hpp"
#include "include/debug.h"
#elif _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/debug.h"
#endif

#include "../include/Event.h"


void MySleep( Uint32 interval )
{
    struct Container
    {
        static Uint32 TimerCallback( Uint32 interval, void* param )
        {
            SDL_Event event;
            event.type = SDL_USEREVENT;
            event.user.code = 42;
            SDL_PushEvent( &event );
            return 0;
        }
    };

    SDL_AddTimer( interval, Container::TimerCallback, NULL );

    SDL_Event event;
    while( SDL_WaitEvent( &event ) )
    {
        if( event.type == SDL_USEREVENT && event.user.code == 42 )
            break;
    }
}

void EngineEvent(int type) {
    if(type == 1){
        //we have events for MainMenu
    }
    if(type == 2){
        //we have events for SubMenus
    }
    if(type == 3){
        //we have events for phone
    }
}

