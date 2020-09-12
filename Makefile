CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lncurses

PROG = main
OBJ = main.o elevator.o person.o

all : $(PROG)
	make $(PROG)

$(PROG) : $(OBJ)
	$(CC) $(OBJ) -o $(PROG) $(LDFLAGS)

person.o : person.c person.h 
	$(CC) -c $(CFLAGS) person.c

elevator.o : elevator.c elevator.h person.h
	$(CC) -c $(CFLAGS) elevator.c

main.o : main.c elevator.h person.h
	$(CC) -c $(CFLAGS)  main.c 

run : $(PROG)
	./$(PROG)

clean : 
	rm -f main *.o
