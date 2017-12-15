shape: Shape.o Rect.o Circle.o driver.o
	g++ Shape.o Rect.o Circle.o driver.o -o shape
Shape.o: Shape.cpp
	g++ -c Shape.cpp
Circle.o: Circle.cpp
	g++ -c Circle.cpp
Rect.o: Rect.cpp
	g++ -c Rect.cpp
driver.o: driver.cpp
	g++ -c driver.cpp
clean:
	rm -f *.out *.o shape *.swf *.gch
