CC = g++
CFLAGS = -Wall -std=c++11 
exec_file = pizza_parlor

all = $(excec_file)


$(exec_file): main.o pizza.o menu.o restaurant.o
	$(CC) $(CFLAGS) main.o pizza.o menu.o restaurant.o -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

pizza.o: pizza.cpp
	$(CC) $(CFLAGS) -c pizza.cpp


menu.o: menu.cpp
	$(CC) $(CFLAGS) -c menu.cpp


restaurant.o: restaurant.cpp
	$(CC) $(CFLAGS) -c restaurant.cpp




clean:
	rm *.o $(exec_file)
