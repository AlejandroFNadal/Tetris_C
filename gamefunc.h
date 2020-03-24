#include <SDL2/SDL.h>
#include <stdio.h>
#include "loadfunc.h"
struct cuadrado{
    int x;
    int y;
    Uint8 r;
    Uint8 g;
    Uint8 b;
};

typedef struct cuadrado cuadrado;



void crear_cuadrado(int x,int y,int r, int g, int b, cuadrado mat[posalto][posancho])
{
    
    static cuadrado temp;
    temp.x=x;//posicion en matriz
    temp.y=y;
    temp.r=r;
    temp.g=g;
    temp.b=b;
    mat[x][y]=temp;
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
            if(mat[x][y].x != 0)
            {
            printf("Pos_x:%d Pos_y %d X:%d\n",x,y,mat[x][y].x);
            SDL_SetRenderDrawColor(renderer,mat[x][y].r,mat[x][y].g,mat[x][y].b,0xFF);
            SDL_Rect temp_r={100+cuadrado_ancho*mat[x][y].x,100+cuadrado_alto*mat[x][y].y,100+cuadrado_ancho*((mat[x][y].x)+1), 100+cuadrado_alto*(mat[x][y].y+1)};
            //dibujar cuadrado aqui
            SDL_RenderFillRect(renderer, &temp_r);
            }
        }
    }
    SDL_RenderPresent(renderer);
}