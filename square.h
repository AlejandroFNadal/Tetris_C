#include <stdbool.h>
#include "constants.h"
#ifndef SQUARE_H
#define SQUARE_H

struct cuadrado{
    int r;
    int g;
    int b;
    int x;
    int y;
    bool active;
    bool moving;
};
typedef struct cuadrado cuadrado;

cuadrado crear_cuadrado(int x,int y,int r, int g, int b, cuadrado mat[posancho][posalto])
{
    mat[x][y].r=r;
    mat[x][y].g=g;
    mat[x][y].b=b;
    mat[x][y].x=x;
    mat[x][y].y=y;
    mat[x][y].active=true;
    mat[x][y].moving=true;
    //printf("Block created in %d %d\n",x,y);

    return mat[x][y];
}

cuadrado nullyfy_square(cuadrado a)
{
    a.r=0;
    a.g=0;
    a.b=0;
    a.x=-1;
    a.y=-1;
    a.active=false;
    a.moving=false;
    return a;
}

#endif
