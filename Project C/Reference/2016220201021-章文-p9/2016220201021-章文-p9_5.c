#include <stdio.h>
#include <stdbool.h> 

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main()
{
	int n;
	
	printf("This program creates a magic square of a specified siza.\n");
	printf("The siza must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d",&n);
	
	int magic_square[n][n];
	
	create_magic_square(n, magic_square);
	print_magic_square(n, magic_square);
	
	return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
	int i,j,num;
	bool check[n][n];
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			check[i][j] = false;
		}
	}
	
	i = 0;
	j = (n-1)/2;
	magic_square[i][j] = 1;
	check[i][j] = true;
	
	for (num = 2; num <= n*n; num++)
	{
		i--;
		j++;
        if (i < 0)
            i += n;
        if (j > n-1)
            j -= n;
        if (check[i][j])
        {
        	i++;
        	i++;
        	j--;
        }
        if (i > n-1)
            i -= n;
        if (j < 0)
            j += n;
        magic_square[i][j] = num;
        check[i][j] = true;
	}
}

void print_magic_square(int n, char magic_square[n][n])
{
	int i,j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4d",magic_square[i][j]);
		}
		printf("\n");
	}
}
