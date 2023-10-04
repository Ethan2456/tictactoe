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
    printf("1   %c   |   %c   |   %c\n", list[0], list[3], list[6]);
    printf("\t|\t|\n");
    printf("-------------------------\n");
    printf("\t|\t|\n");
    printf("2   %c   |   %c   |   %c\n", list[1], list[4], list[7]);
    printf("\t|\t|\n");
    printf("-------------------------\n");
    printf("\t|\t|\n");
    printf("3   %c   |   %c   |   %c\n", list[2] list[5], list[8]);
    printf("\t|\t|\n");
}

void new_list(char column, int row){
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
    game(memory[]);
    for(int i = 0; i < 9; i++){
        if(turn % 2 == 0){
        //allows user to add columns and rows
            printf("Player 2\n\tEnter row: ");
            cin >> row;
            printf("\tEnter column: ");
            cin >> column;
            turn += 1;
        }
        else{
        //allows user to add columns and rows
            printf("Player 1\n\tEnter row: ");
            cin >> row;
            printf("\tEnter column: ");
            cin >> column;
            turn += 1;
        }
    }
    return 0;
}
