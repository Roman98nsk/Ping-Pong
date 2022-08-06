CC = gcc
FLAGS = -Wall -Wextra -Werror

SOURCE = $(wildcard *.c)

.PHONY:
	all pong clean

all:
	$(CC) $(FLAGS) -c $(SOURCE)
	$(CC) Pong_functions.o Pong_main.o -o ../build/Main

pong:
	$(CC) $(FLAGS) -c $(SOURCE)
	$(CC) Pong_functions.o Pong_main.o -o ../build/Main

test_repeat:
	$(CC) $(FLAGS) -c ../tests/Test_repeat.c
	$(CC) Test_repeat.o -o ../build/Repeat

clean:
	rm *.o ../build/Main
	rm -rf ../.vscode

clean_tests:
	rm ../build/Repeat