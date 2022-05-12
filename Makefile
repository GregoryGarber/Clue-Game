SRC = adventure.c character.c rooms.c items.c 
OBJ = adventure.o charactes.o rooms.o items.o
PROG = witcherGame

$(PROG): $(SRC)
	gcc -std=c99 -g $(SRC) -o $(PROG)


