#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void generate_random_walk(char walk[N][N]);
void print_array(char walk[N][N]);

int main()
{
	char walk[N][N],ch = 'A';
	int i,j,x;
	long n;
	
	generate_random_walk(walk);
	
	srand(time (NULL));
	
	walk[0][0] = ch;
	ch++;
	for (i = 0, j = 0,n = 0; ch <= 90 && n <= 999999; n++)
	{
		x=rand() % 4;
		if (x == 0)
		{
			if ((i-1) >= 0)
			{
				if (walk[i-1][j] == '.')
				{
					i--;
					walk[i][j] = ch;
				}
				else
				    continue;
			}
			else
			    continue;
		}
		else if (x == 1)
		{
			if ((j+1) < 10)
			{
				if (walk[i][j+1] == '.')
				{
					j++;
					walk[i][j] = ch;
				}
				else
				    continue;
			}
			else
			    continue;
		}
		else if (x == 2)
		{
			if ((i+1) < 10)
			{
				if (walk[i+1][j] == '.')
				{
					i++;
					walk[i][j] = ch;
				}
				else
				    continue;
			}
			else
			    continue;
		}
		else
		{
			if ((j-1) >= 0)
			{
				if (walk[i][j-1] == '.')
				{
					j--;
					walk[i][j] = ch;
				}
				else
				    continue;
			}
			else
			    continue;
		}
		ch++;
	}
	
	print_array(walk);
	
	return 0;
}

void generate_random_walk(char walk[N][N])
{
	int i,j;
	
	for (i = 0; i < N; i++)
	    for (j = 0; j < N; j++)
	        walk[i][j] = '.';
}

void print_array(char walk[N][N])
{
	int i,j;
	
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		    printf("%c ",walk[i][j]);
        printf("\n");
	}
}
