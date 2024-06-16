Реализована "Игра в жизнь" через терминал на языке C в интерактивном режиме с возможностью смены скорости игры и загрузкой стартового поля 80 на 25 символом из файла grid.txt. Возможна безболезненная реализация динамической генерации сетки поля (немного измените функцию initializeGridDataFromFile(), заменив всё, что там есть на генерацию нуля или единицы для каждой из перебираемых клеток при помощи библиотек <time.h> и <stdlib.h>. 

Управление:
s - ускорить игру на 50ms;
f - замедлить игру на 50ms;
q - выйти из игры и закончить исполнение программы;

https://github.com/Fanzholl/game_of_life/assets/58570733/a216ef74-a954-43b7-adfb-4f1b1648950b

Рекомендации по компиляции через Makefile: make && ./game_of_life.out или make && ./game_of_life.exe.

Славного времени суток и приятной игры!

______________________________________________________________________________________________________________________________________________________

The "Game of life" is implemented through a terminal in C in interactive mode with the ability to change the speed of the game and load the starting field 80 by 25 characters from a file grid.txt . A painless implementation of dynamic field grid generation is possible (slightly change the initializeGridDataFromFile() function, replacing everything that is there with generating zero or one for each of the cells being sorted using <time> libraries.h> and <stdlib.h>. 

Controls:
s - speed up the game by 50ms;
f - slow down the game by 50ms;
q - exit the game and finish the program execution;

Recommendations for compiling via Makefile: make && ./game_of_life.out or make && ./game_of_life.exe .

Have a nice time of day and have a nice game!


Пример кода изменения функции\Example of a function change code (initializeGridDataFromFile(data)):
```
void initializeGridData(int grid[25][80], int size[2]) {
    for (int i = 0; i < size[0]; i++) { // Проходим по каждой строке сетки.
        for (int j = 0; j < size[1]; j++) { // Проходим по каждому столбцу в текущей строке.
            grid[i][j] = rand() % 2; // Инициализация каждого элемента сетки случайным значением 0 или 1.
        }
    }
}
```
