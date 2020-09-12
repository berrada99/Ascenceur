#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "elevator.h"
#include "person.h"

#define HEIGHT 30
#define WIDTH 40
#define PERSON_WIDTH 3

void test_copy() 
{
    Person* p1 = createPerson(1, 3);
    Person* p2 = createPerson(2, 2);
    Person* p3 = createPerson(3, 1);
    Person* p4 = createPerson(4, 0); 

    PersonList* list = insert(p1, NULL);
    list = insert(p2, list);
    list = insert(p3, list);
    list = insert(p4, list);

    printListPerson(list);
    printf("\n");
    PersonList* copy = copyListPerson(list);
    printListPerson(copy);
    printf("\n");
    printListPerson(list);
    printf("\n");
}

void test_person()
{
    printf("Testing the person.c file");
    Person* p1 = createPerson(1, 3);
    Person* p2 = createPerson(2, 2);
    Person* p3 = createPerson(3, 1);
    Person* p4 = createPerson(4, 0);
    Person* p5 = createPerson(5, 2);
    Person* p6 = createPerson(6, 3);
    Person* p7 = createPerson(7, 2);
    Person* p8 = createPerson(8, 1);
    printPerson(p1);
    printf("\n");

    /* In practice, pointers will be size 2 on a 16-bit system (if you can find one), 
    4 on a 32-bit system, 
    and 8 on a 64-bit system, 
    but there's nothing to be gained in relying on a given size. */

    printf("Taille d'un entier : %lu\n", sizeof(int));
    printf("Taille d'un pointeur à entier : %lu\n", sizeof(int*));
    printf("Taille d'une personne : %lu\n", sizeof(Person));
    printf("Taille d'un pointeur à une personne : %lu\n", sizeof(Person*));
    printf("Taille d'une liste de personnes : %lu\n", sizeof(PersonList));

    
    PersonList* l1 = insert(p1, NULL);
    PersonList* l2 = insert(p2, l1);
    PersonList* l3 = insert(p3, l2);
    PersonList* l4 = insert(p4, l3);
    PersonList* l5 = insert(p5, l4);
    PersonList* l6 = insert(p6, l5);
    PersonList* l7 = insert(p7, l6);
    PersonList* l8 = insert(p8, l7);
    


    printPerson(p1);
    printf("\n");
    printPerson(p4);
    printf("\n");

    printListPerson(l8);
    printf("\n");

    PersonList* list = insert(p1, NULL);
    list = insert(p2, list);
    list = insert(p3, list);
    list = insert(p4, list);
    list = insert(p5, list);

    printListPerson(list);
    printf("\n");
}

void test_elevator()

{
    printf("Testing the elevator.c file\n");
    Person* p1 = createPerson(1, 3);
    Person* p2 = createPerson(2, 1);
    Person* p3 = createPerson(3, 1);
    Person* p4 = createPerson(0, 3);
    Person* p5 = createPerson(3, 0);
    Person* p6 = createPerson(2, 0);
    Person* p7 = createPerson(0, 1);
    Person* p8 = createPerson(1, 2);

    PersonList* empty_list = (PersonList *)malloc(sizeof(PersonList));; 
    empty_list = NULL;

    Elevator* elevator = create_elevator(4, 1, empty_list);
    elevator->targetFloor = 2;

    PersonList* list0 = insert(p4, NULL);
    PersonList* list1 = insert(p1, NULL);
    PersonList* list2 = insert(p2, NULL);
    PersonList* list3 = insert(p3, NULL);

    list0 = insert(p7, list0);
    list1 = insert(p8, list1);
    list2 = insert(p6, list2);
    list3 = insert(p5, list3);
    
    PersonList* waitinglist[4] = {list0, list1, list2, list3};

    Building* building = create_building(4, elevator, waitinglist);

    printf("Current Floor : %i\n", building->elevator->currentFloor);
    stepElevator(building);
    printf("Current Floor : %i\n", building->elevator->currentFloor); //Stepelevator else is working 

    stepElevator(building);

    for (int i = 0; i < 4; i++)
    {
        //printListPerson(*(building->waitingLists + i));
        //printf("\n");
    } 

}

int main()
{
    test_copy();
    //test_person();
    //test_elevator();
    return 0;
}