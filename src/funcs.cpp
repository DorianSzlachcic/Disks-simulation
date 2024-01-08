#include <math.h>

int random_number(int min, int max)
{
    int range = max - min + 1;
    return rand() % range + min;
}

int random_number(int max)
{
    return rand() % max;
}
