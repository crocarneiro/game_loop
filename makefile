all:
	gcc -Wall -std=c99 ./src/*.c -o game

run:
	./game

clean:
	- rm *.o
	- rm game
