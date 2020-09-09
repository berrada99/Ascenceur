CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lncurses

PROG = main
OBJ = main.o elevator.o person.o

all : $(PROG)
	make $(PROG)

$(PROG) : $(OBJ)
	$(CC) $(PROG) -o $(OBJ) $(LDFLAGS)

person.o : person.c person.h 
	$(CC) -c $(CFLAGS) person.c

elevator.o : elevator.c elevator.h person.h
	$(CC) -c $(CFLAGS) elevator.c

main.o : main.c elevator.h person.h
	$(CC) -c $(CFLAGS)  main.c 

run : main
	./$(PROG)

clean : 
	rm -f main *.o