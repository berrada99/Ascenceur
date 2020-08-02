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

PersonList* createPersonList(Person* personne)
{
    PersonList* personneliste = (PersonList *)malloc(sizeof(PersonList));
    personneliste->person = personne;
    personneliste->next   = NULL;

    return personneliste; 
}

PersonList* insert(Person *p, PersonList *list)
{
    PersonList* temp = createPersonList(p);
    temp -> next = list;
    temp -> person = p;

    return temp;
}

int length(PersonList* list)
{
    int i = 0;
    PersonList* temp = list;
    while(temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

void printListPerson(PersonList *list)
{
    PersonList* temp  = list;

    while(temp != NULL)
    {
        printPerson(temp->person);
        printf(" / ");
        temp = temp->next;
    }

}