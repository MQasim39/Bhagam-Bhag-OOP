#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "protag.hpp"
#include <iostream>
using namespace std;

class Unit{             //defining a class named unit that will be inherited by ghost, meteor, cactus and animal class
    protected:
        SDL_Rect srcRect, moverRect;            //These values will be inherited by the child classes. This would contain initial srcRect, moverRect values.
    public:
        //virtual int count;
        virtual void draw() = 0;       //A pure virtual draw function as it is unique to each class
        virtual void move() = 0;     //A virtual move function as it is unique to each class
        friend class RunningMan;        
        virtual ~Unit();            //virtual destructor called 
};