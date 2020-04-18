#ifndef LSYSTEM_H
#define LSYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char* (* ReplaceFunction)(char);

typedef struct
{
    char*           initStr;
    ReplaceFunction replaceFunction;
} LSystem;

LSystem* createLSystem(char* initialString, ReplaceFunction rFunction);

char* iterateLSystem(LSystem* system, int iterations);

void freeLSystem(LSystem* system);

#ifdef __cplusplus
}
#endif

#endif
