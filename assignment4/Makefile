wumpus: Gold.o Pit.o Bat.o Wumpus.o Events.o Room.o Game.o AI.o driver.o
	g++ Gold.o Pit.o Bat.o Wumpus.o Events.o Room.o Game.o AI.o driver.o -o wumpus
Gold.o: Gold.cpp
	g++ -c Gold.cpp
Pit.o: Pit.cpp
	g++ -c Pit.cpp
Bat.o: Bat.cpp
	g++ -c Bat.cpp
Wumpus.o: Wumpus.cpp
	g++ -c Wumpus.cpp
Events.o: Events.cpp
	g++ -c Events.cpp
Room.o: Room.cpp
	g++ -c Room.cpp
Game.o: Game.cpp
	g++ -c Game.cpp
AI.o: AI.cpp
	g++ -c AI.cpp
driver.o: driver.cpp
	g++ -c driver.cpp
clean:
		rm -f *.out *.o zoo *.swf *.gch wumpus
