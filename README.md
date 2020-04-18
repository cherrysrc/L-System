# L-System
Implementation of the Lindenmayer System in C  
[Wikipedia](https://en.wikipedia.org/wiki/L-system)

## How to use
### Include file:
```c
#include "LSystem.h"
```
### Create replacement function:
The function is of following signature:
```c
char* replace(char c){}
```
main.c contains the definition of such a function, used to model algae growth. (Wikipedia)
### Create a new L-System:
```c
LSystem* sys = createLSystem("A", replace);
```
### Create iterations and free used memory:
```c
for (int i = 0; i < 6; i++)
{
    char* iteration = iterateLSystem(sys, i);

    printf("[%i] = %s\n", i, iteration);

    free(iteration);
}
```
### Free L-System afterwards:
```c
freeLSystem(sys);
```
