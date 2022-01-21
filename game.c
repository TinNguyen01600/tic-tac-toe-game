#include "game.h"

void print(char character[3][3]){
    system("cls");
    printf(" _____ _____ _____\t\tControl: _____ _____ _____ \n");
    for (int  i = 0; i<3; i++){
        printf("|     |     |     |\t\t\t|     |     |     |\n");
        for (int j = 0; j<3; j++){
            printf("|  %c  ", character[i][j]);
        }
        printf("|\t\t\t");
        for (int j = 0; j<3; j++){
            printf("|  %d  ", j+7-3*i);
        }
        printf("|\t\t\t\n");
        printf("|_____|_____|_____|\t\t\t|_____|_____|_____|\n");
    }
}

bool win(char character[3][3], int player_x){
    int sum_row[3] = {0,0,0};
    int sum_col[3] = {0,0,0};
    int sum_diag[3] = {0,0,0};
    int player_x_ascii = 3*(player_x == 1? 88:79);
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            sum_col[i] += character[j][i];
            sum_row[i] += character[i][j];
        }
        sum_diag[0] += character[i][i];
        sum_diag[1] += character[i][2-i];
    }
    for (int i = 0; i<3; i++){
        if(sum_row[i] == player_x_ascii || sum_col[i] == player_x_ascii || sum_diag[i] == player_x_ascii) {
            return true; break;
        }
    }
}

bool draw(char character[3][3]){
    int count = 0;
    for(int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            if(character[i][j] != 32) {count++;}
        }
    }
    if (count == 9) { return true; }
    else { return false; }
}

void move(char character[3][3], int player_x){
    int k; char ch;
    print(character);
    printf("\nEnter player %d move: ", player_x);
    while (1){
        if(kbhit()){
            ch = getch();
            for (int i = 49; i<58; i++){
                if ((int)ch == i) {k = i-48; break;}
            }
            break;
        }
    }
    printf("%d \n", k);
    Sleep(500);
    int i = (9-k)/3; int j = k-7+3*i;
    if(character[i][j] != 32){
        printf("Invalid move!! Try again\n");
        Sleep(2100);
        move(character, player_x);
    }
    else{
        character[i][j] = player_x == 1? 88:79;
        if(win(character, player_x)) {
            print(character);
            printf("\nPLAYER %d WINS !!!", player_x);
            Sleep(2000);
        }
        else if (draw(character)) { 
            print(character);
            printf("\nDRAW !!!");
            Sleep(2000);
        }
        else {move(character, abs(player_x-2)+1);} 
    }
}