#include "rooms.h"
#include "items.h"
#include "character.h"

//creates and mallocs room
struct Room* createRoom(struct Room* north, struct Room* east, struct Room* south, struct Room* west, struct Item* itemList, char* name, struct Character* charList) {
   struct Room* room = (struct Room*) malloc(sizeof(struct Room));
   room->north = north;
   room->east = east;
   room->south = south;
   room->west = west;
   room->itemList = itemList;
   room->name = name;
   room->charList = charList;
   return room;
}
//Print out contents in room
void look(struct Room* room) {
   printf("\nName: %s\n", room->name);
   printf("\nCharacters: \n");
   printChars(room->charList);
   printf("\nItems: \n");
   printItems(room->itemList);

   printf("\nRooms:\n");
   if (room->north!=NULL){
   	printf("North: %s\n", (room->north)->name);
   }
   if (room->east!=NULL){
        printf("East: %s\n", (room->east)->name);
   }
   if (room->south!=NULL){
        printf("South: %s\n", (room->south)->name);
   }
   if (room->west!=NULL){
        printf("West: %s\n", (room->west)->name);
   }
}
//Sets directions for rooms in a 3x3 gameboard
void cardinalCreator(struct Room* clueGame[3][3]) {
   for(int i =0; i < 3; i++){
    for(int j =0; j < 3; j++){
	if (i == 0) {
	  clueGame[i][j]->north = NULL;
          clueGame[i][j] -> south = clueGame[i+1][j];
	}
	if (j == 0){
	  clueGame[i][j]->east = clueGame[i][j+1];
          clueGame[i][j] ->west = NULL;
        }
	if (i == 1) {
          clueGame[i][j]->north = clueGame[i-1][j];
          clueGame[i][j] -> south = clueGame[i+1][j];
        }
	if (j == 1){
          clueGame[i][j]->east = clueGame[i][j+1];
          clueGame[i][j] ->west = clueGame[i][j-1];
        }
	if (i == 2) {
        clueGame[i][j]->north = clueGame[i-1][j];
        clueGame[i][j] ->south = NULL;
        }
	if (j == 2){
          clueGame[i][j]->east = NULL;
          clueGame[i][j] ->west = clueGame[i][j-1];
        }
    }
   }
}
