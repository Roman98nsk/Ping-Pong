.PHONY:
	all pong clean

all:
	gcc -Wall -Wextra -Werror -c Pong_main.c
	gcc Pong_main.o -o ../build/Main

pong:
	gcc -Wall -Wextra -Werror -c Pong_main.c
	gcc Pong_main.o -o ../build/Main

clean:
	rm *.o ../build/Main
	rm -rf ../.vscode