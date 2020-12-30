#ifndef LOADFUNC_H
#define LOADFUNC_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"
#include "square.h"
int crear_ventana(SDL_Window* window, SDL_Surface *screenSurface,SDL_Renderer *renderer)
{
    printf("Creando Ventana\n");
    window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        printf("window could not be created, SDL_Error %s\n",SDL_GetError());
        return -1;
    }
    else
    {
        screenSurface = SDL_GetWindowSurface(window);
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer == NULL)
        {
            printf("renderer could not be created, SDL_Error %s\n",SDL_GetError());
            return -1;
        }
        else
        {
            return 0;    
        }
    }
    
    
}

void cerrar(SDL_Window *window, SDL_Surface *screenSurface)
{
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_FreeSurface(screenSurface);
    //Quit SDL subsystems
    SDL_Quit();
}

int detect_high_point(int block[4][2])
{
    int high_point = 100000;
    for(int i =0;i<4;i++)
    {
        if(block[i][1] < high_point){
            high_point=block[i][1];
        }
    }
    return high_point;
}
int detect_low_point(int block[4][2])
{
    int low_point = 0;
    for(int i =0;i<4;i++)
    {
        if(block[i][1] > low_point){
            low_point=block[i][1];
        }
    }
    return low_point;
}
int detect_left_point(int block[4][2])
{
    int left_point = 100000;
    for(int i =0;i<4;i++)
    {
        if(block[i][0] < left_point){
            left_point=block[i][0];
        }
    }
    return left_point;
}

int detect_right_point(int block[4][2])
{
    int right_point = 0;
    for(int i =0;i<4;i++)
    {
        if(block[i][0] > right_point){
            right_point=block[i][0];
        }
    }
    return right_point;
}

void complete_rotation_matrix(cuadrado mat[posancho][posalto],cuadrado rotation_matrix[3][3],int center_x, int center_y)
{
    int centered_x;
    int centered_y;
    //I think the usage of center will not easily work for lines
    //printf("In matrix rotation\n");
    printf("In complete rotation matrix\n");

    for(int i = 0; i < 3;i++)
    {
        for(int j = 0; j < 3; j++)
        {
            centered_x = center_x -1+i;
            centered_y = center_y -1+j;
            rotation_matrix[i][j]= mat[centered_x][centered_y];
        }
    }
    printf("In complete_rotation_matrix\n");
    printf("After completion\n");
    for(int i = 0;i<3;i++){
        for(int j = 0;j< 3; j++)
        {
            printf("%d ",rotation_matrix[i][j].moving);
        }
        printf("\n");
    }
}

void matrix_rotation(cuadrado matrix[3][3])
{
    printf("In matrix rotation\n");
    printf("Before rotation\n");
    for(int i = 0;i<3;i++){
        for(int j = 0;j< 3; j++)
        {
            printf("%d ",matrix[i][j].moving);
        }
        printf("\n");
    }
    cuadrado temp_matrix[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            temp_matrix[j][i]=matrix[i][j];
        }
    }
    for(int i = 0; i < 3;i++)
    {
        for(int j = 0; j < 3;j++)
        {
            matrix[i][j]=temp_matrix[i][j];
            printf("%d ",matrix[i][j].moving);
        }
        printf("\n");
    }
}
void insert_submatrix_into_matrix(cuadrado mat[posancho][posalto], cuadrado submat[3][3], int current_block[4][2], int center_x, int center_y)
{
    int origin_x = center_x-1;
    int origin_y = center_y-1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(submat[i][j].moving == true)
            {
                mat[origin_x+i][origin_y+j]=submat[i][j];
                current_block[i][0]= origin_x + i;
                current_block[i][1]= origin_y + j;
            }
        }
    }
}
#endif
