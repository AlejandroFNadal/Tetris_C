#include <SDL2/SDL.h>
#include <stdio.h>
#include "loadfunc.h"
#include <stdlib.h>
#include <stdbool.h>
#define LEFT 1
#define RIGHT 2

struct cuadrado{
    int r;
    int g;
    int b;
    bool active;
    bool moving;
};
typedef struct cuadrado cuadrado;
//line struct contains the four cubes that make a line
struct line{
    cuadrado *first;
    cuadrado *second;
    cuadrado *third;
    cuadrado *fourth;    
};

typedef struct line line;

//Prototypes

void crear_cuadrado(int x,int y,int r, int g, int b, cuadrado mat[posalto][posancho]);
void single_move(cuadrado mat[posancho][posalto],int x, int y, int next_x, int next_y);
void move(cuadrado mat[posancho][posalto], int where); //LEFT = 1, RIGHT = 2


void keyboard_reading(SDL_Surface *screenSurface, SDL_Window *window, SDL_Event ev_control, cuadrado mat[posancho][posalto])
{
    while(SDL_PollEvent(&ev_control)){
                if(ev_control.type == SDL_KEYDOWN)
                {
                    printf("Key pressed\n");
                    if(ev_control.key.keysym.sym == SDLK_ESCAPE)
                    {
                        printf("Escape pressed\n");
                        cerrar(window,screenSurface);
                        exit(0);
                    }
                    if(ev_control.key.keysym.sym==SDLK_LEFT)
                    {
                        move(mat,LEFT);
                    }
                }
            }
}
void move(cuadrado mat[posancho][posalto], int where)
{
   
    for(int x = 0;x < posancho;x++)
    {
        if(where == LEFT) //This is necesary because of the individuality of each block. If not, when moving to the left, a lateral set of blocks will collapse one with another
        {
            for(int y = 0; y < posalto;y++)
            {
                if(mat[x][y].moving==true)
                {
                    if(mat[x-1][y].active==false && x > 0)
                    {
                       single_move(mat,x,y,x-1,y);
                    }
                }
            }
        }
        
    }
}
void single_move(cuadrado mat[posancho][posalto],int x, int y, int next_x, int next_y)
{
    mat[next_x][next_y].active=true;
    mat[next_x][next_y].r=mat[x][y].r;
    mat[next_x][next_y].r=mat[x][y].g;
    mat[next_x][next_y].r=mat[x][y].b;
    mat[x][y].active=false;
    mat[x][y].moving= false;
    mat[next_x][next_y].moving=true;
}
void create_line(cuadrado mat[posancho][posalto])
{
    crear_cuadrado(posancho/2, 0, 255,255,255,mat);
    crear_cuadrado(posancho/2, 1, 255,255,255,mat);
    crear_cuadrado(posancho/2, 2, 255,255,255,mat);
    crear_cuadrado(posancho/2, 3, 255,255,255,mat);
}
void detect_full_bottom(cuadrado mat[posancho][posalto])
{
    bool eliminate = true;
    for(int x = 0; x < posancho;x++)
    {
        if(mat[x][posalto-1].active==false)
        {
            eliminate = false;
            break;
        }
    }
    if(eliminate == true)
    {
        printf("Detecting full bottom\n");
        for(int x = 0; x < posancho;x++)
        {
            mat[x][posalto-1].active=false;
            mat[x][posalto-1].r=0;
            mat[x][posalto-1].b=0;
            mat[x][posalto-1].g=0;
            mat[x][posalto-1].moving=false;
        }
    }
}
void readMatrix(cuadrado mat[posancho][posalto])
{
    for(int x = 0; x < posancho; x++)
    {
        for(int y = 0; y < posalto;y++)
        {
            printf(" %d", mat[x][y].active);
        }
        printf("\n");
    }
}
bool gravity(cuadrado mat[posancho][posalto])
{
    bool move_occur = false;
    //these for go backwards because if not, when a series of blocks must go down, those below that should move will 
    //move after those above and cause movement problems
    for(int x =posancho-1; x>=0 ;x--)
    {
        for(int y = posalto-1;y >= 0;y--)
        {
            if(mat[x][y].active == true && mat[x][y].moving==true)
            {
                if(y < posalto-1 && mat[x][y+1].active ==false)
                {
                    printf("Move down in %d %d\n", x,y);
                    //CREATE DEACTIVATE FUNCTION FOR THIS
                    mat[x][y+1].active = true;
                    mat[x][y+1].moving = true;
                    mat[x][y+1].r=mat[x][y].r;
                    mat[x][y+1].g=mat[x][y].g;
                    mat[x][y+1].b=mat[x][y].b;
                    mat[x][y].r=0;
                    mat[x][y].b=0;
                    mat[x][y].g=0;
                    mat[x][y].active=false;
                    mat[x][y].moving=false;
                    move_occur=true;
                }
                if(y == posalto-2)
                {
                    mat[x][y].moving= false;
                }
                if(mat[x][y+2].active == true)
                {
                    mat[x][y].moving= false;
                }
            }
        }
    }
    return move_occur;
}
void borders(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderDrawLine(renderer,inimatriz_x,inimatriz_y,inimatriz_x,finmatriz_y);
    SDL_RenderDrawLine(renderer,inimatriz_x,inimatriz_y,finmatriz_x,inimatriz_y);
    SDL_RenderDrawLine(renderer,finmatriz_x,inimatriz_y,finmatriz_x,finmatriz_y);
    SDL_RenderDrawLine(renderer,inimatriz_x,finmatriz_y,finmatriz_x,finmatriz_y);

}



void create_random_block(cuadrado mat[posalto][posancho])
{
    crear_cuadrado(rand() % posancho,0,255,255,255,mat);
}
void crear_cuadrado(int x,int y,int r, int g, int b, cuadrado mat[posalto][posancho])
{
    mat[x][y].r=r;
    mat[x][y].g=g;
    mat[x][y].b=b;
    mat[x][y].active=true;
    mat[x][y].moving=true;
    printf("Block created in %d %d\n",x,y);
}

void dibujar_matriz(SDL_Renderer *renderer,cuadrado mat[posalto][posancho])
{
    int x;
    int y;
    for(x=0;x<posancho;x++)
    {
        for(y=0;y<posalto;y++)
        {
            if(mat[x][y].active == true){
                SDL_SetRenderDrawColor(renderer,mat[x][y].r,mat[x][y].g,mat[x][y].b,255);
                SDL_Rect temp_r={x*cuadrado_ancho +100,y*cuadrado_alto + 100,cuadrado_ancho,cuadrado_alto};
                //dibujar cuadrado aqui
                if(renderer == NULL)
                {
                    printf("Problema con renderer\n");
                }
                SDL_RenderFillRect(renderer, &temp_r);
                SDL_Delay(1);
            }
        }
    }
    
}

