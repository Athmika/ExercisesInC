/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/* 1. foo() assigns the number 42 to an array of size 5 and bar() assigns the digits 0 to 4 to an array. The loop in main prints our the loop. 

   2. I get a warning that says function foo returns the address of the local variable. This is because foo is returning a variable that was initialized 
   in foo, so it exists in that particular stack frame.  

   3. When I execute the program, random values get printed. I think this is because in main when bar is done executing 

   4. Both the print statements return the same address. When foo is run, a new stack is created, and when foo is done executing, that stack is allocated to 
   the next fucntion, which in this case is  bar. This explains why the local variables in both the functions are allocated to the same address. 
   Since the array that is being modifed by bar is the same array that was was returned to *array in main, the for loop in main prints out the 
   digits 0 to 4 as assigned by bar. I think the inclusion of the print statement in bar() added a time delay that allows for bar to still exist in memory
   as the loop in main starts executing. 

*/


int *foo() {
    int i;
    int array[SIZE];

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array1[SIZE];

     printf("%p\n", array1);

    for (i=0; i<SIZE; i++) {
        array1[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();
    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
