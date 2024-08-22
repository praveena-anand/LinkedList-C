#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head, *tail, *newnode, *temp, *current, *nextnode;

int count = 0;

void create();
void display();
void insert_beginning();
void insert_end();
void insert_at_position();
void insert_after_position();
int isEmpty();
void delete_beginning();
void delete_end();
void delete_position();
void reverse();

int main()
{
	do
	{
		int opt;
		printf("\nMain Menu : \n1. Create\n2. Display\n3. Insert at Beginning\n4. Insert at End\n5. Insert At Position\n6. Insert After Position\n7. Delete at Beginning\n8. Delete at End\n9. Delete at Position\n10. Reversing\n11. Exit\n");
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
				insert_at_position();
				break;
				
			case 6:
				insert_after_position();
				break;
				
			case 7:
				delete_beginning();
				break;
				
			case 8:
				delete_end();
				break;
				
			case 9:
				delete_position();
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
	
	int ch = 1;
	
	while (ch)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter the Data : ");
		scanf("%d", &newnode -> data);
		newnode -> next = 0;
		newnode -> prev = 0;
		count++;
		
		if (head == 0)
			head = tail = newnode;
		
		else
		{
			tail -> next = newnode;
			newnode -> prev = tail;
			tail = newnode;
		}
		
		printf("Do you want to continue (0/1) : ");
		scanf("%d", &ch);
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
	
	printf("Enter the Data : ");
	scanf("%d", &newnode -> data);
	
	newnode -> prev = 0;
	newnode -> next = head;
	head -> prev = newnode;
	head = newnode;
	
	printf("Sucessfully Inserted at the Beginning!\n");
	count++;
}

void insert_end()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the Data : ");
	scanf("%d", &newnode -> data);
	
	newnode -> next = 0;
	newnode -> prev = tail;
	tail -> next = newnode;
	tail = newnode;
	
	printf("Successfully Inserted at the End!\n");
	count++;
}

void insert_at_position()
{
	int pos, i = 1;
	
	printf("Enter the Position : ");
	scanf("%d", &pos);
	
	if (pos <= 0 || pos > count)
	{
		printf("Invalid Position!\n");
		return;
	}
	
	temp = head;
	newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the Data : ");
	scanf("%d", &newnode -> data);
	
	while (i < pos - 1)
	{
		temp = temp -> next;
		i++;
	}
	
	newnode -> prev = temp;
	newnode -> next = temp -> next;
	temp -> next -> prev = newnode;
	temp -> next = newnode;
	
	printf("Successfully Inserted at Postion %d.\n", pos);
	count++;
}

void insert_after_position()
{
	int pos, i = 1;
	
	printf("Enter the Position : ");
	scanf("%d", &pos);
	
	if (pos <= 0 || pos > count)
	{
		printf("Invalid Position!\n");
		return;
	}
	
	temp = head;
	newnode = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter the Data : ");
	scanf("%d", &newnode -> data);
	
	while (i < pos)
	{
		temp = temp -> next;
		i++;
	}
	
	newnode -> prev = temp;
	newnode -> next = temp -> next;
	temp -> next -> prev = newnode;
	temp -> next = newnode;
	
	printf("Successfully Inserted after Position %d.\n", pos);
	count++;
}

int isEmpty()
{
	if (head == 0)
		return 1;
	else
		return 0;
}

void delete_beginning()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	temp = head;
	
	if (head == tail)
	
		head = tail = 0;
	
	else
	{
		head = head -> next;
		head -> prev = 0;
	}
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
	
	temp = tail;
	
	if (head == tail)
		head = tail = 0;
		
	else
	{
		temp -> prev -> next = 0;
		tail = tail -> prev;
	}
	free(temp);
	
	printf("Successfully Deleted from End!\n");
	count--;
}

void delete_position()
{
	if (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	int pos, i = 1;
	
	printf("Enter the Position : ");
	scanf("%d", &pos);
	
	if (pos <= 0 || pos > count)
	{
		printf("Invalid Position!\n");
		return;
	}
	
	if (pos == 1)
		delete_beginning;
	else if (pos == count)
		delete_end;
	else
	{
		temp = head;
		
		while (i < pos)
		{
			temp = temp -> next;
			i++;
		}
		
		temp -> prev -> next = temp -> next;
		temp -> next -> prev = temp -> prev;
		
		free(temp);
		
		printf("Successfully Deleted from Position %d.\n", pos);
		count--;
	}	
}

void reverse()
{
	current = head;
	
	while (current != 0)
	{
		nextnode = current -> next;
		current -> next = current -> prev;
		current -> prev = current -> next;
		current = nextnode;
	}
	
	current = head;
	head = tail;
	tail = current;
	
	printf("Successfully Reversed the List!\n");
}
