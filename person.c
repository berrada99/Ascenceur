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
    /* Cette fonction permet d'afficher une personne. N'a d'utilité que pour les tests */
    printf("%i -> %i", p->src, p->dest);
}

PersonList* createPersonList(Person* personne)
{
    /* Fonction de création d'une Personne */
    PersonList* personneliste = (PersonList *)malloc(sizeof(PersonList));
    personneliste->person = personne;
    personneliste->next   = NULL;

    return personneliste; 
}

PersonList* insert(Person *p, PersonList *list)
{
    /* Fonction d'insertion d'un Personne en tête de liste */
    PersonList* temp = createPersonList(p);
    temp -> next = list;
    temp -> person = p;

    return temp;
}

int length(PersonList* list)
{
    /* Fonction qui permet de trouver la longueur d'une liste de personnes */
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
    /* Cette fonction permet d'afficher une liste de personnes. N'a d'utilité que pour les tests */
    PersonList* temp  = list;

    while(temp != NULL)
    {
        printPerson(temp->person);
        printf(" / ");
        temp = temp->next;
    }

}