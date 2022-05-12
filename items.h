#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Item {
    char *name;
    struct Item *next;
};
//creates item
struct Item* createItemList(char* name, struct Item* next);

//take and drop functionality, can take item from location  and drop item at a location
bool takePut(char* name, struct Item** giverListHead, struct Item** targetList);

//prints items
void printItems(struct Item* itemList);
