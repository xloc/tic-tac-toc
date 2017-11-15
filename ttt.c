#include <stdio.h>
#include "myRand.h"

#define PLAYER_PIECE_SIGN 'x'
#define COMPUTER_PIECE_SIGN 'o'
#define EMPTY_SIGN '.'

#define GAME_OVER_IN_DRAW 0
#define GAME_OVER_PLAYER_WINS 1
#define GAME_OVER_COMPUTER_WINS 2

void printBoard(char board[3][3]);
void clearScreen();

int emptySpaceCount(char board[3][3]);
int checkWin(char board[3][3], char sign);
void playerMove(char board[3][3]);
void computerMove(char board[3][3]);


int main(){
    char board[3][3] = {"...","...","..."};
    int gameOverFlag = GAME_OVER_IN_DRAW;
    printBoard(board);

    while(1){
        if(emptySpaceCount(board) = 0) break;
        playerMove(board);
        clearScreen(); printBoard(board);
        if(checkWin(board, PLAYER_PIECE_SIGN)){
            gameOverFlag = GAME_OVER_PLAYER_WINS;
            break;
        } 

        if(emptySpaceCount(board) = 0) break;
        computerMove(board);
        clearScreen(); printBoard(board);
        if(checkWin(board, COMPUTER_PIECE_SIGN)){
            gameOverFlag = GAME_OVER_COMPUTER_WINS;
            break
        }
        
    }

    switch(gameOverFlag){
    case GAME_OVER_COMPUTER_WINS:
        printf("Computer Wins\n");
        break;
    case GAME_OVER_PLAYER_WINS:
        printf("Player Wins\n");
        break;
    default:
        print("Game Ends in a draw");
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


int emptySpaceCount(char* board){
    int count = 0;
    for(int i=0; i<9; i++){
        if(board[i] == EMPTY_SIGN) count++;
    }
    return count;
}


int checkWin(char board[3][3], char sign){
    if(
        // Pieces in a row
        (board[0][0] == sign && board[0][1] == sign && board[0][2] == sign) ||
        (board[1][0] == sign && board[1][1] == sign && board[1][2] == sign) ||
        (board[2][0] == sign && board[2][1] == sign && board[2][2] == sign) ||
        // Pieces in a column
        (board[0][0] == sign && board[1][0] == sign && board[2][0] == sign) ||
        (board[0][1] == sign && board[1][1] == sign && board[2][1] == sign) ||
        (board[0][2] == sign && board[1][2] == sign && board[2][2] == sign) ||
        // Pieces in diagonal
        (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign) ||
        (board[0][2] == sign && board[1][1] == sign && board[2][0] == sign)
    ) return 1;
    else return 0;
}

int getPositionFromUserInput(){
    int input;

    scanf("%d", &input);
    while(
        // Notice: there is a ! (NOT)
        !(1 <= input && input <= 9)
    ){
        printf("\tInvalid input, try again: ");
        scanf("%d", &input);
    }

    return input;
}

int isBoardEmptyAtPosition(char board[3][3], int x, int y){
    return board[y][x] == EMPTY_SIGN;
}

void playerMove(char board[3][3]){
    printf("Please take a move: ");

    int idx, x, y;

    idx = getPositionFromUserInput() - 1;
    x = idx % 3;
    y = idx / 3;
    while(isBoardEmptyAtPosition(board, x, y)){
        printf("Position (%d,%d) is occupied, try another one: ")
        idx = getPositionFromUserInput() - 1;
        x = idx % 3;
        y = idx / 3;
    }

    board[x][y] = PLAYER_PIECE_SIGN;
}
