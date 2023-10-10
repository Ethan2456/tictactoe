/*
Authors:Jack Flowers and Ethan Tran
10/9/23
Function Signatures:
game()
column_to_num()
win_condition()


Description:
Lets two people play tictactoe by
entering the row and column of where
they want to put their X or O.
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

//allows for the placement of the column by converting into letter.
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

int win_condition(char list[]){
    if((list[0] == 'X' && list[3] == 'X'  && list[6] == 'X')
       || (list[1] == 'X' && list[4] == 'X' && list[7] == 'X')){
        return 0;
    }
    else{
    return 1;
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
    int winning = 0;

    //Used for deciding turns
    //% 2; if even then player 2 if not player 1
while(winning != 1){
    game(memory);
    for(int i = 0; i < 9; i++){
    //checks for which turn V
        if(turn % 2 == 0){
        //allows user to add columns and rows
            printf("Player 2\nEnter spot: ");
            cin >> row >> column;
            while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                printf("That is not a valid spot. Please choose another spot.\nEnter spot: ");
                cin >> row >> column;
            }
            num_column = column_to_num(column);
        //checks for if the spot is taken.
            while(memory[(num_column + row) - 1] != '-'){
                printf("That spot is already taken! Please choose another spot.\nEnter spot: ");
                cin >> row >> column;
                while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                    printf("That is not a valid spot. Please choose another spot./nEnter spot: ");
                    cin >> row >> column;
                }
                num_column = column_to_num(column);
            }
            turn += 1;
            memory[(num_column + row) - 1] = 'O';
            game(memory);
            if(win_condition(memory) == false){
                winning = 1;
            }
        }

        else{
        //allows the first player to add column and rows
            printf("Player 1\nEnter spot: ");
            cin >> row >> column;
            while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                printf("That is not a valid spot. Please choose another spot.\nEnter spot: ");
                cin >> row >> column;
            }
            num_column = column_to_num(column);
            while(memory[(num_column + row) - 1] != '-'){
                printf("That spot is already taken! Please choose another spot.\nEnter spot: ");
                cin >> row >> column;
                while ((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                    printf("That is not a valid spot. Please choose another spot.\nEnter spot: ");
                    cin >> row >> column;
                }
                num_column = column_to_num(column);
            }
            turn += 1;
            memory[(num_column + row) - 1] = 'X';
            game(memory);
            if(win_condition(memory) == false){
                winning = 1;
            }
        }

}

if(winning == 1){
cout << "you win.";
}


    }
    return 0;
}
