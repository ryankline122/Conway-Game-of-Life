#ifndef BOARD_H
#define BOARD_H

typedef struct Board{
    char *grid;
    int nrows;
    int ncols;
}Board;

Board* update_board(Board* g);

char* update_border(char* mat, int rows, int cols);


#endif
