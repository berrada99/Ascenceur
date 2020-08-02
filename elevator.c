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
    PersonList* exitList = (PersonList*)malloc(sizeof(PersonList*));
    exitList->next = NULL;

    PersonList* personsInE = (PersonList*)malloc(sizeof(PersonList*));
    personsInE->next = NULL;

    while(e->persons != NULL)
    {
        if(e->persons->person->dest == e->currentFloor)
        {
            exitList = insert(e->persons->person, exitList);
        }
        else
        {
            personsInE = insert(e->persons->person, personsInE);
        }
        e->persons = e->persons->next;
    }
    while(personsInE != NULL)
    {
        e->persons = insert(personsInE->person, e->persons);
        personsInE = personsInE->next;
    }
    return exitList;
}

PersonList* enterElevator(Elevator *e, PersonList *list)
{
    int cpcty = e->capacity - length(list);
    int i = 0;

    PersonList* waitingList = list;

    PersonList* stayingList = (PersonList*)malloc(sizeof(PersonList*));
    stayingList->next = NULL;

    while(i < cpcty && waitingList != NULL)
    {
        if(waitingList->person->dest != e->currentFloor)
        {
            e->persons = insert(waitingList->person, e->persons);
        }
        else
        {
            stayingList = insert(waitingList->person, stayingList);
        }
        waitingList = waitingList->next;
        i++;
    }
    while(waitingList != NULL)
    {
        stayingList = insert(waitingList->person, stayingList);
        waitingList = waitingList->next;
    }

   return stayingList;
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
        PersonList* enteringList = enterElevator(b->elevator, b->waitingLists[n]);
        while(b->waitingLists[n] != NULL)
        {
            b->waitingLists[n] = b->waitingLists[n]->next;
        }
        while(enteringList != NULL);
        {
            b->waitingLists[n] = insert(enteringList->person, b->waitingLists[n]);
        }
        
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