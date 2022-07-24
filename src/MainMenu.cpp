#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ResourcePath.hpp"
#include "include/debug.h"
#elif _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "include/debug.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/debug.h"
#endif
#include <stdio.h>
#include "include/SDL_Base.h"
#include "include/Button.h"
#include "include/ElieGEVN.h"
#include "include/media.h"
SDL_Event event;
    bool running = true;

int MainMenu(){
        DEBUG->Log("Begin the game");  
    int TitleSound;
    MediaGEVN Media;
    Mouse mouse;
    
    ElieEngine engine;

    Button StartBtn;
    StartBtn.SourceSprite.y = 1;
    StartBtn.DestSprite.y = 40;
    StartBtn.DestSprite.x = 500;

    Button ContinueBtn;
    ContinueBtn.SourceSprite.y = 53;
    ContinueBtn.DestSprite.y = 103;
    ContinueBtn.DestSprite.x = 500;

    Button ExtraBtn;
    ExtraBtn.SourceSprite.y = 105;
    ExtraBtn.DestSprite.y = 166;
    ExtraBtn.DestSprite.x = 500;
    
    Button ConfigBtn;
    ConfigBtn.SourceSprite.y = 157; // POS Y in the sprite
    ConfigBtn.DestSprite.y = 227; // POS Y on the game
    ConfigBtn.DestSprite.x = 500; // POS X on the game
    TitleSound = Media.load_sound("Content/Resources/Assets/Tracks/believe.wav");

    bool MainMenu = true;
    double delta = .0001;
    double TimeClock = SDL_GetTicks();
        mouse.MouseMain();

    while(MainMenu) {
        delta = (SDL_GetTicks() - TimeClock)/1000;
        TimeClock = SDL_GetTicks();
        mouse.MouseUpdate();
        StartBtn.BtnUpdate(mouse);
        ContinueBtn.BtnUpdate(mouse);
        ExtraBtn.BtnUpdate(mouse);
        ConfigBtn.BtnUpdate(mouse);
        SDL_Texture* menumain = IMG_LoadTexture(renderer, "Content/Resources/Assets/Backgrounds/mainmenutest.png");
        SDL_RenderCopy(renderer, menumain, NULL,NULL);
        StartBtn.BtnDraw();
        ContinueBtn.BtnDraw();
        ExtraBtn.BtnDraw();
        ConfigBtn.BtnDraw();       
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(event.button.button == SDL_BUTTON_LEFT){
                        if(StartBtn.isSelected){
                            SDL_CloseAudioDevice(TitleSound);
                            engine.NewGame();
                        }
                        if(ContinueBtn.isSelected){
                            printf("Noice\n");
                            //ContinueGameMenu();
                        }
                        if(ExtraBtn.isSelected){
                            printf("Noice\n");
                            //ExtraMenu();
                        }
                        if(ConfigBtn.isSelected){
                            printf("Noice\n");
                        }
                    }
                    break;
            }// end switch
        }// end loop

        auto KeyB = SDL_GetKeyboardState(0);

        if(KeyB[SDL_SCANCODE_ESCAPE]){
            running = false;
            printf("REEEE");
        }


        //mouse.Mouse();
       // mouse.MouseDraw();
        

        //phone.SmartPhoneDraw();
        SDL_RenderPresent(renderer);
    }
    return false;
}