

#include "../include/button.h"
#include "../include/SDL_Base.h"
#include "../include/media.h"

MediaGEVN Media;

Button::Button(){
    static SDL_Texture * tex = IMG_LoadTexture(renderer, "Content/Resources/Assets/Buttons/spritebtns.png");
    SpriteTex = tex;

    SourceSprite.h = 51;
    SourceSprite.w = 194;
    SourceSprite.x = 1;

    DestSprite.h = 51;
    DestSprite.w = 194;

}

Button::~Button(){
    
}

void Button::BtnUpdate(Mouse& mouse) {
    if (SDL_HasIntersection(&DestSprite, &mouse.MousePoint)){
        isSelected = true;
        SourceSprite.x = 196;
       // Media.load_sound("click.wav");

    }else{
        isSelected = false;
        SourceSprite.x = 1;
        //Media.load_sound("click.wav");

    }
}

void Button::BtnDraw(){
    SDL_RenderCopy(renderer, SpriteTex, &SourceSprite, &DestSprite);
}