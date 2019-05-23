CC = g++
CFLAGS = -Wall -std=c++11 -g
exec_file = application

all = $(excec_file)


$(exec_file): application.o shape.o rectangle.o circle.o square.o
	$(CC) $(CFLAGS) application.o shape.o rectangle.o circle.o square.o -o $(exec_file)


main.o: application.cpp
	$(CC) $(CFLAGS) -c application.cpp

shape.o: shape.cpp
	$(CC) $(CFLAGS) -c shape.cpp

rectangle.o: rectangle.cpp
	$(CC) $(CFLAGS) -c rectangle.cpp

circle.o: circle.cpp
	$(CC) $(CFLAGS) -c circle.cpp

square.o: square.cpp
	$(CC) $(CFLAGS) -c square.cpp


clean:
	rm *.o $(exec_file)
