mazeSolver: driver.o
	g++ -o mazeSolver driver.o

driver.o: driver.cpp maze_solver.h
	g++ -c driver.cpp

clean: 
	rm *.o