#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ResourcePath.hpp"
#include "debug.h"
#elif _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
//#include "debug.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "debug.h"
#endif

#include "SDL_Base.h"

class Mouse {
public:
  SDL_Rect MouseRect;
  SDL_Rect MousePoint;
  SDL_Texture* MouseTexture;

  void MouseMain() {
    MouseTexture = IMG_LoadTexture(renderer, "CURSOR.png");
    // 13x21
    MouseRect.h = 13;
    MouseRect.w = 21;
    MousePoint.h = 1;
    MousePoint.w = 1;
    SDL_ShowCursor(false);
  }

  void MouseUpdate() {
    SDL_GetMouseState(&MouseRect.x, &MouseRect.y);
    MousePoint.x = MouseRect.x;
    MousePoint.y = MouseRect.y;
  }

  void MouseDraw() {
    SDL_RenderCopy(renderer, MouseTexture, NULL, &MouseRect);
  }

};