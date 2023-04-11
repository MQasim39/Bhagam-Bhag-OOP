#include "screeninfo.hpp"
#include <iostream>

using namespace std;

screeninfo::screeninfo(){                           //Constructor to set the values
    int SCREEN_WIDTH = 1000;
    int SCREEN_HEIGHT = 600;
}

int screeninfo::getWidth() {                        //Function to get the SCREEN_WIDTH data
    return this ->SCREEN_WIDTH;
}
int screeninfo::getHeight() {                       //Function to get the SCREEN_HEIGHT data
    return this ->SCREEN_HEIGHT;
}

void screeninfo::setData(int w, int h) {            //Function to change/set the data if needed
    this -> SCREEN_WIDTH = w;
    this -> SCREEN_WIDTH = h;
}

screeninfo::~screeninfo(){                          //Destructor to remove the object

}