CC=gcc -g
OBJECTS_MAIN= main.o
OBJECTS_LIB = myBank.o
FLAGS= -Wall -fPIC

all: run
run: $(OBJECTS_LIB) $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o run main.o myBank.o
main.o: main.c
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c


.PHONY: clean all

clean:
	rm -f *.o run