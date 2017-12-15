CC = g++
exe_file = facts
$(exe_file): facts.o run_facts.o
	$(CC) facts.o run_facts.o -o $(exe_file)
facts.o: facts.cpp
	$(CC) -c facts.cpp
run_facts.o: run_facts.cpp
	$(CC) -c run_facts.cpp
clean:
	rm -f *.out *.o $(exe_file)