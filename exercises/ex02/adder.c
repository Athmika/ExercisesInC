#include <stdio.h>
#include <stdlib.h>   



void sum(int* listNums, int index)
{
   int i;
  int sum = 0;
  for(i=0; i < index; i++)
         {
             sum = sum + listNums[i];
         }
         printf("Sum of the numbers is %d\n", sum);
}


void getInput()
{

   int MAX = 10;
   int SIZE = 10;
   int listNums[SIZE];
   int index = 0;

   while (1==1)
   {
      char input[MAX];
     
     if (fgets(input,11,stdin) == NULL) 
         {
         sum(listNums, index);
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
           if(atoi(input)==0)
           {
            printf("Cannot be converted\n");
           }

           listNums[index] = atoi(input);
           index = index+1;
         }
         else
         {
          printf("Error too many numbers\n");
          break;
         }   
       }

     }






int main()
{
   
   getInput();    
  
 
    return 0;
}
