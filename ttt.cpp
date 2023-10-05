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
    printf("3   %c   |   %c   |   %c\n", list[2], list[5], list[8]);
    printf("\t|\t|\n");
}

void new_list(char column, int row){
}

//Game.
int main(){
    //declares array. Number is for amount of squares in tictactoe
    char memory[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    int turn = 1;
    char column;
    int row;
    //Used for deciding turns
    //% 2; if even then player 2 if not player 1
    game(memory);
    for(int i = 0; i < 9; i++){
        if(turn % 2 == 0){
        //allows user to add columns and rows
            printf("Player 2\nEnter row: ");
            cin >> row;
            printf("Enter column: ");
            cin >> column;
            turn += 1;
            if(column == 'a'){
                memory[(0 + row) - 1] = 'X';
            }
            else if(column == 'b'){
                memory[(3 + row) - 1] = 'X';
            }
            else{
                memory[(6 + row) - 1] = 'X';
            }
            game(memory);
        }
        else{
        //allows user to add columns and rows
            printf("Player 1\nEnter row: ");
            cin >> row;
            printf("Enter column: ");
            cin >> column;
            turn += 1;
            if(column == 'a'){
                memory[(0 + row) - 1] = 'O';
            }
            else if(column == 'b'){
                memory[(3 + row) - 1] = 'O';
            }
            else{
                memory[(6 + row) - 1] = 'O';
            }
            game(memory);
        }
    }
    return 0;
}
