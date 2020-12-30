#include "square.h"
//angle of L
#define L_ON_L 20
#define L_ON_90 21
#define L_ON_180 22
#define L_ON_270 23

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
int check_L_rotation(cuadrado mat[posancho][posalto], int current_block[4][2])
{
	//return 0 if no rotation is possible
	//return 1 if left rotation
	//return 2 if right rotation
	return 1;
}
void L_rotate(cuadrado mat[posancho][posalto],int current_block[4][2], int spin_direction, int *current_inclination)
{
	cuadrado temp_block[4];
	int temp_x, temp_y;
	cuadrado rotation_matrix[4][4];
	//center detection
	if(*current_inclination == L_ON_L || *current_inclination == L_ON_180)
	{

	}

}
