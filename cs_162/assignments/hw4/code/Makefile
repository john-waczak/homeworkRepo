CC = g++
CFLAGS = -Wall -std=c++11 
exec_file = wumpus

all = $(excec_file)


$(exec_file): main.o event.o rooms.o
	$(CC) $(CFLAGS) main.o event.o rooms.o -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


event.o: event.cpp
	$(CC) $(CFLAGS) -c event.cpp

rooms.o: rooms.cpp
	$(CC) $(CFLAGS) -c rooms.cpp




clean:
	rm *.o $(exec_file)
