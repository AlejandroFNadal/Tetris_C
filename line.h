#include "square.h"

typedef struct line line;

struct line{
    cuadrado first;
    cuadrado second;
    cuadrado third;
    cuadrado fourth;    
};
line create_line(cuadrado mat[posancho][posalto], int current_line[4][2])
{
    int r = rand()%255;
    int g = rand()%255;
    int b = rand()%255;
    static line a_line;
    a_line.first=crear_cuadrado(posancho/2, 0, r,g,b,mat);
    current_line[0][0]=current_line[1][0]=current_line[2][0]=current_line[3][0]=posancho/2;
    current_line[0][1]=0;
    current_line[1][1]=1;
    current_line[2][1]=2;
    current_line[3][1]=3;
    a_line.second=crear_cuadrado(posancho/2, 1, r,g,b,mat);
    a_line.third = crear_cuadrado(posancho/2, 2, r,g,b,mat);
    a_line.fourth=crear_cuadrado(posancho/2, 3, r,g,b,mat);
    return a_line;
}
