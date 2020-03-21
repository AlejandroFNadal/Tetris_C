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
    cuadrado temp;
    temp.x=x;
    temp.y=y;
    temp.r=r;
    temp.g=g;
    temp.b=b;
    mat[x][y]=temp;
}

void dibujar_matriz(cuadrado mat[posalto][posancho])
{
    int x;
    int y;
    for(x=0;x<posancho;x++)
    {
        for(y=0;y<posalto;y++)
        {
            //dibujar cuadrado aqui
        }
    }
}