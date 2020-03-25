#include <SDL2/SDL.h>
#include <stdio.h>
#include "loadfunc.h"
struct cuadrado{
    Uint8 r;
    Uint8 g;
    Uint8 b;
};

typedef struct cuadrado cuadrado;



void crear_cuadrado(int x,int y,int r, int g, int b, cuadrado mat[posalto][posancho])
{
    
    //cuadrado temp;
    cuadrado *ptr;
    ptr=malloc(sizeof(cuadrado));
    ptr->r=r;
    ptr->g=g;
    ptr->b=b;
    mat[x][y]=*ptr;
    printf("Creando cuadrado\n");
}

void dibujar_matriz(SDL_Renderer *renderer,cuadrado mat[posalto][posancho])
{
    int x;
    int y;
    for(x=0;x<posancho;x++)
    {
        for(y=0;y<posalto;y++)
        {
            if((mat[x][y].r != 0) || (mat[x][y].g!=0) || (mat[x][y].b!=0))
            {
            printf("Pos_x:%d Pos_y %d \n",x,y);
            SDL_SetRenderDrawColor(renderer,mat[x][y].r,mat[x][y].g,mat[x][y].b,255);
            SDL_Rect temp_r={x*cuadrado_ancho +100,y*cuadrado_alto + 100,cuadrado_ancho,cuadrado_ancho};
            printf("Rect x %d Rect y %d Rect w %d Rect %d ",x*cuadrado_ancho +100,y*cuadrado_alto + 100,cuadrado_ancho,cuadrado_alto);
            //dibujar cuadrado aqui
            if(renderer != NULL)
            {
                printf("No Problema con renderer\n");
            }
            SDL_RenderFillRect(renderer, &temp_r);
            //SDL_RenderPresent(renderer);
            SDL_Delay(1000);
            }
        }
    }
    
}