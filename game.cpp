#include "game.hpp"
#include "protag.hpp"
#include "stageonerun.hpp"
#include "drawing.hpp"
#include "screeninfo.hpp"

//done to include a particular image in the game

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

//Initialize pointer to zero so that it can be initialized in first call to getInstance
screeninfo *screeninfo::instance = 0;

//Getting the instance of SINGLETON Design Pattern
screeninfo* screen = screen->getInstance();

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 )
        {
            printf( "Unable to open audio: %s\n", Mix_GetError());
            success=false;
        }

		//Create window using SINGLETON Design Pattern
		gWindow = SDL_CreateWindow( "Epic Runner", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen->getWidth(), screen->getHeight(), SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadGrid()       //this is the main game one. This is where all the objects will come and the user can play.
{
	//Loading success flag
	bool success = true;
	// loading all the pictures
	Drawing::assets = loadTexture("assets.png");

    gTexture = loadTexture("bg.png");
	if(Drawing::assets==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

bool Game::loadMedia()   		//this function is called to display the main menu
{
	//Loading success flag
	bool success = true;
	music=Mix_LoadMUS("bhagambhaagsound.mp3");               //we introduced a song to make the game more lively
    gTexture = loadTexture("background1.png");					//image of the menu
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	if(music == NULL)
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
	Mix_PlayMusic(music,0);
	return success;
}


SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	SDL_Event e;

	stageonerun runningman;

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			// //User requests quit
			// if( e.type == SDL_QUIT )
			// {
			// 	quit = true;
			// 	cout<<quit;
			// }


			// if(e.type == SDL_MOUSEBUTTONDOWN){
			// //this is a good location to add pigeon in linked list.
			// 	int xMouse, yMouse;
			// 	SDL_GetMouseState(&xMouse,&yMouse);
			// 	if (state == 0 and xMouse>=415 and xMouse<= 575 and yMouse>=245 and yMouse<=295){  
			// 		// this checks whether we are on the main page and whether we clicked the play button
			// 		// in which case the game would start
			// 		state = 2;
			// 		loadGrid();        //loads the gaming screen
			// 	}
			// 	else if (state == 4){
			// 		// this one is for when the game is finished and you choose whether to contimue or end
			// 		if (xMouse>=425 and xMouse<= 575 and yMouse>=480 and yMouse<=535){
			// 			quit = true; //game finished --bye bye--
			// 		}
			// 		else if(xMouse>=410 and xMouse<= 590 and yMouse>=400 and yMouse<=470){
			// 			state = 0;
			// 			// runningman.counter = 0;        //state changed to the main menu one
			// 			loadMedia();			//main menu opened
			// 		}
			// 	}
			// 	else if(state == 0 and xMouse>=360 and xMouse<= 630 and yMouse>=370 and yMouse<=425){
			// 		state = 1;
			// 		loadIns();         //the instrutions screen is loaded and state is changed
			// 	}
			// 	else if(state == 1 and xMouse>=40 and xMouse<= 145 and yMouse>=35 and yMouse<=85){
			// 		state = 0;
			// 		loadMedia();	//the main screen is loaded and state is changed
			// 	}
			// }
			const Uint8* state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_UP]) { 
				runningman.checks = true;           //for a certain key, a certain check becomes true
			}
			if (state[SDL_SCANCODE_RIGHT]) { 
				runningman.right = true;            //for a certain key, a certain check becomes true
			}
			if (state[SDL_SCANCODE_LEFT]) { 
				runningman.left = true;	           //for a certain key, a certain check becomes true
			}   
		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		if (state ==2){      // these funstions are only called when the user is playing the game
		runningman.drawObjects();
		runningman.createObject();}

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(60);	//causes sdl engine to delay for specified miliseconds
	}
			
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;

	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
