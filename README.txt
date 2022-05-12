Alright here is the clue/withcer game

There are a few files

Character, Rooms, Items : Each with a .h and a .c file

There is also adventire.c

Rooms.c/.h
	Here we 4 main parts. 3 function definitions, and a struct definition for a Room
	A room struct has a pointer to 4 directions representing other rooms or null, 
	a name, a pointer representing a character list and a pointer representng an item list

	The three functions: 1. Creates a room, malloc is in the function
			     2. Look command, to see whats inside a room
			     3. cardinalCreator: which sets the NESW directions for each room
				on a 3x3 gameboard


Items.c/.h
	Here we 4 main parts. 3 function definitions, and a struct definition for a item
	A item struct has a name, and a pointer for a item list
	
	The three functions: 1. createItemList: creates a item struct and mallocs
			     2. takePut: does the take and put command functionality
			     3. printItems: prints items from the desired inventory


characters.c/.h
	Here we 5 main parts. 4 function definitions, and a struct definition for a character
	a character struct has a name, a pointer to the characters current location, a pointer
	to their inventory, and a pointer to a character list

	The four functions: 1. createCharacter: creates a character struct and uses malloc
			    2. move: the go command for the main player
			    3. clueMove: to move a character that was guessed in the clue 
			       command
			    4. printChars: prints characters

adventure.c
	This file has the main code for the game. There is a randomizer function that randomizes 
	the gameboard. As well as functions for all the other user commands, such as help, list, and clue
	All of the items, characters, and rooms are initialized and then randomized
