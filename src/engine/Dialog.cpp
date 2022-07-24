
#include "../include/SDL_Base.h"
#ifdef _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "Include/SDL_test_log.h"
#include "Include/SDL_ttf.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include <cstdio>

#include "../include/dialog.h"
#include "../include/Event.h"


Dialogbox::Dialogbox(){
    static SDL_Texture * diagtex = IMG_LoadTexture(renderer, "Content/Resources/Assets/dialog.png");
    
    DialogTex = diagtex;
    SourceDialog.h = 193;
    SourceDialog.w = 1157;
    SourceDialog.x = 0;
    
    DestDialog.h = 193;
    DestDialog.w = 1157;

    //PhoneTexture = newtex;

   /* SourcePhone.h = 241;
    SourcePhone.w = 281;
    SourcePhone.x = 0;
    SourcePhone.y = 0;

    DestPhone.h = 241;
    DestPhone.w = 281;
    DestPhone.x = 0;
    DestPhone.y = 0;**/

}


int Dialogbox::dialog_text(const char* text){    
    TTF_Font* banhs = TTF_OpenFont("Content/Resources/Assets/Fonts/bahns.ttf", 24);
    SDL_Color White = {255, 255, 255};
    SDL_Color Black = {000,000,000};
    
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(banhs, text, Black); 
    printf("MMMMMH");
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 105;  //controls the rect's x coordinate 
    Message_rect.y = 600; // controls the rect's y coordinte
    Message_rect.w = 1100; // controls the width of the rect
    Message_rect.h = 200; // controls the height of the rect
    //SDL_BlitSurface( surfaceMessage, NULL, gScreenSurface, &Message_rect );
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
		MySleep(5000);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

void Dialogbox::DialogUpdate(){
    static SDL_Texture * diagtex = IMG_LoadTexture(renderer, "Content/Resources/Assets/dialog.png");
    
    DialogTex = diagtex;
    SourceDialog.h = 193;
    SourceDialog.w = 1157;
    SourceDialog.x = 0;
	SourceDialog.y = 0;
    
    DestDialog.h = 193;
    DestDialog.w = 1157;
	DestDialog.y = 568;
	DestDialog.x = 105;
	//SDL_RenderGetViewport(renderer, &DestDialog);
    
	//SDL_RenderSetViewport(renderer, &DestDialog);
    //SDL_RenderCopy(renderer, DialogTex, NULL, NULL);
    SDL_RenderCopy(renderer, DialogTex, &SourceDialog, &DestDialog);
    SDL_RenderPresent(renderer);
    //DialogDraw();
	//SDL_BlitSurface(renderer, DialogTex, &SourceDialog, &DestDialog);
}

void Dialogbox::DiagView(){
    
	SDL_RenderGetViewport(renderer, &DestDialog);
}


void Dialogbox::DialogDraw(){
    SDL_RenderCopy(renderer, DialogTex, NULL, NULL);
}