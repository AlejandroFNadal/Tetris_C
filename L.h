#include "square.h"
#include "loadfunc.h"
//angle of L
#define L_ON_L 20
#define L_ON_90 21
#define L_ON_180 22
#define L_ON_270 23

void read_matrix(cuadrado mat[posancho][posalto])
{
	for(int x = 0; x < posancho; x++)
	{
		for(int y =0; y < posalto;y++)
		{
			printf(" %d",mat[x][y].active);
		}
		printf("\n");
	}
}
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
	printf("In L_rotate\n");
	cuadrado temp_block[4];
	int temp_x, temp_y,center_x, center_y;
	cuadrado rotation_matrix[3][3];
	//center detection
	read_matrix(mat);
	if(*current_inclination == L_ON_L || *current_inclination == L_ON_180)
	{
		int right_extreme = detect_right_point(current_block);
		center_x = right_extreme;
		if(*current_inclination == L_ON_L)
		{
			center_y = detect_high_point(current_block)+1;
			*current_inclination = L_ON_270;
		}
		else if(*current_inclination == L_ON_180)
		{
			center_y = detect_high_point(current_block)-1;
		}
	}
	complete_rotation_matrix(mat,rotation_matrix, center_x, center_y);
	matrix_rotation(rotation_matrix);
	//nullyfy every current element
	for(int i = 0; i < 4; i++)
	{
		mat[current_block[i][0]][current_block[i][1]]=nullyfy_square(mat[current_block[i][0]][current_block[i][1]]);
	}
	insert_submatrix_into_matrix(mat,rotation_matrix,current_block, center_x, center_y);

}
