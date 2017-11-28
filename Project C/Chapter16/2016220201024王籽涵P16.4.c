#include <stdio.h>
#include <ctype.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN+1];
	float price;
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int nuimber);
void insert(void);
void search(void);
void update(void);
void changes(void);
void print(void);

int read_line(char str[], int n);

int main(void)
{
	char code;
	
	for (;;){
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n');
		
		switch (code) {
			case 'i': insert();
					  break;
	  		case 's': search();
	  				  break;
	  		case 'u': update();
					  break;
	  		case 'c': changes();
	  				  break;
	  		case 'p': print();
	  				  break;
	  		case 'q': return 0;
	  		default:  printf("Illegal code\n");
		}
		printf("\n");
	}
}

int find_part(int number)
{
	int i;
	
	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

void insert(void)
{
	int part_number;
	
	if (num_parts == MAX_PARTS){
		printf("Database id full; can't add more parts.\n");
		return;
	}
	
	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	if (find_part(part_number) >= 0){
		printf("Part already exists.\n");
		return;
	}
	
	inventory[num_parts].number = part_number;
    
	printf("Enter part name: ");
    
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter part price:");
	scanf("%f", &inventory[num_parts].price);
    
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
    
	num_parts++;
}

void search(void)
{
	int i, number;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0){
		printf("Part name: %s\n", inventory[i].name);
		printf("Part price: %.2f\n", inventory[i].price);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(void)
{
	int i, number, change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0){
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void changes(void)
{
	int i, number;
	float change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0){
		printf("Enter changed price: ");
		scanf("%f", &change);
		inventory[i].price = change;
	}
	else
		printf("Part not found.\n");
}

void print(void)
{
	int i;
	printf("Part Number   Part Name                Part Price     "
		   "Quantuty on hand\n");
 	for (i = 0; i < num_parts; i++)
 		printf("%7d       %-25s%-15.2f%9d\n", inventory[i].number, inventory[i].name, inventory[i].price, inventory[i].on_hand);
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while (isspace(ch = getchar()));
	
	while (ch != '\n' && ch != EOF){
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}
