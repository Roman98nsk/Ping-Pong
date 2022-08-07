CC = gcc
FLAGS = -Wall -Wextra -Werror

.PHONY:
	all clean

all: build/Main

build/Main: obj/Pong_functions.o obj/Pong_main.o
	$(CC) $(FLAGS) obj/Pong_functions.o obj/Pong_main.o -o build/Main

build/Repeat: obj/Test_repeat.o
	$(CC) $(FLAGS) obj/Test_repeat.o -o build/Repeat

build/Draw: obj/Test_draw.o
	$(CC) $(FLAGS) obj/Test_draw.o -o build/Draw

obj/Pong_functions.o: src/Pong_functions.c
	$(CC) $(FLAGS) -c src/Pong_functions.c -o obj/Pong_functions.o

obj/Pong_main.o: src/Pong_main.c
	$(CC) $(FLAGS) -c src/Pong_main.c -o obj/Pong_main.o

obj/Test_repeat.o: tests/Test_repeat.c
	$(CC) $(FLAGS) -c tests/Test_repeat.c -o obj/Test_repeat.o

obj/Test_draw.o: tests/Test_draw.c
	$(CC) $(FLAGS) -c tests/Test_draw.c -o obj/Test_draw.o

clean:
	rm build/Main obj/*.o
	rm -rf .vscode

clean_tests:
	rm obj/*.o
	rm build/Repeat build/Draw