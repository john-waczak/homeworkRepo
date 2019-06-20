CC = g++
CFLAGS = -Wall -std=c++11 
exec_file = wumpus

all = $(excec_file)


$(exec_file): main.o  event.o wumpus.o room.o cave.o
	$(CC) $(CFLAGS) main.o event.o wumpus.o room.o cave.o -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


event.o: event.cpp
	$(CC) $(CFLAGS) -c event.cpp


wumpus.o: wumpus.cpp
	$(CC) $(CFLAGS) -c wumpus.cpp

room.o: room.cpp
	$(CC) $(CFLAGS) -c room.cpp

cave.o: cave.cpp
	$(CC) $(CFLAGS) -c cave.cpp


clean:
	rm *.o $(exec_file)
