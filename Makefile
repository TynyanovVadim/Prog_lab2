all: main

main.o: src/main.c
	gcc -c -Wall -Werror -o main.o src/main.c

IntVector.o: src/IntVector.c
	gcc -c -Wall -Werror -o IntVector.o src/IntVector.c

main: IntVector.o main.o
	gcc -Wall -Werror -o main IntVector.o main.o
