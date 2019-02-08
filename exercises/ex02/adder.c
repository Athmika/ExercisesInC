#include <stdio.h>
#include <stdlib.h>   
int main()
{
   int MAX = 10;
   int SIZE = 10;
   char listNums[SIZE];
   int index = 0;
   int i;
   int sum = 0;
   while (1==1)
   {
    char input[MAX];
     

     if (fgets(input,11,stdin) == NULL) 
         {
         for(i=0; i < index; i++)
         {
             sum = sum + listNums[i];
         }
         printf("Sum of the numbers is %d\n", sum);
         break;
       }
       int len = strlen(input);

       if (input[len-1] != '\n')
       {
         printf("Error. Input too long\n");
            break;
       }

       if (index < SIZE)
        {
           
           listNums[index] = atoi(input);
           printf("in %i\n", listNums[index]);
           index = index+1;
         }
         else
         {
          printf("Error too many numbers");
          break;
         }   
   }
 
    return 0;
}
