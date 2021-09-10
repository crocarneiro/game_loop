all:
	gcc ./src/*.c -o game -Wall -std=c99 -lSDL2

run:
	./game

clean:
	- rm *.o
	- rm game
