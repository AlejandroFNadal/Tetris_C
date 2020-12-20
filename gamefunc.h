#include <SDL2/SDL.h>
#include <stdio.h>
#include "loadfunc.h"
#include <stdlib.h>
#include <stdbool.h>


struct cuadrado{
    int r;
    int g;
    int b;
    bool active;
    bool moving;
};

typedef struct cuadrado cuadrado;

void detect_full_bottom(cuadrado mat[posancho][posalto])
{
    bool eliminate = true;
    for(int x = 0; x < posancho;x++)
    {
        printf("Detecting full bottom\n");
        printf("Pos x %d \n",x);
        if(mat[x][posalto-1].active==false)
        {
            eliminate = false;
            break;
        }
    }
    if(eliminate == true)
    {
        for(int x = 0; x < posancho;x++)
        {
            mat[x][posalto-1].active=false;
            mat[x][posalto-1].r=0;
            mat[x][posalto-1].b=0;
            mat[x][posalto-1].g=0;
        }
    }
}
bool gravity(cuadrado mat[posancho][posalto])
{
    bool move_occur = false;
    //these for go backwards because if not, when a series of blocks must go down, those below that should move will 
    //move after those above and cause movement problems
    for(int x =posancho; x>=0 ;x--)
    {
        for(int y = posalto;y >= 0;y--)
        {
            if(mat[x][y].active == true)
            {
                if(y < posalto-1 && mat[x][y+1].active ==false)
                {
                    printf("Move down in %d %d\n", x,y);
                    //CREATE DEACTIVATE FUNCTION FOR THIS
                    mat[x][y+1].active = true;
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

void crear_cuadrado(int x,int y,int r, int g, int b, cuadrado mat[posalto][posancho]);

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
}

void dibujar_matriz(SDL_Renderer *renderer,cuadrado mat[posalto][posancho])
{
    int x;
    int y;
    for(x=0;x<posancho;x++)
    {
        for(y=0;y<posalto;y++)
        {
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

