#include <SDL2/SDL.h>
#include <stdio.h>
#include "./ControlSystem.h"
#include <iostream>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// used to test control system
void printVector2D(Vector2D vec)
{
    cout<<"<"+to_string(vec[0])+","+to_string(vec[1])+">"<<endl;
}


 int main( int agrc , char * agrs [])
{
    /* ********************.       INITIALIZATION PART       *******************/
	//The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }


    /* ********************       TESTING PART       *******************/
    ControlSystem* cs = ControlSystem::instance();
    bool running =true;
	while (running)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running =false;
					break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym==SDLK_q) running = false;
                    else cs->update(event);
			}

            Vector2D input_this_frame = cs->getInputs(0);
            printVector2D(input_this_frame);
		}

	}

        //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}

