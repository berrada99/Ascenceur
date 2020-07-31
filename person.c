#include<stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include"person.h"

Person* createPerson(int src, int dest);
PersonList* insert(Person *p, PersonList *list);