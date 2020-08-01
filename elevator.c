#include <time.h>
#include <stdlib.h>

#include"elevator.h"
#include"person.h"


Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons)
{
    Elevator* elevator = (Elevator*)malloc(sizeof(Elevator*));
    elevator->capacity = capacity;
    elevator->currentFloor = currentFloor;
    elevator->persons = persons;

    return elevator;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists)
{
    Building* building = (Building*)malloc(sizeof(Building*));
    building->nbFloor = nbFloor;
    building->elevator = elevator;
    building->waitingLists = 
}

PersonList* exitElevator(Elevator *e);

PersonList* enterElevator(Elevator *e, PersonList *list);

void stepElevator(Building *b);