
#include "../include/SmartPhone.h"
#include "../include/SDL_Base.h"

#include "../include/Media.h"
#include "../include/Mouse.h"

MediaGEVN PhoneRingtone;

SDL_Texture * PhoneTexture;
Mouse osmouse;

SmartPhone::SmartPhone(){
    static SDL_Texture * newtex = IMG_LoadTexture(renderer, "Content/Resources/Assets/Phone/phone.png");
    PhoneTexture = newtex;

    SourcePhone.h = 241;
    SourcePhone.w = 281;
    SourcePhone.x = 0;
    SourcePhone.y = 0;

    DestPhone.h = 241;
    DestPhone.w = 281;
    DestPhone.x = 0;
    DestPhone.y = 0;

}

SmartPhone::~SmartPhone(){
    
}

void SmartPhone::IncommingCall(){
    // Specific stuff etc
    //PhoneRingtone.load_sound("fatima.wav");
}

void SmartPhone::PhoneOS(){
    static SDL_Texture * apps = IMG_LoadTexture(renderer, "Content/Resources/Assets/Phone/phoneicons.png");
    PhoneOSapps = apps;

    PhoneOSSource.h = 50;
    PhoneOSSource.w = 50;
    PhoneOSSource.x = 0;

    PhoneOSDest.h = 50;
    PhoneOSDest.w = 50;
    // Specific stuff etc
    //PhoneRingtone.load_sound("fatima.wav");
}

void SmartPhone::PhoneOSUpdate(){
    if (SDL_HasIntersection(&PhoneOSDest, &osmouse.MousePoint)){
        AppisSelected = true;
        PhoneOSSource.x = 90;
       // Media.load_sound("click.wav");

    }else{
        AppisSelected = false;
        PhoneOSSource.x = 0;
        //Media.load_sound("click.wav");

    }
}

void SmartPhone::PhoneOSDraw(){
    // Specific stuff etc
    //PhoneRingtone.load_sound("fatima.wav");
    SDL_RenderCopy(renderer, PhoneOSapps, &PhoneOSSource, &PhoneOSDest);
}


/*void SmartPhone::SmartPhoneUpdate() {
    if (SDL_HasIntersection(&DestPhone, &mouse.MousePoint)){
        isOpened = true;
        SourceSprite.x = 196;
        
        DestPhone.y = 503;
        DestPhone.x = 500;
       // Media.load_sound("click.wav");

    }else{
        isOpened = false;
        SourceSprite.x = 1;
        //Media.load_sound("click.wav");

    }
}*/
void SmartPhone::SmartPhoneOpen() {
    PhoneTexture = IMG_LoadTexture(renderer, "Content/Resources/Assets/Phone/phone.png");
    isOpened = true;
    int maxposy = 768 - 500;

    SourcePhone.h = 651;
    SourcePhone.w = 291;
    SourcePhone.x = 0;
    SourcePhone.y = 0;
    DestPhone.h = 651;
    DestPhone.w = 291;
    DestPhone.x = 1366 - 320;
    DestPhone.y = 768 - 600;

    SDL_RenderCopy(renderer, PhoneTexture, &SourcePhone, &DestPhone);
        SDL_RenderPresent(renderer);

        //SmartPhoneDraw();
}

void SmartPhone::SmartPhoneClose() {
        isOpened = false;
        DestPhone.y = 768;
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(PhoneTexture);
        //SDL_RenderCopy(renderer, PhoneTexture, &SourcePhone, &DestPhone);
}

void SmartPhone::SmartPhoneDraw(){
    SDL_RenderCopy(renderer, PhoneTexture, &SourcePhone, &DestPhone);
}