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
    building->waitingLists = waitingLists;

    return building;
}

PersonList* exitElevator(Elevator *e)
{
    PersonList* exitList;
    exitList->next = NULL;
    while(e->persons != NULL)
    {
        if(e->persons->person->dest == e->currentFloor)
        {
            exitList = insert(e->persons->person, exitList);
            e->persons = e->persons->next;
        }
        else
        {
            e->persons = e->persons->next;
        }
        
    }
}

PersonList* enterElevator(Elevator *e, PersonList *list)
{

}


void stepElevator(Building *b)
{
    if (b->elevator->currentFloor == b->elevator->targetFloor)
    {
        int n = b->elevator->currentFloor;

        //Exiting Elevator
        PersonList* exitList = exitElevator(b->elevator);
        while(exitList != NULL)
        {
            b->waitingLists[n] = insert(exitList->person, b->waitingLists[n]);
            exitList = exitList->next;
        }
        //Entering Elevator
        
    }
    else
    {
        int diffFloor = b->elevator->currentFloor - b->elevator->targetFloor;
        if (diffFloor > 0)
        {
            b->elevator->currentFloor--; 
        }
        else
        {
            b->elevator->currentFloor++;
        }   
    }
    
}