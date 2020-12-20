#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
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
    int x, y;
    //empty matrix
    for(x=0;x<posalto;x++)
    {
        for(y=0;y<posancho;y++)
        {
            matrix[x][y].r=0;
            matrix[x][y].g=0;
            matrix[x][y].b=0;
            matrix[x][y].active=false;
            matrix[x][y].moving=false;
        }
    }
    
    if( SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL cannot initialize, SDL_Error: %s\n",SDL_GetError());
    }
    
    
    
    window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    if(renderer == NULL)
        printf("Render error");
    SDL_SetRenderDrawColor(renderer,100,100,100,255);
    SDL_RenderClear(renderer);
    
    borders(renderer);
    create_random_block(matrix);
    gravity(matrix);

    dibujar_matriz(renderer,matrix);
    SDL_RenderPresent(renderer);
    
   
    //Wait two seconds
    SDL_Delay( 5000 );
    //SDL_FreeSurface(screenSurface);
      //Destroy window
    cerrar(window,screenSurface);
  
    return 0;
}

