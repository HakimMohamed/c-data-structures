CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = main.exe

# All source files (but NOT main.c)
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))

all: build/$(TARGET)

# Link everything into final binary
build/$(TARGET): build/main.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile main.c separately
build/main.o: main.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c main.c -o $@

# Compile each .c file from src/
build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
