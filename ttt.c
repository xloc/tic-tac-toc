#include <stdio.h>

#define PLAYER_PIECE_SIGN 'x'
#define COMPUTER_PIECE_SIGN 'o'

void printBoard(char board[3][3]);
void clearScreen();

int emptySpaceCount(char board[3][3]);
int checkWin(char board[3][3], char sign);
int playerMove(char board[3][3]);
int computerMove(char board[3][3]);


int main(){
    char board[3][3] = {"...","...","..."};
    printBoard(board);

    while(emptySpaceCount(board) > 0){
        playerMove(board);
        if(checkWin(board, PLAYER_PIECE_SIGN)){
            printf("Player wins\n");
        }

        computerMove(board);
        if(checkWin(board, COMPUTER_PIECE_SIGN)){
            printf("Computer wins\n");
        }

        clearScreen();
        printBoard(board);
    }
    
    return 0;
}


void printBoard(char board[3][3]){
    for(int i=0; i<3; i++){
        printf("%c%c%c\n", board[i][0], board[i][1], board[i][2]);
    }
}


void clearScreen(){
    printf("\n\n\n\n\n\n\n\n\n\n\n");
}