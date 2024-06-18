#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <ncurses.h>

// Определение размеров сетки
#define ROWS 25
#define COLS 80

// Структура для хранения сетки
typedef struct {
    int **grid; // Указатель на двумерный массив
} Grid;

// Прототипы функций
void initializeGrid(Grid *grid);
void freeGrid(Grid *grid);
void initializeGridDataFromFile(Grid *grid, const char* filename);
void printGrid(const Grid *grid);
void calcNextGeneration(const Grid *grid, Grid *nextGrid);
int countAliveNeighbors(const Grid *grid, int x, int y);
void copyGrid(Grid *dest, const Grid *src);
void handleInput(int *delay, int ch);
void initializeNcurses();
void finalizeNcurses();

#endif // GAME_OF_LIFE_H
