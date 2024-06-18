#include "game_of_life.h"
#include <stdlib.h>

int main(void) {
    Grid grid, nextGrid; // Создание двух сеток: текущая и следующая
    int delay = 500; // Начальная задержка (скорость игры)
    const char* filename = "glider_gun.txt"; // Имя файла с начальным состоянием

    initializeGrid(&grid); // Инициализация текущей сетки
    initializeGrid(&nextGrid); // Инициализация следующей сетки
    initializeGridDataFromFile(&grid, filename); // Загрузка начального состояния из файла
    initializeNcurses(); // Инициализация ncurses

    while (1) {
        int ch = getch(); // Чтение символа с клавиатуры
        if (ch == 'q' || ch == 'Q') break; // Выход из цикла при нажатии 'q' или 'Q'
        handleInput(&delay, ch); // Обработка ввода пользователя

        calcNextGeneration(&grid, &nextGrid); // Расчет следующего поколения
        copyGrid(&grid, &nextGrid); // Копирование следующего поколения в текущую сетку
        clear(); // Очистка экрана
        printGrid(&grid); // Вывод сетки на экран
        refresh(); // Обновление экрана
        napms(delay); // Задержка перед следующей итерацией
    }

    finalizeNcurses(); // Завершение ncurses
    freeGrid(&grid); // Освобождение памяти текущей сетки
    freeGrid(&nextGrid); // Освобождение памяти следующей сетки
    return EXIT_SUCCESS; // Завершение программы
}
