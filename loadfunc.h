#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"
int crear_ventana(SDL_Window* window, SDL_Surface *screenSurface,SDL_Renderer *renderer)
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
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer == NULL)
        {
            printf("renderer could not be created, SDL_Error %s\n",SDL_GetError());
            return -1;
        }
        else
        {
            return 0;    
        }
    }
    
    
}

void cerrar(SDL_Window *window, SDL_Surface *screenSurface)
{
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_FreeSurface(screenSurface);
    screenSurface= NULL;
  
    //Quit SDL subsystems
    SDL_Quit();
}
