/*
Authors:Jack Flowers and Ethan Tran
10/9/23
Function Signatures:
game()
column_to_num()
p1_win_condition()
p2_win_conditon()
robot()

Description:
Lets two people play tictactoe by
entering the row and column of where
they want to put their X or O.
*/

#include <iostream>
#include <time.h>
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
//win condition for player 1 checks for 3 in a row
int p1_win_condition(char list[]){
    if((list[0] == 'X' && list[3] == 'X' && list[6] == 'X')
    || (list[1] == 'X' && list[4] == 'X' && list[7] == 'X')
    || (list[2] == 'X' && list[5] == 'X' && list[8] == 'X')
    || (list[0] == 'X' && list[1] == 'X' && list[2] == 'X')
    || (list[3] == 'X' && list[4] == 'X' && list[5] == 'X')
    || (list[6] == 'X' && list[7] == 'X' && list[8] == 'X')
    || (list[0] == 'X' && list[4] == 'X' && list[8] == 'X')
    || (list[2] == 'X' && list[4] == 'X' && list[6] == 'X')){
        return 0;
    }
    else{
        return 1;
    }
}

//win condition for player 2 checks for 3 in a row
int p2_win_condition(char list[]){
    if((list[0] == 'O' && list[3] == 'O' && list[6] == 'O')
    || (list[1] == 'O' && list[4] == 'O' && list[7] == 'O')
    || (list[2] == 'O' && list[5] == 'O' && list[8] == 'O')
    || (list[0] == 'O' && list[1] == 'O' && list[2] == 'O')
    || (list[3] == 'O' && list[4] == 'O' && list[5] == 'O')
    || (list[6] == 'O' && list[7] == 'O' && list[8] == 'O')
    || (list[0] == 'O' && list[4] == 'O' && list[8] == 'O')
    || (list[2] == 'O' && list[4] == 'O' && list[6] == 'O')){
        return 0;
    }
    else{
        return 1;
    }
}
//function for picking by using random function (robot)
void robot(char list[]){
    int repeat = 0;
    while(repeat == 0){
        int range = 9;
        srand(time(NULL));
        int rand_num = rand();
        rand_num = rand_num % range;
        if(list[rand_num] == '-'){
            list[rand_num] = 'O';
            repeat = 1;
        }
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
    int num_players;

//introduces game and allows to play with robot or 2 people
    printf("Welcome to tictactoe!\nPlayer 1 is X and Player 2 is O.\nWhen choosing a spot, put in the column and then the row. Ex: c2\n");
    printf("Are you playing with 1 player or 2? ");
    cin >> num_players;

    //Used for deciding turns
    //% 2; if even then player 2 if not player 1
    if(num_players == 2){
        game(memory);
        while(turn < 10){
        //checks for which turn V
            if(turn % 2 == 0){
            //allows user to add columns and rows
                printf("Player 2\nEnter spot: ");
                cin >> column >> row;
                while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                    printf("That is not a valid spot. Please choose another spot.\nEnter spot: ");
                    cin >> column >> row;
                }
                num_column = column_to_num(column);
            //checks for if the spot is taken.
                while(memory[(num_column + row) - 1] != '-'){
                    printf("That spot is already taken! Please choose another spot.\nEnter spot: ");
                    cin >> column >> row;
                    while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                        printf("That is not a valid spot. Please choose another spot./nEnter spot: ");
                        cin >> column >> row;
                    }
                    num_column = column_to_num(column);
                }
                turn += 1;
                memory[(num_column + row) - 1] = 'O';
                game(memory);
                //checks for win by using function
                if(p2_win_condition(memory) == 0){
                    printf("Player 2 wins!\n");
                    //sets turn to 100 to stop game.
                    turn = 100;
                }
            }

            else{
            //allows the first player to add column and rows
                printf("Player 1\nEnter spot: ");
                cin >> column >> row;
                while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                    printf("That is not a valid spot. Please choose another spot.\nEnter spot: ");
                    cin >> column >> row;
                }
                num_column = column_to_num(column);
                while(memory[(num_column + row) - 1] != '-'){
                    printf("That spot is already taken! Please choose another spot.\nEnter spot: ");
                    cin >> column >> row;
                    while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                        printf("That is not a valid spot. Please choose another spot.\nEnter spot: ");
                        cin >> column >> row;
                    }
                    num_column = column_to_num(column);
                }
                turn += 1;
                memory[(num_column + row) - 1] = 'X';
                game(memory);
                if(p1_win_condition(memory) == 0){
                    printf("Player 1 wins!\n");
                    turn = 100;
                }
            }
        }
        //if amount of turns less then 100 (means no winner) is tie
        if(turn < 100){
            printf("It's a tie. Neither player wins.\n");
        }
    }

//robot stuff
//same thing expect robot determines spots.
    if(num_players == 1){
        game(memory);
        while(turn < 10){
            if(turn % 2 == 1){
                printf("Player 1\nEnter spot: ");
                cin >> column >> row;
                while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                    printf("That is not a valid spot. Please choose another spot.\nEnter spot: ");
                    cin >> column >> row;
                }
                num_column = column_to_num(column);
                while(memory[(num_column + row) - 1] != '-'){
                    printf("That spot is already taken! Please choose another spot.\nEnter spot: ");
                    cin >> column >> row;
                    while((row > 3) || (row < 1) || ((column != 'a') && (column != 'b') && (column != 'c'))){
                        printf("That is not a valid spot. Please choose another spot.\nEnter spot: ");
                        cin >> column >> row;
                    }
                    num_column = column_to_num(column);
                }
                turn += 1;
                memory[(num_column + row) - 1] = 'X';
                game(memory);
                if(p1_win_condition(memory) == 0){
                    printf("Player 1 wins!\n");
                    turn = 100;
                }
            }
            else{
                robot(memory);
                turn += 1;
                printf("Robot's turn:\n");
                game(memory);
                if(p2_win_condition(memory) == 0){
                    printf("Robot wins!\n");
                    turn = 100;
                }
            }
        }
        if(turn < 100){
            printf("It's a tie. You did not beat the robot.\n");
        }
    }
}
