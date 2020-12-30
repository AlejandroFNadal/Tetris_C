#include "square.h"
#define LINE_ON_SIDE 10
#define LINE_VERTICAL 11

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

int check_line_rotation(cuadrado mat[posancho][posalto],int current_block[4][2])
{
	//return 0 if no rotation is possible
	//return 1 if left rotation is possible
	//return 2 if right rotation is possible
	return 1;
}

void line_rotate(cuadrado mat [posancho][posalto], int current_block[4][2], int spin_direction,int *current_inclination)
{
	cuadrado temp_block[4];
	int temp_x,temp_y;
	int high_point = posalto; //to be used when the line is vertical
	int center_point = 0; //to be used when the line is on the side
	//here we rotate to left or right the line
	for(int k = 0; k < 4; k++)//copy each block
	{	
		temp_x = current_block[k][0];
		temp_y = current_block[k][1];
		temp_block[k]= mat[temp_x][temp_y];
		center_point+=temp_x;
		if(temp_y < high_point)
		{
			high_point = temp_y;
		}
		mat[temp_x][temp_y] = nullyfy_square(mat[temp_x][temp_y]);
		
	}
	center_point= center_point / 4; // average the center;
	if(*current_inclination == LINE_VERTICAL && spin_direction == 1)//actual line rotation. Each line moves a block to where it should rotate
	{	
		//sorry, I know it is a complex piece of code, but I did not find any other way to do this except making every change in a line
		for(int k = temp_x-1; k < temp_x+3; k++)
		{
			mat[k][high_point]=temp_block[k-temp_x+1];
			current_block[k-temp_x+1][0]=k;
		}

		current_block[0][1] = current_block[1][1] = current_block[2][1]= current_block[3][1]= high_point;
		*current_inclination = LINE_ON_SIDE;
	}
	else if(*current_inclination == LINE_ON_SIDE && spin_direction == LEFT)
	{
	    for(int k = 0; k < 4; k++)
	    {
	        mat[center_point][high_point+k] = temp_block[k];
            current_block[k][1] = high_point + k;
	    	current_block[k][0] = center_point;
	    }
	    *current_inclination = LINE_VERTICAL;
	}	
}

