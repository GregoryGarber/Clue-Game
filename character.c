#include "character.h"
#include "rooms.h"
#include "items.h"


//Creates a Character struct pointer, mallocs to create space
struct Character* createCharacter(char* name, struct Room* currLoc, struct Item* inventory, struct Character* next){
   struct Character *character = (struct Character*)malloc(sizeof(struct Character));
   character->name = name;
   character->currLoc = currLoc;
   character->inventory = inventory;
   character->next = next;
   return character;
}
//Prints character list, used for character list in a room
void printChars(struct Character* charList){
   if (charList == NULL) {
     printf("\nNone. \n");
     return;
   }
   struct Character* charChecker = charList;
   while(charChecker != NULL) {
    printf("%s\n", charChecker->name);
    charChecker = charChecker->next;
   }
}
//moves main player throughout the gameboard
bool move(struct Character* character, char* direction) {
   if (strcmp(direction, "north") == 0){
      if(character->currLoc->north == NULL) {
	printf("\nCant move that way\n");
        return false;
      }
      character->currLoc = character->currLoc->north;
      printf("\nMoved to: %s\n", (character->currLoc)->name);
   }
   else if (strcmp(direction, "east") == 0){
	if(character->currLoc->east == NULL) {
        printf("\nCant move that way\n");
        return false;
      }
      character->currLoc = character->currLoc->east;
      printf("\nMoved to: %s\n", (character->currLoc)->name);
   }
   else if (strcmp(direction, "south") == 0){
	if(character->currLoc->south == NULL) {
        printf("\nCant move that way\n");
        return false;
      }
      character->currLoc = character->currLoc->south;
      printf("\nMoved to: %s\n", (character->currLoc)->name);
   }
   else if (strcmp(direction, "west") == 0){
	if(character->currLoc->west == NULL) {
        printf("\nCant move that way\n");
        return false;
      }
      character->currLoc = character->currLoc->west;
      printf("\nMoved to: %s\n", (character->currLoc)->name);
   }
   else {
      printf("\nDirection does not exist\n");
      return false;
   }
   return true;
}
//Moves the character chosen in the clue guess
bool clueMove(char* name, struct Character** giverListHead,  struct Character** targetList) {
   struct Character* giverCheck = *giverListHead;
   struct Character* giverFixer = NULL;
   struct Character* toTarget = NULL;
   struct Character* targetCheck = NULL;
//gets and removes target characater from its current location
   while(giverCheck != NULL) {
     if (strcmp(name, giverCheck->name) == 0){
        if (giverFixer == NULL) {
           toTarget = *giverListHead;
           *giverListHead = giverCheck->next;
        }else {
           toTarget = giverCheck;
           giverFixer->next = giverCheck->next;
        }
    }
    giverFixer = giverCheck;
    giverCheck = giverCheck->next;
  }
//Moves target to target location
  if (toTarget != NULL) {
   toTarget->next = NULL;
   if (targetCheck == NULL) {
     *targetList = toTarget;
   }else {
     while (targetCheck != NULL) {
      if (targetCheck->next == NULL) {
       targetCheck->next = toTarget;
       break;
      }
      targetCheck = targetCheck->next;
     }
   }
  }
  else {
   return false;
  }
  return true;
}
