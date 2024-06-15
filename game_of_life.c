#include <stdio.h>
#include <stdlib.h>

void initializeGridData(int grid[25][80], int size[2]);
void printGrid(int grid[25][80], int size[2]);

int main(void) {
    int grid[25][80]; // Инициализация массива сетки поля.
    int nextGrid[25][80]; // Инициализация массива сетки следуещего шага эволюции игрового поля.
    int size[2] = {25, 80}; // Инициализация массива с данными, о размере массива сетки.



    return 0;
}

void initializeGridData(int grid[25][80], int size[2]) {
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            grid[i][j] = rand() % 2;
        }
    }  
}

void printGrid(int grid[25][80], int size[2]) {
    for (int i = 0; i < size[0]; i++) {

    }
}