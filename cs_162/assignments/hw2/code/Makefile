CC = g++
CFLAGS = -Wall -std=c++11
exec_file = pizza_parlor

all = $(excec_file)


$(exec_file): main.o pizza.o
	$(CC) $(CFLAGS) main.o pizza.o  -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

pizza_portal.o: pizza.cpp
	$(CC) $(CFLAGS) -c pizza.cpp

clean:
	rm *.o $(exec_file)
