#include <stdio.h>

void printBoard(char board[3][3]){
    for(int i=0; i<3; i++){
        printf("%c%c%c\n", board[i][0], board[i][1], board[i][2]);
    }
}

int main(){
    char board[3][3] = {"...","...","..."};
    printBoard(board);
    
    return 0;
}