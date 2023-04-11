#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"

class protag{
    SDL_Rect srcRect, moverRect;
    friend class stageonerun;
public:
    void draw();        //draw function declared here
    protag();                //default constructor
    bool check;             //check used in Runningprotag for jump checking
    void moving();          //moving function 
    void jump();            //jump function
    int i;                  // for horizontal animation 
    int frame = 0;          // for animation while jumping 
    ~protag();                 // destructor
};