#include <stdio.h>
#include <SDL2/SDL.h>


int main()
{
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if( SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL cannot initialize, SDL_Error: %s\n",SDL_GetError());
    }
    else
    {
        window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);
        if(window == NULL)
        {
            printf("window could not be created, SDL_Error %s\n",SDL_GetError());
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );
        }
        
    }
      //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
    

}