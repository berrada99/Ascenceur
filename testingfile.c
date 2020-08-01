#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

#include "elevator.h"
#include "person.h"

#define HEIGHT 30
#define WIDTH 40
#define PERSON_WIDTH 3

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

    
    PersonList* l1 = createPersonList(p1);
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
}


int main()
{
    test_person();
    return 0;
}