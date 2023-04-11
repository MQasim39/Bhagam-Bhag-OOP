#include <iostream>

using namespace std;

class screeninfo{
    static screeninfo *instance;            //the SINGLETON object that will be used throughout
    int SCREEN_WIDTH = 1000;                //Game screen width
    int SCREEN_HEIGHT = 600;                //Game screen height
 
    // Private constructor so that no objects can be created.
    screeninfo();

    public:
    static screeninfo* getInstance() {          //Function to get the created object or create a new one if not already
        if (!instance)
        instance = new screeninfo;
        return instance;
   }
    int getWidth();                     //Function to get the SCREEN_WIDTH data
    int getHeight();                    //Function to get the SCREEN_HEIGHT data
    void setData(int w, int h);         //Function to change/set the data if needed
    ~screeninfo();                      //Destructor to remove the object
};