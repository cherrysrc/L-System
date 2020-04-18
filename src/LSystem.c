#include "LSystem.h"

LSystem* createLSystem(char* initialString, ReplaceFunction rFunction)
{
    LSystem* new = (LSystem*)calloc(1, sizeof(LSystem));

    char* newcpy = (char*)calloc(strlen(initialString), sizeof(char));

    strcpy(newcpy, initialString);

    new->initStr         = newcpy;
    new->replaceFunction = rFunction;

    return(new);
}

char* iterateLSystem(LSystem* system, int iterations)
{
    char* strlsys = (char*)calloc(strlen(system->initStr), sizeof(char));

    strcpy(strlsys, system->initStr);

    for (int i = 0; i < iterations; i++)
    {
        int strLen = strlen(strlsys);
        int newLen = 0;
        for (int j = 0; j < strLen; j++)
        {
            char* replacement    = system->replaceFunction(strlsys[j]);
            int   replacementLen = strlen(replacement);
            newLen += replacementLen;
            free(replacement);
        }

        char* newString = (char*)calloc(newLen + 1, sizeof(char));
        newString[newLen] = '\0';
        int newStringIndex = 0;

        for (int j = 0; j < strLen; j++)
        {
            char* replacement    = system->replaceFunction(strlsys[j]);
            int   replacementLen = strlen(replacement);

            for (int k = 0; k < replacementLen; k++)
            {
                newString[newStringIndex] = replacement[k];
                newStringIndex++;
            }

            free(replacement);
        }

        free(strlsys);
        strlsys = newString;
    }
    return(strlsys);
}

void freeLSystem(LSystem* system)
{
    if (!system)
    {
        return;
    }
    free(system->initStr);
    free(system);
}
