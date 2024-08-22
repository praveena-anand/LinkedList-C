#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head, *newnode, *temp, *prevnode, *currentnode, *nextnode;

void create();
void display();
void insert_beginning();
void insert_end();
void insert_after_position();
void delete_beginning();
void delete_end();
void delete_at_position();
void getLength();
int isEmpty();
void reverse();

int count;

int main()
{
	do
	{
		int opt;
		printf("\nMain Menu : \n1. Create\n2. Display\n3. Insert at Beginning\n4. Insert at End\n5. Insert After Position\n6. Delete at Beginning\n7. Delete at End\n8. Delete at Position\n9. Find Length\n10. Reversing\n11. Exit\n");
		printf("Enter your Option : ");
		scanf("%d", &opt);
		
		switch (opt)
		{
			case 1:
				create();
				break;
				
			case 2:
				display();
				break;
			
			case 3:
				insert_beginning();
				break;
				
			case 4:
				insert_end();
				break;
				
			case 5:
				insert_after_position();
				break;
				
			case 6:
				delete_beginning();
				break;
				
			case 7:
				delete_end();
				break;
				
			case 8:
				delete_at_position();
				break;
				
			case 9:
				getLength();
				break;
				
			case 10:
				reverse();
				break;
				
			case 11:
				printf("Thank you!\n");
				return 0;
			
			default:
				printf("Invalid Input!\n");
		}
	}
	while (1);
	
	return 0;
}

void create()
{
	head = 0;
	char ch = 'Y';
	
	while (ch == 'y' || ch == 'Y')
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		
		printf("Enter the Data : ");
		scanf("%d", &newnode -> data);
		newnode -> next = 0;
		count++;
		
		if (head == 0)
			head = temp = newnode;
		
		else
		{
			temp -> next = newnode;
			temp = newnode;
		}
		
		printf("Do you want to enter more data [Y/N] : ");
		scanf(" %c", &ch);
	}
}

void display()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = head;
	
	while (temp != 0)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
void insert_beginning()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter Data : ");
	scanf("%d", &newnode -> data);
	
	newnode -> next = head;
	head = newnode;
	
	printf("Inserted at the Beginning Successfully!\n");
	count++;
}

void insert_end()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter Data : ");
	scanf("%d", &newnode -> data);
	
	newnode -> next = 0;
	
	temp = head;
	
	while (temp -> next != 0)
	{
		temp = temp -> next;
	}
	
	temp -> next = newnode;
	
	printf("Inserted at the End Successfully!\n");
	count++;
}

void insert_after_position()
{	
	int pos, i = 1;
	
	newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the Position : ");
	scanf("%d", &pos);

	if (pos > count)
	{
		printf("Invalid Position!\n");
		return;
	}	
	
	printf("Enter Data : ");
	scanf("%d", &newnode -> data);
	
	temp = head;
	
	while (i < pos)
	{
		temp = temp -> next;
		i++;
	}
	
	newnode -> next = temp -> next;
	temp -> next = newnode;
	
	printf("Inserted after Position %d Successfully!\n", pos);
	count++;
}

void delete_beginning()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = head;
	head = head -> next;
	free(temp);
	
	printf("Successfully Deleted from Beginning!\n");
	count--;
}

void delete_end()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = head;
	
	while (temp -> next != 0)
	{
		prevnode = temp;
		temp = temp -> next;
	}
	
	if (temp == head)
		head =0;
	else
		prevnode -> next = 0;
	free(temp);
	
	printf("Successfully Deleted from End!\n");
	count--;
}

void delete_at_position()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = head;
	
	int pos, i = 1;
	
	printf("Enter the Position : ");
	scanf("%d", &pos);
	
	if (pos > count)
	{
		printf("Invalid Position!\n");
		return;
	}
	
	while (i < pos - 1)
	{
		temp = temp -> next;
		i++;
	}
	nextnode = temp -> next;
	temp -> next = nextnode -> next;
	free(nextnode);
	
	printf("Successfully Deleted at Position %d!\n", pos);
	count--;
}

void getLength()
{
	temp = head;
	int length = 0;
	
	while (temp != 0)
	{
		length++;
		temp = temp -> next;
	}
	
	printf("Length is %d.\n", length);
}

int isEmpty()
{
	if (count == 0)
		return 1;
	else
		return 0;
}

void reverse()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	prevnode = 0;
	currentnode = nextnode = head;
	
	while (nextnode != 0)
	{
		nextnode = nextnode -> next;
		currentnode -> next = prevnode;
		prevnode = currentnode;
		currentnode = nextnode;
	}
	
	head = prevnode;
}
