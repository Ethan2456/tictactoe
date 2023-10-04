/*
Authors:Jack Flowers and Ethan Tran
10/9/23
Function Signatures:
game()
new_list()

Description:
Just Tictactoe
.
*/

#include <iostream>
using namespace std;

void game(char list[]){ //This is the game board
    printf("    a       b       c\n");
    printf("\t|\t|\n");
    printf("1   -   |   -   |   -\n");
    printf("\t|\t|\n");
    printf("-------------------------\n");
    printf("\t|\t|\n");
    printf("2   -   |   -   |   -\n");
    printf("\t|\t|\n");
    printf("-------------------------\n");
    printf("\t|\t|\n");
    printf("3   -   |   -   |   -\n");
    printf("\t|\t|\n");
}

void new_list(string coord){
}

//Game.
int main(){
    game();
    //declares array. Number is for amount of squares in tictactoe
    char memory[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    int turn = 1;
    char column;
    int row;
    //Used for deciding turns
    //% 2; if even then player 2 if not player 1
    for(int i = 0; i < 9; i++){
        if(turn % 2 == 0){
            printf("Player 2\n\tEnter row: ");
            cin >> row;
            printf("\tEnter column: ");
            cin >> column;
            turn += 1;
        }
        else{
            printf("Player 1\n\tEnter row: ");
            cin >> row;
            printf("\tEnter column: ");
            cin >> column;
            turn += 1;
        }
    }
    return 0;
}
