# Имя исполняемого файла
TARGET = game_of_life

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Флаги для линковки с библиотекой ncurses
LDFLAGS = -lncurses

# Исходные файлы и объектные файлы
SRCS = main.c game_of_life.c
OBJS = $(SRCS:.c=.o)

# Правило для сборки всего проекта
all: $(TARGET)

# Правило для создания исполняемого файла из объектных файлов
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Правило для компиляции исходных файлов в объектные файлы
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для очистки скомпилированных файлов
clean:
	rm -f $(OBJS) $(TARGET)

# Указывает, что цели 'all' и 'clean' не являются файлами
.PHONY: all clean