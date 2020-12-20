main: main.c gamefunc.h loadfunc.h constants.h
	gcc -o tetris main.c gamefunc.h loadfunc.h constants.h -lSDL2 -Wall