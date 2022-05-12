#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Character {
  char* name;
  struct Room* currLoc;
  struct Item* inventory;
  struct Character* next;
};
//Creates character
struct Character* createCharacter(char* name, struct Room* currLoc, struct Item* inventory, struct Character* next);
//Moves main player
bool move(struct Character *character, char *direction);
//Moves character chosen in clue guess
bool clueMove(char* name, struct Character** giverListHead, struct Character** targetList);
//prints our characters
void printChars(struct Character* charList);
