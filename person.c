#include<stdio.h>
#include <stdlib.h>

#include"person.h"

Person* createPerson(int src, int dest)
{
    Person* personne = (Person *)malloc(sizeof(Person));
    personne -> src  = src;
    personne -> dest = dest;

    return personne; 
}

void printPerson(Person* p)
{
    printf("%i -> %i", p->src, p->dest);
}

PersonList* insert(Person *p, PersonList *list)
{
    list -> next = list;
    list -> person = p;

    return list;
}

void printListPerson(PersonList *list)
{
    PersonList* temp  = list;
    while(temp->next != NULL)
    {
        printPerson(temp->person);
        printf(" / ");
        temp = temp->next;
    }

}