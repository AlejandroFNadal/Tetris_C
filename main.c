#include <stdio.h>
#include <SDL2/SDL.h>
//#include "constants.h"
//#include "loadfunc.h"
#include "gamefunc.h"
#define posalto 30
#define posancho 10
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Event ev_control;

cuadrado matrix[posalto][posancho];


int main()
{
    if( SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL cannot initialize, SDL_Error: %s\n",SDL_GetError());
    }
    crear_ventana(window,screenSurface);
    
    //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
    //Update the surface
    //SDL_UpdateWindowSurface(window );

    //Wait two seconds
    SDL_Delay( 2000 );
    //SDL_FreeSurface(screenSurface);
      //Destroy window
    cerrar(window,screenSurface);
  
    return 0;
}

