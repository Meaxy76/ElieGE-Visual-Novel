#ifdef _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "Include/SDL_test_log.h"
#include "Include/SDL_ttf.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

class Dialogbox
{
public:
    SDL_Texture * DialogTex;
    SDL_Rect SourceDialog;
    SDL_Rect DestDialog;
    Dialogbox();
    int dialog_text(const char* text);
    void DiagView();
    void DialogUpdate();
    void DialogDraw();
};