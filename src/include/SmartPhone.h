#ifndef GEVN_PHONE_H
#define GEVN_PHONE_H

#ifdef _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "Include/SDL_test_log.h"
#include "Include/SDL_ttf.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

class SmartPhone {
public:
    SDL_Texture * PhoneTexture;
    SDL_Rect SourcePhone;
    SDL_Rect DestPhone;

    SDL_Texture * PhoneOSapps;
    SDL_Rect PhoneOSSource;
    SDL_Rect PhoneOSDest;
    bool AppisSelected = false;

    bool isOpened = false;

    SmartPhone();
    virtual ~SmartPhone();

    void PhoneOS();
    void PhoneOSUpdate();
    void PhoneOSDraw();

    void SmartPhoneClose();
    void SmartPhoneOpen();
    void IncommingCall();
    //void SmartPhoneUpdate();
    void SmartPhoneDraw();
};

#endif /* GEVN_PHONE_H*/ 