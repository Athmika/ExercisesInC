#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

Reflect: what worked, what slowed you down? What would you do differently next time?
I had some trouble understanding how to use getopt because the documentation on it was sparse. I also didn't realse that we had
use the rewind command to overwrite files. Next time, I would spend more time looking for help online before debugging on my own.



Compare your solution to this professional implementation or this one.
What do you see in professional code that is not in your solution?
The professional code raises warnings while mine only raises error messages. I also noticed that the professional code does
not use fgets or scanf. The method it uses to read stdin seems to be more complicated. 



*/

//implementation of the tee command with the append option
int main(int argc,char *argv[])
{
  FILE *output;
  char inputBuffer[800];
  int append = 0;
  char ch;
  int options = 0;

//Returns an error if the user does not enter a file name
    if (argc<1)
    {
     fprintf(stderr, "Enter Valid arguments\n");
       return 1;
        exit(1);
    }
    while ((ch = getopt(argc, argv, "ai")) != -1)
  	{
      options += 1;
  		switch((char)ch)
      {
  		case 'a':
  			append = 1;
  			break;
  		case 'i':
      //optional, don't have to implement
  			break;
  		default:
  		    printf("Enter a valid option");
  		    return 1;
  		    exit(1);
  		}
  	}

int numFiles = argc - options - 1;
int fileIndex = options+1;


while (fgets(stdin,800,inputBuffer))
{
    while(numFiles>0)
    {
      if (append==0)
      {
        output = open(argv[fileIndex], "w");
        rewind(output);
      }
      else
      {
          output = open(argv[fileIndex], "a");
      }
      printf("%s\n", inputBuffer);
      frwite(inputBuffer,output);
      fileIndex += 1;
      numFiles-=1;
      fclose(output);
    }
}
    return 0;
}
