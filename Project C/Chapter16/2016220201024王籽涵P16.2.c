#include <stdio.h>
#include <ctype.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

void quicksort(struct part *order_data, int low, int high);
int split(struct part *order_data, int low, int high);

int read_line(char str[], int n);

int main(void)
{
	char code;
	
	for (;;){
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n');
		
		switch (code) {
			case 'i':insert();break;
	  		case 's': search();break;
	  		case 'u': update();break;
	  		case 'p': print();break;
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
		printf("No space for more parts!!!.\n");
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

void print(void)
{
	int i;
	
	quicksort(inventory, 0, num_parts-1);
	
	printf("Part Number   Part Name"
		   "    Quantuty on hand\n");
 	for (i = 0; i < num_parts; i++)
 		printf("%11d%-13s%15d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

void quicksort(struct part *order_data, int low, int high)
{
	int middle;
	
	if (low >= high)
		return;
	middle = split(order_data, low, high);
	quicksort(order_data, low, middle-1);
	quicksort(order_data, middle+1, high);
}

int split(struct part *order_data, int low, int high)
{
	struct part part_elemrnt = order_data[low];
	
	for (;;){
		while (low < high && part_elemrnt.number <= order_data[high].number)
			high--;
		if (low >= high)
			break;
		order_data[low++] = order_data[high];
		
		while (low < high && order_data[low].number <= part_elemrnt.number)
			low++;
		if (low >= high)
			break;
		order_data[high--] = order_data[low];
	}
	
	order_data[high] = part_elemrnt;
	return high;
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
