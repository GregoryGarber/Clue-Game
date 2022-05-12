#include "items.h"
#include "rooms.h"
#include "character.h"
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

//randomizes gameboard
struct Room** createGame(struct Character* charArr[6], struct Room* roomArr[9], struct Item* itemArr[6], struct Room* witcherBoard[3][3]){
   srand(time(NULL));
   int ranNum;
   bool boolArr[9] = {false, false, false, false, false, false, false, false, false};
   bool check = false;
//randomly places items in rooms
   for (int i = 0; i < 6; i++){
      while(!check) {
         ranNum = rand() % 9;
         if(!boolArr[ranNum]) {
      	   roomArr[ranNum]->itemList = itemArr[i];
           check = true;
           boolArr[ranNum] = true;
         }
      }
      check = false;
   }
   for (int i = 0; i < 9; i++) {
      boolArr[i] = false;
   }
//randomly places characters in rooms
   for (int i = 0; i < 6; i++){
      while(!check) {
         ranNum = rand() % 9;
         if(!boolArr[ranNum]) {
           roomArr[ranNum]->charList = charArr[i];
           charArr[i]->currLoc = roomArr[ranNum];
           check = true;
           boolArr[ranNum] = true;
         }
      }
      check = false;
   }
   for (int i = 0; i < 9; i++) {
      boolArr[i] = false;
   }
//randomly places rooms on gameboard
   for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
       while(!check) {
          ranNum = rand() % 9;
          if(!boolArr[ranNum]) {
             witcherBoard[i][j] = roomArr[ranNum];
             check = true;
             boolArr[ranNum] = true;
          }
       }
       check = false;
    }
    check = false;
   }
}
//Gets a random item for the final answer
struct Item* ranItem(struct Item* itemArr[6]){
   srand(time(NULL));
   int ranNum;
   ranNum = rand() % 6;
   return itemArr[ranNum];
}
//gets a random room for the final answer
struct Room* ranRoom(struct Room* roomArr[9]){
   srand(time(NULL));
   int ranNum;
   ranNum = rand() % 9;
   return roomArr[ranNum];
}
//gets a final character fir the final answer
struct Character* ranChar(struct Character* charArr[6]){
   srand(time(NULL));
   int ranNum;
   ranNum = rand() % 6;
   return charArr[ranNum];
}
//prints out all commans
void help() {
   printf("Commands:\nhelp\nlist\nlook\ngo\ntake\ndrop\ninventory\nclue\n");
}
//prints out all rooms, characters, and items
void list(struct Item* itemArr[6], struct Room* roomArr[9], struct Character* charArr[6]){
   printf("Rooms: \n");
   for (int i = 0; i < 9; i++){
      printf("%s\n", roomArr[i]->name);
   }
   printf("Items:\n");
   for (int i = 0; i < 6; i++){
      printf("%s\n", itemArr[i]->name);
   }

   printf("Characters:\n");
   for (int i = 0; i < 6; i++){
      printf("%s\n", charArr[i]->name);
   }
}
//checks if for clue guess, the player is in correct room and correct item is in possession or in room
bool clueRoomAndItem(struct Character* geralt, char* answer[3]){
   struct Item* itemChecker = geralt->inventory;
   struct Item* roomChecker = geralt->currLoc->itemList;
   struct Character* charChecker = geralt->currLoc->charList;
   bool check = true;
   bool charItem = false;
   bool roomItem = false;
   bool charCheck = false;
   if (strcmp(geralt->currLoc->name,answer[0])!=0) {
      check = false;
   }
   else {
      printf("Room match");
   }
   while(itemChecker != NULL) {
      if (strcmp(itemChecker->name,answer[1])==0) {
         printf("Item Match");
         charItem = true;
      }
      itemChecker = itemChecker->next;
   }
   while(roomChecker != NULL){
      if (strcmp(roomChecker->name,answer[1])==0){
         printf("Item Match");
         roomItem = true;
      }
      roomChecker = roomChecker->next;
   }
   if (!charItem && !roomItem){
      check = false;
   }
   while(charChecker != NULL) {
      if (strcmp(charChecker->name,answer[2])==0) {
         printf("Character Match");
         charCheck = true;
      }
      charChecker = charChecker->next;
   }
   if (!charCheck) {
      check = false;
   }
   return check;
}

int main(void){
//character creation
   struct Character* geralt = createCharacter("Geralt of Rivea",NULL, NULL, NULL);
   struct Character* Yennefer = createCharacter("Yennefer",NULL,NULL, NULL);
   struct Character* Ciri = createCharacter("Ciri",NULL,NULL, NULL);
   struct Character* Dandelion = createCharacter("Dandelion",NULL,NULL, NULL);
   struct Character* Cahir = createCharacter("Cahir",NULL,NULL, NULL);
   struct Character* Fringilla = createCharacter("Fringilla",NULL,NULL, NULL);
   struct Character* Tissaia = createCharacter("Tissaia",NULL,NULL, NULL);

   struct Character* charArr[6] = {Yennefer, Ciri, Dandelion, Cahir, Fringilla, Tissaia};
//room creation
   struct Room* Cintra = createRoom(NULL, NULL, NULL, NULL, NULL, "Cintra", NULL);
   struct Room* Redania = createRoom(NULL, NULL, NULL, NULL, NULL, "Redania", NULL);
   struct Room* Temeria = createRoom(NULL, NULL, NULL, NULL, NULL, "Temeria", NULL);
   struct Room* Nilfgaard = createRoom(NULL, NULL, NULL, NULL, NULL, "Nilfgaard", NULL);
   struct Room* Nivellens_Manor = createRoom(NULL, NULL, NULL, NULL, NULL, "Nivellens Manor", NULL);
   struct Room* Kaer_Morhen = createRoom(NULL, NULL, NULL, NULL, NULL, "Kaer Morhen", NULL);
   struct Room* Aretuza = createRoom(NULL, NULL, NULL, NULL, NULL, "Aretuza", NULL);
   struct Room* Gors_Velen = createRoom(NULL, NULL, NULL, NULL, NULL, "Gors Velen", NULL);
   struct Room* Oxenfurt = createRoom(NULL, NULL, NULL, NULL, NULL, "Oxenfurt", NULL);

   struct Room* roomArr[9] = {Cintra, Redania, Temeria, Nilfgaard, Nivellens_Manor, Kaer_Morhen, Aretuza, Gors_Velen, Oxenfurt};
//item creation
   struct Item* sword = createItemList("sword", NULL);
   struct Item* dagger = createItemList("dagger", NULL);
   struct Item* bow = createItemList("bow", NULL);
   struct Item* magic = createItemList("magic", NULL);
   struct Item* club = createItemList("club", NULL);
   struct Item* mace = createItemList("mace", NULL);

   struct Item* itemArr[6] = {sword, dagger, bow, magic, club, mace};
//board set up
   struct Room* witcherBoard[3][3] = {Cintra, Redania, Temeria, Nilfgaard, Nivellens_Manor, Kaer_Morhen, Aretuza, Gors_Velen, Oxenfurt};
   createGame(charArr, roomArr, itemArr, witcherBoard);
   cardinalCreator(witcherBoard);
//correct answer generation
   struct Room* randRoom = ranRoom(roomArr);
   struct Item* randItem = ranItem(itemArr);
   struct Character* randChar = ranChar(charArr);
   char* answer[3] = {randRoom->name, randItem->name, randChar->name};
//variables necessary for game functionality
   char* guess[3];
   char play[20];//for user command input
   char direction[7];//for user direction input
   char itemPicked[10];//for user item input
   char charPicker[20];//for user character input
   bool correct = false;//see if answer has been guessed
   bool corrDirec = false;//check if a valid direction has been inputted
   bool corrItem = false;//check if a valid item has been inputted
   bool corrChar = false;//check if a valid character has been inputted
   geralt->currLoc = witcherBoard[1][1];

   printf("Welcome to the Witcher Clue Game, Here are your commands\n");
   help();
   printf("\nYou may begin by typing in a command\n");
   printf("You here someone whispering through the walls about %s", answer[2]);
   while(!correct){
      printf("\nPick a command\n");
      scanf("%[^\n]%*c", play);
      if (strcmp(play,"help")==0){
          help();
      }
      else if (strcmp(play,"list")==0){
         list(itemArr, roomArr, charArr);
      }
      else if (strcmp(play,"look")==0){
         look(geralt->currLoc);
      }
      else if (strcmp(play,"go")==0){
         while(!corrDirec){
            printf("\nPick a direction: north, east, south, west\n");
            scanf("%[^\n]%*c", direction);
            corrDirec = move(geralt, direction);
         }
         corrDirec = false;
      }
      else if (strcmp(play,"take")==0){
         while(!corrItem){
            printf("\nPick and item to take\n");
            scanf("%[^\n]%*c", itemPicked);
            corrItem = takePut(itemPicked, &(geralt->currLoc->itemList), &(geralt->inventory));
         }
         corrItem = false;
      }
      else if (strcmp(play,"drop")==0){
         while(!corrItem){
            printf("\nPick an item to drop\n");
            scanf("%[^\n]%*c", itemPicked);
            corrItem = takePut(itemPicked, &(geralt->inventory), &(geralt->currLoc->itemList));
         }
         corrItem = false;
      }
      else if (strcmp(play,"inventory")==0){
         printItems(geralt->inventory);
      }
      else if (strcmp(play,"clue")==0){
         while(!corrChar){
            printf("\npick a character\n");
            scanf("%[^\n]%*c", charPicker);
            if (strcmp(charPicker,"Yennefer")==0){
               corrChar = clueMove(charPicker, &(Yennefer->currLoc->charList), &(geralt->currLoc->charList));
            }
            else if (strcmp(charPicker,"Ciri")==0){corrChar = clueMove(charPicker, &(Ciri->currLoc->charList),&( geralt->currLoc->charList));}
            else if (strcmp(charPicker,"Dandelion")==0){corrChar = clueMove(charPicker, &(Dandelion->currLoc->charList), &(geralt->currLoc->charList));}
            else if (strcmp(charPicker,"Cahir")==0){corrChar = clueMove(charPicker, &(Cahir->currLoc->charList), &(geralt->currLoc->charList));}
            else if (strcmp(charPicker,"Fringilla")==0){corrChar = clueMove(charPicker, &(Fringilla->currLoc->charList), &(geralt->currLoc->charList));}
            else if (strcmp(charPicker,"Tissaia")==0){corrChar = clueMove(charPicker, &(Tissaia->currLoc->charList), &(geralt->currLoc->charList));}
            else {printf("\nIncorrect character Spelling, try again\n");};
         }
         if (clueRoomAndItem(geralt, answer)) {
	       printf("\nCongratulations, you win!\n");
               correct = true;
         }
         else {printf("\nIncorrect, try again\n");}
      }
      else {
	printf("\nNot a command, please try again\n");
      }
   }

   for (int i = 0; i<3; i++){
    for (int j = 0; j<3; j++){
       //free items in room
       while(witcherBoard[i][j]->itemList != NULL) {
          struct Item* prevItem;
          prevItem = witcherBoard[i][j]->itemList;
          witcherBoard[i][j]->itemList = witcherBoard[i][j]->itemList->next;
          free(prevItem);
       }
       free(witcherBoard[i][j]->itemList);
       //free characters in room
       while(witcherBoard[i][j]->charList != NULL) {
          struct Character* prevChar;
          prevChar = witcherBoard[i][j]->charList;
          witcherBoard[i][j]->charList = witcherBoard[i][j]->charList->next;
          free(prevChar);
       }
       free(witcherBoard[i][j]->charList);
       free(witcherBoard[i][j]);//free room
    }
   }
   //free inventory of player
   while(geralt->inventory != NULL){
      struct Item* prevItem2;
      prevItem2 = geralt->inventory;
      geralt->inventory = geralt->inventory->next;
      free(prevItem2);
   }
   free(geralt->inventory);
   free(geralt);
   return 0;
}

