#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3]) {
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3]) {
    char winner = '-';
    // COMPLETE

    /* 
        Win by row. 
        |O|O|O|        | | | |        | | | |
        | | | |        |O|O|O|        | | | |
        | | | |        | | | |        |O|O|O|
    */
    for(unsigned int row = 0; row < 3 && winner == '-'; row++) {
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            winner = board[row][0];
        }
    }

    /* 
        Win by column. 
        |X| | |        | |X| |        | | |X|
        |X| | |        | |X| |        | | |X|
        |X| | |        | |X| |        | | |X|
    */
    for(unsigned int column = 0; column < 3 && winner == '-'; column++) {
        if(board[0][column] == board[1][column] && board[1][column] == board[2][column]) {
            winner = board[0][column];
        }
    }

    /* 
        Win by diagonal. 
        |X| | |        | | |O|
        | |X| |        | |O| |
        | | |X|        |O| | |
    */
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        winner = board[1][1];
    }
    else if(board[2][0] == board[1][1] && board[1][1] == board[0][2]){
        winner = board[1][1];
    }

    // COMPLETE
    return winner;
}

bool has_free_cell(char board[3][3]) {
    bool free_cell = false;
    // COMPLETE

    for(unsigned int row = 0; row < 3; row++) {
        for(unsigned int column = 0; column < 3; column++) {
            if(board[row][column] == '-') {
                free_cell = true;
            }
        }
    }

    // COMPLETE
    return free_cell;
}

int main(void) {
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

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
            int row = cell / 3;
            int colum = cell % 3;
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
