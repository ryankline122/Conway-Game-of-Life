#include <stdio.h>
#include <stdlib.h>
#include "board.h"


Board* update_board(Board* g){
    //Array of index values that need to be updated in the next iteration
    int *index_to_update = (int *) malloc((g->nrows*g->ncols)*sizeof(int));
    //Array of chars that will replace cells being changed in each iteration
    char *char_to_update = (char *) malloc((g->nrows*g->ncols)*sizeof(char));

    for(int i = 0; i<g->ncols*g->nrows;i++){
        int neighbors = 0;
        int gCount = 0;
        int rCount = 0;

        //grid[i] is not part of the wrapping border
        if(i > g->ncols &&
           i < ((g->nrows*g->ncols) - g->ncols) &&
           i % g->ncols != 0 &&
           i % g->ncols != (g->ncols -1)){

            //Neighbor indexes
            int N = i - g->ncols;
            int NE = i - (g->ncols -1);
            int E = i + 1;
            int SE = i + g->ncols + 1;
            int S = i + g->ncols;
            int SW = i + g->ncols - 1;
            int W = i - 1;
            int NW = i - (g->ncols + 1);

            //Checks status of neighbors, adds to neighbor count if 'g' or 'r'

            //NORTH
            if(g->grid[N] == 'r'){
                neighbors+=1;
                rCount+=1;
            }else if(g->grid[N] == 'g'){
                neighbors+=1;
                gCount+=1;
            }

            //NORTHEAST
            if(g->grid[NE] == 'r'){
                neighbors+=1;
                rCount+=1;
            }else if(g->grid[NE] == 'g'){
                neighbors+=1;
                gCount+=1;
            }

            //EAST
            if(g->grid[E] == 'r'){
                neighbors+=1;
                rCount+=1;
            }else if(g->grid[E] == 'g'){
                neighbors+=1;
                gCount+=1;
            }

            //SOUTHEAST
            if(g->grid[SE] == 'r'){
                neighbors+=1;
                rCount+=1;
            }else if(g->grid[SE] == 'g'){
                neighbors+=1;
                gCount+=1;
            }

            //SOUTH
            if(g->grid[S] == 'r'){
                neighbors+=1;
                rCount+=1;
            }else if(g->grid[S] == 'g'){
                neighbors+=1;
                gCount+=1;
            }

            //SOUTHWEST
            if(g->grid[SW] == 'r'){
                neighbors+=1;
                rCount+=1;
            }else if(g->grid[SW] == 'g'){
                neighbors+=1;
                gCount+=1;
            }

            //WEST
            if(g->grid[W] == 'r'){
                neighbors+=1;
                rCount+=1;
            }else if(g->grid[W] == 'g'){
                neighbors+=1;
                gCount+=1;
            }

            //NORTHWEST
            if(g->grid[NW] == 'r'){
                neighbors+=1;
                rCount+=1;
            }else if(g->grid[NW] == 'g'){
                neighbors+=1;
                gCount+=1;
            }

        //IF >3 LIVING NEIGHBORS, or < 2 LIVING NEIGHBORS, DIE
            if(neighbors > 3 || neighbors < 2){
                index_to_update[i] = i;
                char_to_update[i] = 'x';
                }

        //IF DEAD AND 3 LIVING NEIGHBORS, ALIVE (TAKES COLOR OF THE MAJORITY)
            else if(g->grid[i] == 'x' && neighbors == 3){
                if(gCount > rCount){
                    index_to_update[i] = i;
                    char_to_update[i] = 'g';
                }else{
                    index_to_update[i] = i;
                    char_to_update[i] = 'r';
                }
            //If cell does not change
            }else{
            index_to_update[i] = -1;
            char_to_update[i] = 'n';
        }
        //If i is Border cell
        }else{
        index_to_update[i] = i;
        char_to_update[i] = 'b';
        }
    }


    //Update Cells of Board b
    for(int i = 0; i<g->nrows*g->ncols;i++){
        if(index_to_update[i] != -1){
            g->grid[i] = char_to_update[i];
        }
    }
    update_border(g->grid, g->nrows, g->ncols);

    free(index_to_update);
    free(char_to_update);

    return g;
}

//Updates the wrapping border
char* update_border(char* mat, int rows, int cols){
        int count = rows*cols;

        for (int i=0; i<count; i++){
            if (mat[i] == 'b'){

            //TOP ROW
                //Top left corner
                if(i == 0){
                    int corner = cols * (rows -2) + (cols -2);
                    mat[i] = mat[corner];
                }
                //Top right corner
                else if(i == (cols -1)){
                    int corner = cols *(rows - 2) + (1 % (cols + 2));
                    mat[i] = mat[corner];

                }
                //Top row
                else if(i < cols){
                    int topRow = cols *(rows - 2) + (i % (cols + 2));
                    mat[i] = mat[topRow];
                }
           //BOTTOM ROW
                //Bottom left corner
                else if(i == (rows -1) * (cols)){
                    int corner = (cols * 2) -2;
                    mat[i] = mat[corner];

                }
                //Bottom right corner
                else if(i == (rows * cols) - 1){
                    mat[i] = mat[cols + 1];
                }
                //Bottom row
                else if(i > (rows -1) * (cols) &&
                        i < (rows*cols) - 1){
                    int bottom = (i % cols) + cols;
                    mat[i] = mat[bottom];
                }
         //LEFT/RIGHT BORDER
                else if(i % cols == 0){
                    mat[i] = mat[(i + cols) -2];
                }
                else{
                    mat[i] = mat[(i - cols) + 2];
                }
            }
        }
        return mat;
    }
