#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <assert.h>  /* assert() */

#define SIZE 5
#define CELL_MAX (SIZE * SIZE - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[SIZE][SIZE]) {
    int cell = 0;

    print_sep(SIZE);
    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(SIZE);
    }
}

char get_winner(char board[SIZE][SIZE]) {
    char winner = '-';
    // COMPLETE

    /* 
        Win by row. 
        |O|O|O|        | | | |        | | | |
        | | | |        |O|O|O|        | | | |
        | | | |        | | | |        |O|O|O|
    */
    for(unsigned int row = 0; row < SIZE; row++) {
        bool equal_row = true;

        for(unsigned int column = 1; column < SIZE && equal_row; column++) {
            if(board[row][0] != board[row][column]) {
                equal_row = false;
            }
        }

        if(equal_row && board[row][0] != '-') {
            winner = board[row][0];
        }
    }

    /* 
        Win by column. 
        |X| | |        | |X| |        | | |X|
        |X| | |        | |X| |        | | |X|
        |X| | |        | |X| |        | | |X|
    */
    for(unsigned int column = 0; column < SIZE; column++) {
        bool equal_column = true;

        for(unsigned int row = 1; row < SIZE && equal_column; row++) {
            if(board[0][column] != board[row][column]) {
                equal_column = false;
            }
        }

        if(equal_column && board[0][column] != '-') {
            winner = board[0][column];
        }
    }

    /* 
        Win by diagonal. 
        |X| | |        | | |O|
        | |X| |        | |O| |
        | | |X|        |O| | |
    */
    bool equal_diagonal_left_right = true;
    for(unsigned int row = 1, column = 1; row < SIZE && equal_diagonal_left_right; row++) {
        if(board[0][0] != board[row][column]) {
            equal_diagonal_left_right = false;
        } else {
            column++;
        }
        
        if (equal_diagonal_left_right && column == SIZE) {
            winner = board[0][0];
        }
    }

    bool equal_diagonal_right_left = true;
    for(int row = 1, column = SIZE-2; row < SIZE && equal_diagonal_right_left; row++) {
        if(board[0][SIZE-1] != board[row][column]) {
            equal_diagonal_right_left = false;
        } else {
            column--;
        }
        
        if (equal_diagonal_right_left && column < 0) {
            winner = board[0][SIZE-1];
        }
    }

    // COMPLETE
    return winner;
}

bool has_free_cell(char board[SIZE][SIZE]) {
    bool free_cell = false;
    // COMPLETE

    for(unsigned int row = 0; row < SIZE && !free_cell; row++) {
        for(unsigned int column = 0; column < SIZE && !free_cell; column++) {
            if(board[row][column] == '-') {
                free_cell = true;
            }
        }
    }

    // COMPLETE
    return free_cell;
}

int main(void) {
    printf("TicTacToe [CoMpLeTo :B]\n");
    char board[SIZE][SIZE];

    for (unsigned int row = 0; row < SIZE; row++) {
        for (unsigned int column = 0; column < SIZE; column++) {
            board[row][column] = '-';
        }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado.\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / SIZE;
            int colum = cell % SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\n¡Celda ocupada!\n");
            }
        } else {
            printf("\n¡Celda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("¡Empate!\n");
    } else {
        printf("Ganó %c.\n", winner);
    }
    return 0;
}
