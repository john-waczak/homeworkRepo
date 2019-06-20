CC = g++
CFLAGS = -Wall -std=c++11 -g
exec_file = wumpus

all = $(excec_file)


$(exec_file): main.o cave.o room.o event.o wumpus.o gold.o bat.o pit.o empty.o
	$(CC) $(CFLAGS) main.o cave.o room.o event.o wumpus.o gold.o bat.o pit.o empty.o -o $(exec_file)




main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp



cave.o: cave.cpp
	$(CC) $(CFLAGS) -c cave.cpp

room.o: room.cpp
	$(CC) $(CFLAGS) -c room.cpp

event.o: event.cpp
	$(CC) $(CFLAGS) -c event.cpp



wumpus.o: wumpus.cpp
	$(CC) $(CFLAGS) -c wumpus.cpp

gold.o: gold.cpp
	$(CC) $(CFLAGS) -c gold.cpp

bat.o: bat.cpp
	$(CC) $(CFLAGS) -c bat.cpp

pit.o: pit.cpp
	$(CC) $(CFLAGS) -c pit.cpp

empty.o: empty.cpp
	$(CC) $(CFLAGS) -c empty.cpp





clean:
	rm *.o $(exec_file)
