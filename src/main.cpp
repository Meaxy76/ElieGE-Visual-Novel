// #include <SFML/Graphics.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Audio.hpp>
#ifdef _WIN32
#include "include/debug.h"
#endif

#include <stdio.h>

//#include "include/eliege.hpp"
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>

int game();


int main()
{    
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
        DEBUG->Log("Begin the game");  
        game();

        return 0;
}

