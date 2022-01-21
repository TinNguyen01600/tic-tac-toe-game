#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

void print(char character[3][3]);
bool win(char character[3][3], int player_x);
bool draw(char character[3][3]);
void move(char character[3][3], int player_x);