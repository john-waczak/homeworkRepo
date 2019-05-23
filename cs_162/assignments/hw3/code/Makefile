CC = g++
CFLAGS = -Wall -std=c++11 
exec_file = zoo

all = $(excec_file)


$(exec_file): main.o animal.o zoo.o
	$(CC) $(CFLAGS) main.o animal.o zoo.o -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


animal.o: animal.cpp
	$(CC) $(CFLAGS) -c animal.cpp

zoo.o: zoo.cpp
	$(CC) $(CFLAGS) -c zoo.cpp


clean:
	rm *.o $(exec_file)
