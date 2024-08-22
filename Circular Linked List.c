#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *head, *tail, *temp, *newnode, *prevnode, *current, *nextnode;

int count = 0;

void create()
{
	head = 0;
	int ch = 1;
	
	while (ch)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter tha Data : ");
		scanf("%d", &newnode -> data);
		newnode -> next = 0;
		count++;
		
		if (head == 0)
			head = tail = newnode;
		else
		{
			tail -> next = newnode;
			tail = newnode;
		}
		
		tail -> next = head;
		
		printf("Do you want to continue [0/1] : ");
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
	
	while (temp -> next != head)
	{
		printf("%d\t", temp -> data);
		temp = temp -> next;
	}
	printf("%d\n", temp -> data);
}

int isEmpty()
{
	if (count == 0)
		return 1;
	else
		return 0;
}

void insert_beginning()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the Data : ");
	scanf("%d", &newnode -> data);
	
	newnode -> next = head;
	tail -> next = newnode;
	head = newnode;
	
	printf("Inserted at the Beginning Successfully!\n");
	count++;
}

void insert_end()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the Data : ");
	scanf("%d", &newnode -> data);
	
	newnode -> next = tail -> next;
	tail -> next = newnode;
	tail = newnode;
	
	printf("Inserted at the End Successfully!\n");
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
	
	if (pos == 1)
		insert_beginning;
	else if (pos == count)
		insert_end;
	else
	{
		newnode = (struct node*)malloc(sizeof(struct node));
	
		printf("Enter the Data : ");
		scanf("%d", &newnode -> data);
	
		temp = head;
	
		while (i < pos - 1)
		{
			temp = temp -> next;
			i++;
		}
	
		newnode -> next = temp -> next;
		temp -> next = newnode;
		
		printf("Inserted at Position %d Successfully!\n", pos);
		count++;
	}
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
		tail -> next = head;
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
	
	temp = head;
	
	while (temp -> next != head)
	{
		prevnode = temp;
		temp = temp -> next;
	}
	
	if(temp == head)
		head = tail = 0;
	else
	{
		prevnode -> next = head;
		tail = prevnode;
	}
	
	free(temp);
	
	printf("Successfully Deleted from End!\n");
	count--;
}

void delete_at_position()
{
	int pos, i = 1;
	
	printf("Enter the Position : ");
	scanf("%d", &pos);
	
	if (pos <= 0 || pos > count)
	{
		printf("Invalid Position!\n");
		return;
	}
	
	if (pos == 1)
		delete_beginning();
	else if (pos == count)
		delete_end();
	else
	{
		temp = head;
		
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
}

void reverse()
{
	if  (isEmpty())
	{
		printf("Underflow!\n");
		return;
	}
	
	prevnode = 0;
	current = head;
	nextnode = current -> next;	
	
	while (current != tail)
	{
		prevnode = current;
		current = nextnode;
		nextnode = current ->next;
		current -> next = prevnode;
	}
	
	head -> next = tail;
	temp = head;
	head = tail;
	tail = temp;
}

int main()
{
	do
	{
		int opt;
		
		printf("\nMain Menu : \n1. Create\n2. Display\n3. Insert at Beginning\n4. Insert at End\n5. Insert at Position\n6. Delete at Beginning\n7. Delete at End\n8. Delete at Position\n9. Reverse\n10. Exit\n");
		printf("Enter your option : ");
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
				delete_beginning();
				break;
				
			case 7:
				delete_end();
				break;
				
			case 8:
				delete_at_position();
				break;
				
			case 9:
				reverse();
				break;
				
			case 10:
				printf("Thank you!\n");
				return 0;
				
			default:
				printf("Invalid Option!\n");
		}
	}
	while (1);
	
	return 0;
}
