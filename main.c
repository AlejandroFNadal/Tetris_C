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
SDL_Renderer* renderer = NULL; 

cuadrado matrix[posalto][posancho];


int main()
{
    
    if( SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL cannot initialize, SDL_Error: %s\n",SDL_GetError());
    }
    //crear_ventana(window,screenSurface, renderer);
    //crear_cuadrado(5,5,255,0,0,matrix);
    //dibujar_matriz(renderer,matrix);
    window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    if(renderer == NULL)
        printf("Render error");
    
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderClear(renderer);
    //SDL_Rect temp_r={100,100,200,200};
            //dibujar cuadrado aqui
    //SDL_RenderFillRect(renderer, &temp_r);
    SDL_RenderPresent(renderer);
    //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
    //Update the surface
    //SDL_UpdateWindowSurface(window );

    //Wait two seconds
    SDL_Delay( 5000 );
    //SDL_FreeSurface(screenSurface);
      //Destroy window
    cerrar(window,screenSurface);
  
    return 0;
}

