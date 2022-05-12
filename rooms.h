#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Room {
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
    struct Item *itemList;
    char *name;
    struct Character* charList;
    //struct Character characterList[10];//may need to be pointer
};
//creates room
struct Room* createRoom(struct Room* north, struct Room* east, struct Room* south, struct Room* west, struct Item* itemList, char* name, struct Character* charList);
//prints out room items
void look(struct Room* room);
//creates directions for each room in 3x3 gameboard
void cardinalCreator(struct Room* clueGame[3][3]);
