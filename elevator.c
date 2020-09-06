#include <time.h>
#include <stdlib.h>
#include <stdio.h> //Delete after Testing

#include"elevator.h"
#include"person.h"


Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons)
{
    /* Fonction de creation d'un ascenceur */
    Elevator* elevator = (Elevator*)malloc(sizeof(Elevator*));
    elevator->capacity = capacity;
    elevator->currentFloor = currentFloor;
    elevator->persons = persons;

    return elevator;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists)
{
    /* Fonction de création d'un bâtiment */
    Building* building = (Building*)malloc(sizeof(Building*));
    building->nbFloor = nbFloor;
    building->elevator = elevator;
    building->waitingLists = waitingLists;

    return building;
}

PersonList* exitElevator(Elevator *e)
{
    /* Fonction de sortie d'ascenceur */
    PersonList* exitList = (PersonList*)malloc(sizeof(PersonList*));
    exitList = NULL;

    PersonList* personsInE = (PersonList*)malloc(sizeof(PersonList*));
    personsInE = NULL;

    while(e->persons != NULL)
    {
        /* Dans un premier temps la liste des personnes de l'ascenceur est vidée afin de séparer
        les personnes entrantes (personsInE) et les personnes sortantes (exitList) */
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
        /* Les personnes étant restée dans l'ascnenceur y sont remplacées */
        e->persons = insert(personsInE->person, e->persons);
        personsInE = personsInE->next;
    }
    return exitList;
}

PersonList* enterElevator(Elevator *e, PersonList *list)
{
    /* Fonction d'entrée d'ascenceur */
    int cpcty = e->capacity - length(e->persons);
    int i = 0;

    PersonList* waitingList = list;

    PersonList* stayingList = (PersonList*)malloc(sizeof(PersonList*));
    stayingList = NULL;

    while(i < cpcty && waitingList != NULL)
    {
        /* On sépare dans un premier temps les personnes qui rentrent dans l'ascenceur et
        celles qui en sortent */
        if(waitingList->person->dest != e->currentFloor)
        {
            e->persons = insert(waitingList->person, e->persons);
            i++;
        }
        else
        {
            stayingList = insert(waitingList->person, stayingList);
        }
        waitingList = waitingList->next;
    }
    while(waitingList != NULL)
    {
        /* On vide la liste des personnes qui attendent dans stayingList */
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
        PersonList* stayingList = enterElevator(b->elevator, b->waitingLists[n]);
        while(b->waitingLists[n] != NULL)
        {
            b->waitingLists[n] = b->waitingLists[n]->next;
        }
        while(stayingList != NULL)
        {
            b->waitingLists[n] = insert(stayingList->person, b->waitingLists[n]);
            stayingList = stayingList->next;
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