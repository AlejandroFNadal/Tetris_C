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
    int n = 0;
    bool falling= true;
    bool quit = false;
    
    while(!quit)
    {
        printf("%d\n",n);
        create_line(matrix);
        dibujar_matriz(renderer,matrix);
        SDL_RenderPresent(renderer);
        SDL_Delay(200);
        SDL_SetRenderDrawColor(renderer,100,100,100,255);
        SDL_RenderClear(renderer);
        while(falling == true)
        {
            falling = gravity(matrix);
            detect_full_bottom(matrix);
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            dibujar_matriz(renderer,matrix);
            SDL_RenderPresent(renderer);
            SDL_Delay(200);
            SDL_SetRenderDrawColor(renderer,100,100,100,255);
            SDL_RenderClear(renderer);
            while(SDL_PollEvent(&ev_control)){
                if(ev_control.type == SDL_KEYDOWN)
                {
                    printf("Key pressed\n");
                    if(ev_control.key.keysym.sym == SDLK_ESCAPE)
                    {
                        printf("Escape pressed\n");
                        cerrar(window,screenSurface);
                        return 0;
                    }
                }
            }
            
        }
        falling=true;
        n++;
        SDL_Delay(10);
    }
    

    
    
   
    //Wait two seconds
    SDL_Delay( 5000 );
    //SDL_FreeSurface(screenSurface);
      //Destroy window
    cerrar(window,screenSurface);
  
    return 0;
}

