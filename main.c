#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"


SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
int crear_ventana()
{
    printf("Creando Ventana\n");
    window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        printf("window could not be created, SDL_Error %s\n",SDL_GetError());
        return -1;
    }
    else
    {
        screenSurface = SDL_GetWindowSurface(window);
        return 0;
    }
    
    
}

void cerrar()
{
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_FreeSurface(screenSurface);
    screenSurface= NULL;
  
    //Quit SDL subsystems
    SDL_Quit();
}

int main()
{
    if( SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL cannot initialize, SDL_Error: %s\n",SDL_GetError());
    }
    crear_ventana();
    
    //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
    //Update the surface
    //SDL_UpdateWindowSurface(window );

    //Wait two seconds
    SDL_Delay( 2000 );
    //SDL_FreeSurface(screenSurface);
      //Destroy window
    
  
    return 0;
}

