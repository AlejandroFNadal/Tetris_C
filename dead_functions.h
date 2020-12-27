bool gravity(cuadrado mat[posancho][posalto])
{
    bool move_occur = false;
    //these for go backwards because if not, when a series of blocks must go down, those below that should move will 
    //move after those above and cause movement problems
    for(int x =posancho-1; x>=0 ;x--)
    {
        for(int y = posalto-1;y >= 0;y--)
        {
            if(mat[x][y].active == true && mat[x][y].moving==true)
            {
                if(y < posalto-1 && mat[x][y+1].active ==false)
                {
                    printf("Move down in %d %d\n", x,y);
                    //CREATE DEACTIVATE FUNCTION FOR THIS
                    mat[x][y+1].active = true;
                    if(y < posalto-2) //stop last line for moving
                    {
                        mat[x][y+1].moving = true;
                    }
                    else{
                        mat[x][y+1].moving = false;
                    }
                    mat[x][y+1].r=mat[x][y].r;
                    mat[x][y+1].g=mat[x][y].g;
                    mat[x][y+1].b=mat[x][y].b;
                    mat[x][y].r=0;
                    mat[x][y].b=0;
                    mat[x][y].g=0;
                    mat[x][y].active=false;
                    mat[x][y].moving=false;
                    move_occur=true;
                }
                if(mat[x][y+2].active == true)
                {
                    mat[x][y].moving= false;
                }
            }
        }
    }
    return move_occur;
}

void single_move(cuadrado mat[posancho][posalto],int x, int y, int next_x, int next_y)
{
    mat[next_x][next_y].active=true;
    mat[next_x][next_y].r=mat[x][y].r;
    mat[next_x][next_y].g=mat[x][y].g;
    mat[next_x][next_y].b=mat[x][y].b;
    mat[x][y].active=false;
    mat[x][y].moving= false;
    mat[next_x][next_y].moving=true;
}