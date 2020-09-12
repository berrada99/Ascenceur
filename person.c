#include<stdio.h>
#include<stdlib.h>

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

PersonList* createPersonList(void)
{
    /* Fonction de création d'une PersonneList vide */
    PersonList* personneliste = NULL;

    return personneliste; 
}

PersonList* insert(Person *p, PersonList *list)
{
    /* Fonction d'insertion d'un Personne en tête de liste */
    PersonList* personlist = (PersonList*)malloc(sizeof(PersonList*)); // Sinon Coredump 
    personlist -> next = list;
    personlist -> person = p;

    return personlist;
}

int length(PersonList* list)
{
    /* Fonction qui permet de trouver la longueur d'une liste de personnes */
    int i = 0;
    while(list != NULL)
    {
        list = list->next;
        i++;
    }
    return i;
}

void printListPerson(PersonList *list)
{
    /* Cette fonction permet d'afficher une liste de personnes. N'a d'utilité que pour les tests */
    while(list != NULL)
    {
        printPerson(list->person);
        printf(" / ");
        list = list->next;
    }

}