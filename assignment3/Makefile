zoo: Animal.o Penguin.o Pb.o Tiger.o Orca.o Zoo.o driver.o
	g++ Animal.o Penguin.o Pb.o Tiger.o Orca.o Zoo.o driver.o -o zoo
Animal.o: Animal.cpp
	g++ -c Animal.cpp
Penguin.o: Penguin.cpp
	g++ -c Penguin.cpp
Pb.o: Pb.cpp
	g++ -c Pb.cpp
Tiger.o: Tiger.cpp
	g++ -c Tiger.cpp
Orca.o: Orca.cpp
	g++ -c Orca.cpp
Zoo.o: Zoo.cpp
	g++ -c Zoo.cpp
driver.o: driver.cpp
	g++ -c driver.cpp
clean:
	rm -f *.out *.o zoo *.swf *.gch
