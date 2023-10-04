/*
Jack Flowers and Ethan Tran
10/9/23
Global Functions
game()
Description
Just Tictactoe.
*/

#include <iostream>
using namespace std;

void game(int list[]){ //This is the game board
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

//Game.
int main(){
    game();
    //declares array. Number is for amount of squares in tictactoe
    int memory[9];
    int turn = 1;
    string input;
    //Used for deciding turns
    //% 2; if even then player 2 if not player 1
    for(int i = 0; i < 9; i++){
        if(turn % 2 == 0){
            cout << "Player 2 ";
            cin >> input;
            turn += 1;
        }
        else{
            cout << "Player 1 ";
            cin >> input;
            turn += 1;
        }
    }
    return 0;
}
