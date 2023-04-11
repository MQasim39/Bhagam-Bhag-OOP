#include <iostream>
#include "stageonerun.hpp"

using namespace std;

void stageonerun::drawObjects()                                 //Draws all the objects
{   
    int k = 0; 
    
    while (k < man.size()){                                     //Iterating over the vector to make the object 
        if (k==0){                                              //Initial Object Creation
        man[k]->draw();                                         //Calling the draw function
    if (left==true){                                            //User has pressed left button
            if ( (man[k] ->moverRect.x - 130) < 0 )             //Checks the corner of the screen
                {man[k] ->moverRect.x = 0;}                     //The man object moves left
            else {man[k] ->  moverRect.x -= 130;}               //The man object moves left
                left = false;}
        if (right==true){                                       //User has pressed right button
            if ( (man[k] ->moverRect.x + 130) > 980 )           //Checks the corner of the screen
                {man[k] ->moverRect.x = 980;}                   //The man object moves right
            else{man[k] ->  moverRect.x += 130;}                //The man object moves right
                right = false;}
        if (checks==true){                                      //User has pressed jump button
            man[k] -> check = true;                             //Flag Variable
            checks = false;}
        if (man[k] -> check ==true){
        man[k]->jump();}                                        //Calling the Jump function
        else{
        man[k]->moving();}  }                                   //Calling the Move function
        k++;}
    } 

void stageonerun::createObject()                     //Creates and pushes all the objects to vectors
{
    if (counter == 0){
        if (man.size()<1){                       //Checks if the vector is empty
        protag *man1 = new protag();                      //Creates one man object pointer
        man.push_back(man1);}

        counter++ ;
    }

}

stageonerun :: ~stageonerun(){                        //Destructor to remove the object of this class
}