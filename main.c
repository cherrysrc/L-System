// Implementation of the algae growth modelling l-system
// Wikipedia: https://en.wikipedia.org/wiki/L-system#Example_1:_Algae

#include "LSystem.h"

#include <stdio.h>
#include <stdlib.h>

char* replace(char c)
{
    if (c == 'A')
    {
        char* p = (char*)calloc(3, sizeof(char));
        strcpy(p, "AB\0");
        return(p);
    }
    else if (c == 'B')
    {
        char* p = (char*)calloc(2, sizeof(char));
        strcpy(p, "A\0");
        return(p);
    }
    else
    {
        char* p = (char*)calloc(2, sizeof(char));
        p[0] = c;
        p[1] = '\0';
        return(p);
    }
}

int main()
{
    LSystem* sys = createLSystem("A", replace);

    for (int i = 0; i < 6; i++)
    {
        char* lsystemed = iterateLSystem(sys, i);

        printf("[%i] = %s\n", i, lsystemed);

        free(lsystemed);
    }

    freeLSystem(sys);

    return(0);
}
