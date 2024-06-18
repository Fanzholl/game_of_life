#include "game_of_life.h"
#include <stdio.h>
#include <stdlib.h>

// Функция для инициализации сетки
void initializeGrid(Grid *grid) {
    grid->grid = (int**) malloc(ROWS * sizeof(int*)); // Выделение памяти для строк
    for (int i = 0; i < ROWS; ++i) {
        grid->grid[i] = (int*) malloc(COLS * sizeof(int)); // Выделение памяти для столбцов в каждой строке
        for (int j = 0; j < COLS; ++j) {
            grid->grid[i][j] = 0; // Инициализация всех ячеек нулями
        }
    }
}

// Функция для освобождения памяти сетки
void freeGrid(Grid *grid) {
    for (int i = 0; i < ROWS; ++i) {
        free(grid->grid[i]); // Освобождение памяти для каждой строки
    }
    free(grid->grid); // Освобождение памяти для указателя на строки
}

// Функция для инициализации сетки из файла
void initializeGridDataFromFile(Grid *grid, const char* filename) {
    FILE *file = fopen(filename, "r"); // Открытие файла для чтения
    if (!file) {
        perror("Error opening file"); // Вывод ошибки в случае неудачи
        exit(EXIT_FAILURE); // Завершение программы с ошибкой
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int c = fgetc(file); // Чтение символа из файла
            if (c == EOF || c == '\n') break; // Прерывание цикла в случае конца файла или строки
            if (c == '0' || c == '1') {
                grid->grid[i][j] = c - '0'; // Преобразование символа в число
            } else {
                --j; // Повторное чтение в случае неверного символа
            }
        }
        while (fgetc(file) != '\n' && !feof(file)); // Пропуск оставшихся символов в строке
    }

    fclose(file); // Закрытие файла
}

// Функция для вывода сетки на экран
void printGrid(const Grid *grid) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            mvprintw(i, j, "%c", (grid->grid[i][j]) ? 178 : ' '); // Вывод живых клеток как '178', мертвых как пробел
        }
    }
}

// Функция для подсчета живых соседей клетки
int countAliveNeighbors(const Grid *grid, int x, int y) {
    int aliveNeighbors = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Пропуск самой клетки
            int newX = (x + i + ROWS) % ROWS; // Вычисление координат с учетом цикличности
            int newY = (y + j + COLS) % COLS;
            aliveNeighbors += grid->grid[newX][newY]; // Подсчет живых соседей
        }
    }
    return aliveNeighbors;
}

// Функция для расчета следующего поколения сетки
void calcNextGeneration(const Grid *grid, Grid *nextGrid) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int aliveNeighbors = countAliveNeighbors(grid, i, j); // Подсчет живых соседей
            nextGrid->grid[i][j] = (grid->grid[i][j]) ? (aliveNeighbors == 2 || aliveNeighbors == 3) : (aliveNeighbors == 3); // Правила игры
        }
    }
}

// Функция для копирования одной сетки в другую
void copyGrid(Grid *dest, const Grid *src) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            dest->grid[i][j] = src->grid[i][j]; // Копирование значения каждой ячейки
        }
    }
}

// Функция для обработки ввода пользователя
void handleInput(int *delay, int ch) {
    switch (ch) {
        case 'f': // Ускорение игры
            *delay = (*delay > 50) ? *delay - 50 : *delay;
            break;
        case 's': // Замедление игры
            *delay = (*delay < 2000) ? *delay + 50 : *delay;
            break;
    }
}

// Функция для инициализации ncurses
void initializeNcurses() {
    if (initscr() == NULL) {
        fprintf(stderr, "Error initializing ncurses.\n"); // Вывод ошибки в случае неудачи
        exit(EXIT_FAILURE);
    }
    cbreak(); // Отключение буферизации ввода
    noecho(); // Отключение отображения вводимых символов
    curs_set(FALSE); // Скрытие курсора
    timeout(0); // Неблокирующий ввод
    keypad(stdscr, TRUE); // Включение функциональных клавиш
}

// Функция для завершения ncurses
void finalizeNcurses() {
    endwin(); // Завершение ncurses
}