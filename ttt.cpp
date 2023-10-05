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

int column_to_num(char column){
    if(column == 'a'){
        return 0;
    }
    else if(column == 'b'){
        return 3;
    }
    else{
        return 6;
    }
}

//Game.
int main(){
    //declares array. Number is for amount of squares in tictactoe
    char memory[] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    int turn = 1;
    char column;
    int row;
    int num_column;
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
            num_column = column_to_num(column);
            while(memory[(num_column + row) - 1] != '-'){
                printf("That spot is already taken! Please choose another spot.\nEnter row: ");
                cin >> row;
                printf("Enter column: ");
                cin >> column;
                num_column = column_to_num(column);
            }
            memory[(num_column + row) - 1] = 'X';
            game(memory);
        }
        else{
        //allows user to add columns and rows
            printf("Player 1\nEnter row: ");
            cin >> row;
            printf("Enter column: ");
            cin >> column;
            turn += 1;
            num_column = column_to_num(column);
            while(memory[(num_column + row) - 1] != '-'){
                printf("That spot is already taken! Please choose another spot.\nEnter row: ");
                cin >> row;
                printf("Enter column: ");
                cin >> column;
                num_column = column_to_num(column);
            }
            memory[(num_column + row) - 1] = 'O';
            game(memory);
        }
    }
    return 0;
}
