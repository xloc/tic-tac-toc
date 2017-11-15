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

int emptySpaceCount(char* board);
int checkWin(char board[3][3], char sign);
void playerMove(char board[3][3]);
void computerMove(char board[3][3]);


int main(){
    initRandSeed();

    char board[3][3] = {"...","...","..."};
    int gameOverFlag = GAME_OVER_IN_DRAW;
    printBoard(board);

    while(1){
        if(emptySpaceCount(board) == 0) break;
        playerMove(board);
        clearScreen(); printBoard(board);
        if(checkWin(board, PLAYER_PIECE_SIGN)){
            gameOverFlag = GAME_OVER_PLAYER_WINS;
            break;
        } 

        if(emptySpaceCount(board) == 0) break;
        computerMove(board);
        clearScreen(); printBoard(board);
        if(checkWin(board, COMPUTER_PIECE_SIGN)){
            gameOverFlag = GAME_OVER_COMPUTER_WINS;
            break;
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
        printf("Game Ends in a draw\n");
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

// There is another approach to return values from a function
// It is particularly useful when multiple values need returning
void idx2xy(int idx, int *x, int *y){
    *x = idx % 3;
    *y = idx / 3;
}

void playerMove(char board[3][3]){
    printf("Please take a move: ");

    int x, y;

    idx2xy(getPositionFromUserInput() - 1, &x, &y);
    while(!isBoardEmptyAtPosition(board, x, y)){
        printf("Position (%d,%d) is occupied, try another one: ", x, y);
        idx2xy(getPositionFromUserInput() - 1, &x, &y);
    }

    board[y][x] = PLAYER_PIECE_SIGN;
}

void computerMove(char board[3][3]){
    int emptyCount = 0, emptyIndexes[9];
    for(int i=0; i<9; i++){
        if( ((char*)board)[i] == EMPTY_SIGN ){
            // Record empty cell index
            emptyIndexes[emptyCount++] = i;
        }
    }
    
    int ridx;
    // Evaluate random number for selecting an item from emptyIndexes
    ridx = getRand() * emptyCount;
    // Index the corresponding element  from emptyIndexes
    // (which is the random empty position of chess board)
    ridx = emptyIndexes[ridx];
    // Flatten the 3x3 board array to 1x9, assign piece sign
    ((char*)board)[ridx] = COMPUTER_PIECE_SIGN;
}