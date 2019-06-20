CC = g++
CFLAGS = -Wall -std=c++11 -g
exec_file = application

all = $(excec_file)


$(exec_file): main.o my_array.o
	$(CC) $(CFLAGS) main.o my_array.o -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

my_array.o: my_array.cpp
	$(CC) $(CFLAGS) -c my_array.cpp

clean:
	rm *.o $(exec_file)
