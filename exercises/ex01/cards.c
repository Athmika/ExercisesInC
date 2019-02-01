/* 
This program helps users improve their chances at blackjack by card counting. 
Code from Head First C page 37, modified by Athmika
*/


#include <stdio.h>
#include <stdlib.h>

/*This function displays the current count to the command prompt*/
void displayCount(int count)
{
	printf("Current count: %i\n", count);
}

/*This function either increments or decrements the count depending on the value of the card*/
int updateCount(int val, int count)
{
	if ((val > 2) && (val < 7)) 
	{
		count++;
	} 
	else if (val == 10) 
	{
		count--;
	}

	return count;
}

/*This function makes sure that the user doesn't enter an invalid card*/
int throwException(char card_name[])
{
	int val = atoi(card_name);
	if ((val < 1) || (val > 10)) 
	{
		puts("I don't understand that value!");
		return 1;
	}
	return 0;
}

int main()
{
	int count = 0;
	char card_name[3];

	do {

    puts("Enter the card_name: ");
	scanf("%2s", card_name);

	int val = 0;

	switch(card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			continue;
		default:
		    val = atoi(card_name);
			if (throwException(card_name) == 1) {continue;}
		}

	count = updateCount(val,count);
	displayCount(count);

	} while (card_name[0] != 'X');
	
	return 0;
}