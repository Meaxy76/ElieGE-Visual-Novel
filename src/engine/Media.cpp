
#include <stdio.h>

#ifdef _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "Include/SDL_test_log.h"
#include "Include/SDL_ttf.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "../include/media.h"
#include "../include/resources.h"
#include "../include/SDL_Base.h"

Uint32 wavLength;
Uint8 *wavBuffer;

void MediaGEVN::Splash(SDL_Renderer* renderer){
    string path = RESOURCES->SplashRoot + "SplashTest.png";
    const char * splashimg = path.c_str();
    SDL_Texture* splash = IMG_LoadTexture(renderer, splashimg);
    SDL_RenderCopy(renderer, splash, NULL,NULL);
}

MediaGEVN::load_sound(string pathsound)
{
    SDL_AudioDeviceID deviceId;
    SDL_AudioSpec wavSpec;
    
    const char * c = pathsound.c_str();
    SDL_LoadWAV(c, &wavSpec, &wavBuffer, &wavLength);
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
    
    return deviceId;
}

