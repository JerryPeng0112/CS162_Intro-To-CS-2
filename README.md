# CS162 - Intro to Computer Science 2
## Assignment 1 - Print State & County infomation
**To Compile:** `make`  
**To Run:** `./facts -s # -f filename`  

This program read state and county information from specified text file, and print out statistical results.

Example text file `test.txt` is included.

The text file contain information in this order:  
`State_name state_pop #_county`  
`county_name county_pop county_income county_house #_cities city_name`  
`...`  

This program requires command line arguments:  
1. "-s" means the parameter for the number of state data to read from file, the "#" is placeholder for the number.
2. "-f" means the parameter for filename.

Example: `./facts -s 2 -f test.txt` means read 2 state data from test.txt.

## Assignment 2 - Blackjack Game
**To Compile:** `make`  
**To Run:** `./blackjack`  

This program is a blackjack tournament game. The first program where I used classes and objects in C++.

This blackjack tournament supports up to 8 players. In each turn, a player can do the following actions:
1. Hit
2. Stay
3. Double Down (If the player's dealt card total is between 9 and 11)
4. Split (If the player's dealt 2 cards have the same number)

If a player's game total is over 4 times the initial amount of money at the start of game, the player wins the game.
If all players go bankrupt, the game is over and no one wins.

## Assignment 3 - Zoo Tycoon Game
**To Compile:** `make`  
**To Run:** `./zoo`  

This game is the second assignment to use classes and objects.

In this zoo tycoon game, the player owns the zoo. Each animals have different cost, number of babies, food cost, and payoff from visitors.

Each turn is a day, and animals turn adult when they are 3 days old. After each day, the following event can happen:
1. A sickness occurs in the zoo: the player will be asked which animal to be saved, but the animal will still die due to severe sickness.
2. A boom in zoo attendance: each tiger generates bonus payoff, 250-500.
3. A baby animal is born: the player will be asked which animal will have babies. The baby will have age of 0 days.
4. Nothing happens.

The player can unlock legendary animal, the orcas, by building an aquarium to host the animals.

## Assignment 4 - Hunt the Wumpus Game
**To Compile:** `make`  
**To Run:** `./wumpus -s #` where "#" needs to be between 4 and 12.  

This game is called Hunt the Wumpus. 

At the start of the game, the player is placed is randomly placed in a room in a cave grid. The cave grid is consisted of rooms. Each room can contain one or no event. The following are the event types:

1. Wumpus
2. Pits
3. Bats
4. Gold

The goal of the game is to acquire the gold, kill the Wumpus with your arrows, and go back to starting position to exit the cave.

Each turn, the player can either move, or fire an arrow. 

When the player moves to a new room, the player can sense surrounding rooms (rooms directly adjacent to the room) using their "percept" ability; this means the player will be notified if any events are present in the surrounding rooms. 

If the player fires an arrow, the player can choose which direction to shoot the arrow at. The arrow can travel 3 rooms, or less if it hits a wall (edge of the grid). If the arrow hits Wumpus, the Wumpus is killed. Otherwise, the Wumpus will be startled by the sound of the arrow and has 75% chance of moving to a different room. The player only carries 3 arrows, so if all the arrows are used up and the Wumpus is not killed, the game is over.

If the player goes to a room where Wumpus is, the player loses.  
If the player goes to a room where there is a pit, the player falls into the pit and die.  
If the player goes to a room where there is a bat, the player will be carried by the bat, and randomly dropped to a different room.  
If the player goes to a room where there is gold, the player will pick up the gold. The gold can only be copied once.  

## Assignment 5 - Doubly Linked List
**To Compile:** `gcc list.c test_list.c -o list`  
**To Run:** `./list`  

This program includes an implementation of a doubly-linked list.

The program test the doubly linked list by first asking for the data text. An example text file `list.txt` is included.

## Final Assignment - Sorting Algorithms
**To Compile:** `gcc sorting.c -o sort`  
**To Run:** `./sort`  

`gen.cpp` is used for generating sorted or randonmized numbers. The generated numbers are copied into files. 
`sorting.c` is a program that takes in a text file with numbers, and sorts it, while timing the operation.

## Labs - miscellaneous

These labs are used to aid learning concepts of programming in C++, including structs, classes, objects, inheritance, and polymorphism.
