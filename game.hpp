#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>

class Game{
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;

    Mix_Music* music=NULL;

public:
    bool init();
    //these are the different functions, each called differenty, for different screens 
    bool loadMedia();    
    bool loadIns();
    bool loadWIN();
    bool loadLOST();
    bool loadGrid();
    
    void close();   
    SDL_Texture* loadTexture( std::string path );
    void run();
    int state = 0;          //this is used to check which screen we currently are on. 
};

