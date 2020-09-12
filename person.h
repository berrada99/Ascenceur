#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
    int src;
    int dest;
} Person;

typedef struct _PersonList {
    Person *person;
    struct _PersonList *next;
} PersonList;

Person* createPerson(int src, int dest);
PersonList* createPersonList(void);
PersonList* insert(Person *p, PersonList *list);

int length(PersonList* list);
PersonList* copyListPerson(PersonList* list);

void printPerson(Person* p);
void printListPerson(PersonList *list);

#endif
