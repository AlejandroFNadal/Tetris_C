#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "gamefunc.h"


SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Event ev_control;
SDL_Renderer* renderer = NULL; 


//cuadrado matrix[posalto][posancho];



int main()
{
    cuadrado matrix[posancho][posalto];
    time_t t;
    
    bool falling= false;
    bool quit = false;
    
    srand((unsigned)time(&t));
    int current_inclination; 
    //empty matrix
    for(int x=0;x<posancho;x++)
    {
        for(int y=0;y<posalto;y++)
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

    int current_block[4][2];
    int block_type;
    
    while(!quit)
    {
        printf("Falling %d\n", falling);
        if(!falling) // a new figure is required
        {
	    //decide block type
	    block_type=rand()%2 + 4;
	    if(block_type == L_BLOCK)
	    {
		create_L(matrix,current_block);
	    }
	    else if(block_type == LINE_BLOCK)
            {
		create_line(matrix,current_block);
		current_inclination = LINE_VERTICAL;
	    }
            falling = true;
        }
        borders(renderer);
        //printf("Start of loop\n");
        //readMatrix(matrix);
        falling = gravity2(matrix,current_block);
        //printf("After gravity applied\n");
        readMatrix(matrix);
        detect_full_bottom(matrix);
        //printf("After detection of full bottom\n");
        readMatrix(matrix);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        dibujar_matriz(renderer,matrix);
        SDL_RenderPresent(renderer);
        SDL_Delay(200);
        SDL_SetRenderDrawColor(renderer,100,100,100,255);
        SDL_RenderClear(renderer);
        keyboard_reading(screenSurface,window, ev_control, matrix, current_block,block_type,&current_inclination);
        SDL_Delay(10);
    }
    cerrar(window,screenSurface);
  
    return 0;
}

