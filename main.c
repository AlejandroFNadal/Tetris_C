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
    cuadrado a1;
    a1.g=230;
    matrix[0][0]=a1;
    if( SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL cannot initialize, SDL_Error: %s\n",SDL_GetError());
    }
    //crear_ventana(window,screenSurface, renderer);
    
    
    window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    if(renderer == NULL)
        printf("Render error");
    SDL_SetRenderDrawColor(renderer,100,100,100,255);
    SDL_RenderClear(renderer);
    //int x = 1;
    //int y = 1;
    //SDL_SetRenderDrawColor(renderer,255,0,0,255);
     //SDL_Rect temp_r={x*cuadrado_ancho +100,y*cuadrado_alto + 100,cuadrado_ancho,cuadrado_alto};
    //printf("Rect x %d Rect y %d Rect w %d Rect %d ",x*cuadrado_ancho +100,y*cuadrado_alto + 100,cuadrado_ancho,cuadrado_alto);
    //dibujar cuadrado aqui
    //SDL_RenderFillRect(renderer, &temp_r);
    //crear_cuadrado(5,5,255,0,0,matrix);
    //crear_cuadrado(6,6,255,255,0,matrix);
    dibujar_matriz(renderer,matrix);
    SDL_RenderPresent(renderer);
    
   
    //Wait two seconds
    SDL_Delay( 5000 );
    //SDL_FreeSurface(screenSurface);
      //Destroy window
    cerrar(window,screenSurface);
  
    return 0;
}

