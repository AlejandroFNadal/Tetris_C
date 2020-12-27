#include "square.h"

void create_L(cuadrado mat[posancho][posalto], int current_block[4][2])
{
	int r = rand()%255;
	int g = rand()%255;
	int b = rand()%255;

	current_block[0][0]=current_block[1][0]=current_block[2][0]=posancho/2;
	current_block[3][0]=(posancho/2)+1;
	current_block[0][1]=0;
	current_block[1][1]=1;
	current_block[2][1]=2;
	current_block[3][1]=2;
	crear_cuadrado(posancho/2,0,r,g,b,mat);
	crear_cuadrado(posancho/2,1,r,g,b,mat);
	crear_cuadrado(posancho/2,2,r,g,b,mat);
	crear_cuadrado(posancho/2 + 1,2,r,g,b,mat);
}
