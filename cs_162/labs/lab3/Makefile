CC = g++
CFLAGS = -Wall -std=c++11
exec_file = pizza_portal

all = $(excec_file)


$(exec_file): main.o pizza_portal.o
	$(CC) $(CFLAGS) main.o pizza_portal.o  -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

pizza_portal.o: pizza_portal.cpp
	$(CC) $(CFLAGS) -c pizza_portal.cpp

clean:
	rm *.o $(exec_file)
