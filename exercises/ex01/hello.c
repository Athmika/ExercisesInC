#include <stdio.h>
/*
1. These two lines of code: 
	subq	$16, %rsp
	movl	$5, -4(%rbp)
    get added when int x = 5 is added

2. When the optimization flag is used the assembly code becomes significantly shorter. The lines declaring int x is not present.  

3. When x is printed without optimization, the lines declaring int x appears in the assembley code. When x is printed with optimization instead of 
allocating 16 bytes of memory (subq $16) only 8 bytes are allocated (subq	$8). 
However, the line, movl $5, stays intact even with optimization meaning that int x stores the value 5 in both cases. 

4. In the first case, without optimization, variable x is created and assigned a value and then variable y is assigned a value. 
But with optimization only variable y is stored. y is directly assigned 6 without storing and retrieving x. 

5. Optimization disregards variables that are never used. This helps reduce space usage and makes execution faster.

*/

int main() {
    int x = 5;
    int y = x + 1;

    printf("%d",y);
    return 0;
}
