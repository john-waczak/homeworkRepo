CC = g++
CFLAGS = -Wall -std=c++11
exec_file = wizard_catalog

all = $(excec_file)


$(exec_file): main.o wizard_catalog.o
	$(CC) $(CFLAGS) main.o wizard_catalog.o  -o $(exec_file)


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

wizard_catalog.o: wizard_catalog.cpp
	$(CC) $(CFLAGS) -c wizard_catalog.cpp

clean:
	rm *.o $(exec_file)
