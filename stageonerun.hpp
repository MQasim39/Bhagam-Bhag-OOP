#include<SDL.h>
#include "protag.hpp"
#include "Unit.hpp"
#include<vector>
#include<list>
using namespace std;

class stageonerun{
    vector<protag*> man;                       //Vector to store the man object
    list <Unit*> objects;                   //List to store the rest of the polymorphised objects' pointers such as animal, ghosts etc

    public:
    
    bool checks = false ;                   //Checks if the user has pressed jump for the man
    bool left = false ;                     //Checks if the user has pressed left dash for the man
    bool right = false ;                    //Checks if the user has pressed right dash for the man
    int counter=0;                          //Checks how many man/lives object has been created
    void drawObjects();                     //Draws all the objects
    void createObject();                    //Creates and pushes all the objects to vectors
    void emptying();                        //Clears the vectors and deletes the pointers/everything

    ~stageonerun();                          //Destructor
};