#include"person.h"

#include<stdio.h>
#include <stdlib.h>


Person* createPerson(int src, int dest)
{
    Person* personne = (Person *)malloc(sizeof(Person));
    personne -> src  = src;
    personne -> dest = dest;

    return personne; 
}

void printPerson(Person* p)
{
    printf("%i/%i\n", p->src, p->dest);
}

PersonList* insert(Person *p, PersonList *list)
{
    list -> next = list;
    list -> person = p;
}