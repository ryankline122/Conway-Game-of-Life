#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main(void){

    int steps;
    int count;
    int gCount =0;
    int rCount =0;
    char *mat = (char *) malloc(count*sizeof(char));
    struct Board g;

    scanf("%d %d", &g.nrows, &g.ncols);

    //Add two rows/cols to create wrapping border
    g.nrows += 2;
    g.ncols += 2;
    scanf("%d", &steps);
    count = (g.nrows*g.ncols);


    //Board Pointer to use in update_board function
    struct Board *bptr;
    bptr = (Board *) malloc(sizeof(Board));
    bptr->ncols = g.ncols;
    bptr->nrows = g.nrows;

    //Fills grid cells with specified chars and a border of empty chars
    for (int i=0; i<count;i++){
        if((i + 1) % g.ncols == 0 || //Left
           (i + 1) % g.ncols == 1 || //Right
           i < (g.ncols - 1) || // Top
           i < count && i > count - g.ncols ) // Bottom
                mat[i] = 'b';
        else
            scanf(" %c", &mat[i]);
    }

    //Fill border to wrap
    update_border(mat, g.nrows, g.ncols);

    g.grid = mat;
    bptr->grid = g.grid;

    //Runs update_board function for the number iterations given in stdin
    for(int i=0; i<steps;i++){
        bptr->grid = update_board(bptr)->grid;
   }

    //Counts number of green and red cells
     for (int i=0; i<count;i++){
           if(i > bptr->ncols &&
           i < ((bptr->nrows*bptr->ncols) - bptr->ncols) &&
           i % bptr->ncols != 0 &&
           i % bptr->ncols != 1){
                if(bptr->grid[i-1] == 'g'){
                    gCount+=1;
                }else if(bptr->grid[i-1] == 'r')
                    rCount +=1;
           }
        }
    printf("green: %d, red: %d\n", gCount, rCount);


    free(mat);
    free(bptr);
    return 0;
}
