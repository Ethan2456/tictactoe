#include <iostream>
using namespace std;

void game(int list[]){
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
int main(){
    game();
    int memory[9];
    int turn = 1;
    string input;
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
