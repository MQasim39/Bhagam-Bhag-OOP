#include <SDL.h>
#pragma once

class Drawing {
public:
    // The window renderer
    static SDL_Renderer* gRenderer;
    // Global references to png image sheets
    static SDL_Texture* assets;         // Man Image
};

