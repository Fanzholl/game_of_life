# Имя исполняемого файла
TARGET = game_of_life

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -I/usr/local/opt/ncurses/include
LDFLAGS = -L/usr/local/opt/ncurses/lib -lncurses

# Файлы проекта
SRCS = game_of_life.c
OBJS = $(SRCS:.c=.o)

# Правило по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Правило для сборки объектных файлов
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка скомпилированных файлов
clean:
	rm -f $(OBJS) $(TARGET)

# Пересборка проекта
rebuild: clean all

.PHONY: all clean rebuild