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
    return 0;
}