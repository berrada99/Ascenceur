CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lncurses

PROG = main  #Change here for testing : testingfile
OBJ = main.o elevator.o person.o # Change here for testing : testingfile.o

all : $(PROG)
	make $(PROG)

$(PROG) : $(OBJ)
	$(CC) $(OBJ) -o $(PROG) $(LDFLAGS)

person.o : person.c person.h 
	$(CC) -c $(CFLAGS) person.c

elevator.o : elevator.c elevator.h person.h
	$(CC) -c $(CFLAGS) elevator.c

main.o : main.c elevator.h person.h     # Change here for testing
	$(CC) -c $(CFLAGS)  main.c        

run : $(PROG)
	./$(PROG)

clean : 
	rm -f $(PROG) *.o
