CC = g++
CFLAGS = -Wall -std=c++11
exec_file = linked-list

all = $(excec_file)


$(exec_file): main.o
	$(CC) $(CFLAGS) main.o -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


clean:
	rm *.o $(exec_file)
