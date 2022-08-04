.PHONY:
	all pong clean

all:
	gcc -Wall -Wextra -Werror -c Pong_functions.c Pong_main.c
	gcc Pong_functions.o Pong_main.o -o ../build/Main

pong:
	gcc -Wall -Wextra -Werror -c Pong_functions.c Pong_main.c
	gcc Pong_functions.o Pong_main.o -o ../build/Main

test_repeat:
	gcc -Wall -Wextra -Werror -c ../tests/Test_repeat.c
	gcc Test_repeat.o -o ../build/Repeat

#test_score:
#	gcc -Wall -Wextra -Werror -c ../tests/Test_score.c
#	gcc Test_scre.o -o ../build/Score

clean:
	rm *.o ../build/Main
	rm -rf ../.vscode

clean_tests:
	rm ../build/Repeat