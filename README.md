<div style="text-align:center"><h1>L-System</h1></div>

<div style="text-align:center">
<img src="https://img.shields.io/badge/-Language-blue?style=for-the-badge&logo=c" />
</div>

<div style="text-align:center">
<br>
Implementation of the Lindenmayer System in C <br>
<a href="https://en.wikipedia.org/wiki/L-system">Wikipedia on Lindenmayer-Systems</a>
</div>

<div style="text-align:center"><h2>How to use</21></div>

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
