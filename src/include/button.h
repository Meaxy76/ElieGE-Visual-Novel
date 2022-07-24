#ifndef GEVN_BUTTON_H
#define GEVN_BUTTON_H

#ifdef _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "Include/SDL_test_log.h"
#include "Include/SDL_ttf.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "Mouse.h"

class Button {
public:
    SDL_Texture * SpriteTex;
    SDL_Rect SourceSprite;
    SDL_Rect DestSprite;

    bool isSelected = false;

    Button();
    virtual ~Button();

    void BtnUpdate(Mouse&);
    void BtnDraw();
};

#endif /* GEVN_BUTTON_H*/ 