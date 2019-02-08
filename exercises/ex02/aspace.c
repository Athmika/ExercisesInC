/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

/*

4.) Yes the heap does grow. I created a new pointer variable called c that is allocated memory through malloc. 
During execution, c pointed to the address 0x71ea7010, and the pointer variable that was declared after, p, pointed to the address 0xlea70a0. 
Therefore, we can tell that the heap has grown. 

5.) Yes again the stack size grows because the retadd() gets added onto the stack frame. 

6.) I allocated chunks of size 32 bytes and the hexadecimal difference between them was 30

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void retAdd()
{
	int x = 5;
	printf ("Address of x (stack) is %p\n", &x);

}

int main ()
{
    int var2 = 5;

    void *c = malloc(32);
    void *p = malloc(32);
    char *s = "Hello, World";
    retAdd();
    printf ("Address of c is %p\n", c);
    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);

    return 0;
}
