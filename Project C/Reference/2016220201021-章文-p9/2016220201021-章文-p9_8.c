#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int roll_dice();
bool play_game();

int main()
{
	int win = 0, lose = 0;
	char ch;
	
	for (;;)
	{
		if (play_game())
		{
			printf("You win!\n\n");
			win++;
		}
		else
		{
			printf("You lose!\n\n");
			lose++;
		}
		
		printf("Play again?(y or n) ");
		for (;(ch = getchar()) == '\n';)
		;
		
		if (ch != 'y' && ch != 'Y')
		    break;
	}
	
	printf("\nWin: %d  Lose: %d\n",win,lose);
	return 0;  
}

int roll_dice()
{
	int x,y;
	
	x = rand()%6 + 1;
	y = rand()%6 + 1;
	
	return x + y;
}

bool play_game()
{
	int point,num;
	
	srand(time(NULL));
	
	point = roll_dice();
	printf("You rolled: %d\n",point);
	
	if (point == 7 || point == 11)
	    return true;
    else if (point == 2 || point == 3 || point == 12)
        return false;
    else
    {
    	printf("Your point is %d\n",point);
    	
    	for (;;)
    	{
	    	num = roll_dice();
	    	printf("You rolled: %d\n",num);
	    	
	    	if (num == point)
	    	    return true;
 	        else if (num == 7)
 	            return false;
	    }
    }
}
