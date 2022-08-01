.PHONY:
	all pong clean

all:
	gcc -Wall -Wextra -Werror -c Pong_main.c
	gcc -o Main Pong_main.o

pong:
	gcc -Wall -Wextra -Werror -c Pong_main.c
	gcc -o Main Pong_main.o

clean:
	rm Main *.o
	rm -rf .vscode