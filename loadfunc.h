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
    //Quit SDL subsystems
    SDL_Quit();
}

int detect_high_point(int block[4][2])
{
    int high_point = 100000;
    for(int i =0;i<4;i++)
    {
        if(block[i][1] < high_point){
            high_point=block[i][1];
        }
    }
    return high_point;
}
int detect_low_point(int block[4][2])
{
    int low_point = 0;
    for(int i =0;i<4;i++)
    {
        if(block[i][1] > low_point){
            low_point=block[i][1];
        }
    }
    return low_point;
}
int detect_left_point(int block[4][2])
{
    int left_point = 100000;
    for(int i =0;i<4;i++)
    {
        if(block[i][0] < left_point){
            left_point=block[i][0];
        }
    }
    return left_point;
}

int detect_right_point(int block[4][2])
{
    int right_point = 0;
    for(int i =0;i<4;i++)
    {
        if(block[i][0] > right_point){
            right_point=block[i][0];
        }
    }
    return right_point;
}
