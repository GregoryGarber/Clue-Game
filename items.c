#include "items.h"

//creates and mallocs Item struct
struct Item* createItemList(char* name, struct Item* next){
   struct Item* item = (struct Item*) malloc(sizeof(struct Item));
   item->name = name;
   item->next = next;
   return item;
}
//funcionality to take and place a an item from its location to its target:both take and drop
bool takePut(char* name, struct Item** giverListHead, struct Item** targetList) {
   struct Item* giverCheck = *giverListHead;
   struct Item* giverFixer = NULL;
   struct Item* toTarget = NULL;
   struct Item* targetCheck = *targetList;
//takes item from its location
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
//brings target to its target location
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
    printf("\nItem not in location or incorrect spelling\n");
    return false;
  }
  return true;
}
//prints items
void printItems(struct Item* itemList) {
   if (itemList == NULL) {
      printf("\nNone.\n");
      return;
   }
   struct Item* itemChecker = itemList;
   while(itemChecker != NULL) {
      printf("%s\n",itemChecker->name);
      itemChecker = itemChecker->next;
   }
}

