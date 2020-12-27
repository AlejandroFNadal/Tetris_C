#include <SDL2/SDL.h>
#include <stdio.h>
#include "loadfunc.h"
#include <stdlib.h>
#include <stdbool.h>
#include "line.h"
#include "L.h"
#define LEFT 1
#define RIGHT 2
#define ROTATE 3
#define L_BLOCK 4
#define LINE_BLOCK 5

//Prototypes
void single_move(cuadrado mat[posancho][posalto],int x, int y, int next_x, int next_y);
void move(cuadrado mat[posancho][posalto], int current_block[4][2], int where); //LEFT = 1, RIGHT = 2


void keyboard_reading(SDL_Surface *screenSurface, SDL_Window *window, SDL_Event ev_control, cuadrado mat[posancho][posalto], int current_block[4][2])
{
    while(SDL_PollEvent(&ev_control)){
                if(ev_control.type == SDL_KEYDOWN)
                {
                    printf("Key pressed\n");
                    if(ev_control.key.keysym.sym == SDLK_ESCAPE)
                    {
                        printf("Escape pressed\n");
                        cerrar(window,screenSurface);
                        exit(0);
                    }
                    if(ev_control.key.keysym.sym==SDLK_LEFT)
                    {
                        move(mat, current_block,LEFT);
                    }
                    else if(ev_control.key.keysym.sym == SDLK_RIGHT)
                    {
                    	move(mat, current_block, RIGHT);
                    }
		    else if(ev_control.key.keysym.sym == SDLK_UP)
		    {
		    	move(mat,current_block,ROTATE);
		    }
                    
                }
            }
}
void move(cuadrado mat[posancho][posalto],int current_block[4][2],int where)
{
    cuadrado temp_block[4];
    bool move_posible = true; //assuming this, then, checking if cannot be done
    for(int k = 0; k < 4; k++) //checking if any block is touching the border already
    {
        int temp_x = current_block[k][0];
        int temp_y = current_block[k][1];
        if(temp_x == 0 && where == LEFT || where == LEFT && mat[temp_x-1][temp_y].active && mat[temp_x-1][temp_y].moving == false)
        {
            move_posible = false;
        }
        if(temp_x == posancho -1 && where == RIGHT || where == RIGHT && mat[temp_x+1][temp_y].active && mat[temp_x+1][temp_y].moving == false)
        {
            move_posible = false;
        }
        
    }
    if(move_posible)
        {
            for(int k = 0; k < 4; k++) // copy every block to be moved and destroy originals
            {
                int temp_x = current_block[k][0];
                int temp_y = current_block[k][1];
                temp_block[k]=mat[temp_x][temp_y];
                mat[temp_x][temp_y] = nullyfy_square(mat[temp_x][temp_y]);
            }
            for(int k = 0; k < 4; k++)
            {
                int temp_x = current_block[k][0];
                int temp_y = current_block[k][1];
                if(where == LEFT)
                {
                    mat[temp_x-1][temp_y]=temp_block[k]; //move block to the left
                    current_block[k][0]--; //change reference position value
                }
                else{
                    mat[temp_x+1][temp_y]=temp_block[k]; // move block to the right
                    current_block[k][0]++; // change reference position value
                }
            }
        }
    
    
    
}


void detect_full_bottom(cuadrado mat[posancho][posalto])
{
    bool eliminate = true;
    for(int x = 0; x < posancho;x++)
    {
        if(mat[x][posalto-1].active==false)
        {
            eliminate = false;
            break;
        }
    }
    if(eliminate == true)
    {
        printf("Detecting full bottom\n");
        /*for(int x = 0; x < posancho;x++)
        {
            mat[x][posalto-1].active=false;
            mat[x][posalto-1].r=0;
            mat[x][posalto-1].b=0;
            mat[x][posalto-1].g=0;
            mat[x][posalto-1].moving=false;
        }*/
        for(int x = 0; x < posancho;x++)
        {
            for(int y = posalto-2; y >=0;y--)
            {
                mat[x][y+1]=mat[x][y];
            }
        }
    }
}
void readMatrix(cuadrado mat[posancho][posalto])
{
    for(int x = 0; x < posancho; x++)
    {
        for(int y = 0; y < posalto;y++)
        {
            printf(" %d", mat[x][y].active);
        }
        printf("\n");
    }
    printf("\n");
}
bool gravity2(cuadrado mat[posancho][posalto], int current_line_position[4][2])
{
    bool stop_object = false;
    bool move_occur = false;
    for(int k = 0; k < 4;k++) //touching the ground detection
    {
        int temp_x = current_line_position[k][0];
        int temp_y = current_line_position[k][1];
        if(temp_y == posalto -1 )
        {
            //Essentially, if any block of the object touched ground
            stop_object= true;
        }
        else if(mat[temp_x][temp_y+1].active && !mat[temp_x][temp_y+1].moving)
        {
                //Or if the block touches a non moving block
                stop_object=true;
        }
    }
    if(!stop_object) // move every block down
    {
        move_occur=true;
        cuadrado temp_block[4];
        for(int k = 0; k < 4;k++) //copy every block and destroy it
        {
            int temp_x = current_line_position[k][0];
            int temp_y = current_line_position[k][1];
            temp_block[k] = mat[temp_x][temp_y];
            mat[temp_x][temp_y] = nullyfy_square(mat[temp_x][temp_y]);
            
        }
        for(int k = 0; k < 4;k++) //paste the temporal blocks one step down
        {
            int temp_x = current_line_position[k][0];
            int temp_y = current_line_position[k][1];
            mat[temp_x][temp_y+1] = temp_block[k];
            current_line_position[k][1]++; 
        }
    }
    else{ //stop every element of the object
        for(int k = 0; k < 4;k++)
        {
            int temp_x = current_line_position[k][0];
            int temp_y = current_line_position[k][1];
            mat[temp_x][temp_y].moving=false;
            current_line_position[k][0]=current_line_position[k][1] = 0;
        }
    }
    return move_occur;
}


void borders(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderDrawLine(renderer,inimatriz_x,inimatriz_y,inimatriz_x,finmatriz_y);
    SDL_RenderDrawLine(renderer,inimatriz_x,inimatriz_y,finmatriz_x,inimatriz_y);
    SDL_RenderDrawLine(renderer,finmatriz_x,inimatriz_y,finmatriz_x,finmatriz_y);
    SDL_RenderDrawLine(renderer,inimatriz_x,finmatriz_y,finmatriz_x,finmatriz_y);

}



void create_random_block(cuadrado mat[posalto][posancho])
{
    crear_cuadrado(rand() % posancho,0,255,255,255,mat);
}

void dibujar_matriz(SDL_Renderer *renderer,cuadrado mat[posancho][posalto])
{
    int x;
    int y;
    for(x=0;x<posancho;x++)
    {
        for(y=0;y<posalto;y++)
        {
            if(mat[x][y].active == true){
                SDL_SetRenderDrawColor(renderer,mat[x][y].r,mat[x][y].g,mat[x][y].b,255);
                SDL_Rect temp_r={x*cuadrado_ancho +100,y*cuadrado_alto + 100,cuadrado_ancho,cuadrado_alto};
                //dibujar cuadrado aqui
                if(renderer == NULL)
                {
                    printf("Problema con renderer\n");
                }
                SDL_RenderFillRect(renderer, &temp_r);
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                SDL_RenderDrawRect(renderer,&temp_r);
                SDL_Delay(1);
            }
        }
    }
    
}

