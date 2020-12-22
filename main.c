#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
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
    time_t t;
    int x, y;
    int n = 0;
    bool falling= false;
    bool quit = false;
    bool create_new_figure= true;
    srand((unsigned)time(&t));
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
    SDL_RenderPresent(renderer);

    
    
    while(!quit)
    {
        printf("Falling %d\n", falling);
        if(!falling) // a new figure is required
        {
            //create_line(matrix);
            crear_cuadrado(2, 0, 255,255,255,matrix);
            falling = true;
        }
        borders(renderer);
        printf("Start of loop\n");
        readMatrix(matrix);
        falling = gravity(matrix);
        printf("After gravity applied\n");
        readMatrix(matrix);
        detect_full_bottom(matrix);
        printf("After detection of full bottom\n");
        readMatrix(matrix);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        dibujar_matriz(renderer,matrix);
        SDL_RenderPresent(renderer);
        SDL_Delay(200);
        SDL_SetRenderDrawColor(renderer,100,100,100,255);
        SDL_RenderClear(renderer);
        keyboard_reading(screenSurface,window, ev_control, matrix);
        SDL_Delay(10);
    }
    

    
    
    /*crear_cuadrado(0,1,255,255,255,matrix);
    dibujar_matriz(renderer,matrix);
    SDL_RenderPresent(renderer);*/
    //Wait two seconds
    SDL_Delay( 5000 );
    //SDL_FreeSurface(screenSurface);
      //Destroy window
    cerrar(window,screenSurface);
  
    return 0;
}

