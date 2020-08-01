#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

#include "elevator.h"
#include "person.h"

#define HEIGHT 30
#define WIDTH 40
#define PERSON_WIDTH 3

int main()
{
    Person* p1 = createPerson(1, 3);
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
    
    return 0;
}