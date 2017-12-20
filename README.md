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

This game

## Assignment 5 - Doubly Linked List

## Final Assignment - Sorting Algorithms

## Labs - miscellaneous

These labs are used to aid learning concepts of programming in C++
