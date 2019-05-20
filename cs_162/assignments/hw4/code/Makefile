CC = g++
CFLAGS = -Wall -std=c++11 
exec_file = wumpus

all = $(excec_file)


$(exec_file): main.o event.o
	$(CC) $(CFLAGS) main.o event.o -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


event.o: event.cpp
	$(CC) $(CFLAGS) -c event.cpp



clean:
	rm *.o $(exec_file)
