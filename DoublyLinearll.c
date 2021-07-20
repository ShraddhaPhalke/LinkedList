// 		                          Doubly Linear Linked List

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node 
{
	int data;
	struct node* next;
	struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void DisplayFor(PNODE head);
void DisplayBack(PNODE head);
int Count(PNODE head);
void InsertFirst(PPNODE head,int value);
void InsertLast(PPNODE head,int value);
void InsertAtPos(PPNODE head,int value,int pos);

void DeleteFirst(PPNODE head);
void DeleteLast(PPNODE head);
void DeleteAtPos(PPNODE head,int pos);

int main()
{

	PNODE first = NULL;
	int iret = 0;
	int choice = 0;
	int value = 0;
	int pos = 0;
	
	while(choice <=9)
	{

	printf("\n 1 Display List in Forward Direction\n");
	printf(" 2 Display List in Backward Direction\n");
	printf(" 3 Count Element \n");
	printf("\n Insertion Operations \t Deletion Operations\n\n");
	printf(" 4 Insert at First \t 7 Delete from First\n");
	printf(" 5 Insert at Last \t 8 Delete from Last\n");
	printf(" 6 Insert at Position \t 9 Delete from Position\n\n");
	
	printf("Enter your choice\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			DisplayFor(first);
			break;
			
		case 2:
			DisplayBack(first);
			break;
			
		case 3:
			iret = Count(first);
			printf("NUmber of element in the list is %d\n",iret);
			break;
					
		case 4:
			printf("Enter element\n");
			scanf("%d",&value);
			InsertFirst(&first,value);
			break;
			
		case 5:
			printf("Enter element\n");
			scanf("%d",&value);
			InsertLast(&first,value);
			break;
			
		case 6:
			printf("Enter element and Position\n");
			scanf("%d%d",&value,&pos);
			InsertAtPos(&first,value,pos);
			break;
			
		case 7:
			DeleteFirst(&first);
			break;
			
		case 8:
			DeleteLast(&first);
			break;
			
		case 9:
			printf("Enter position at which you want to delete\n");
			scanf("%d",&pos);
			DeleteAtPos(&first,pos);
			break;	
			
		default:
			printf("You have entered wrong choice\n");
			break;
	
	}
	}	
return 0;
}	

void InsertFirst(PPNODE head,int value)
{

	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = value;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(*head == NULL)
	{
		*head = newn;	
	}	
	else
	{
		newn->next = *head;
		(*head)->prev = newn;
		*head = newn;
	}
}

void DisplayFor(PNODE head)
{
	while(head != NULL)
	{
		printf("%d ->",head->data);
		head = head->next;
	}
	printf("null\n");
}				
		
void DisplayBack(PNODE head)
{
	if(head == NULL)
	{
		return;
	}
	while(head->next != NULL)
	{
		head = head->next;
	}
	
	while(head != NULL)
	{
		printf("%d ->",head->data);
		head = head->prev;
	}
}						

void InsertLast(PPNODE head,int value)
{
	PNODE newn = NULL;
	PNODE temp = *head;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = value;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(*head == NULL)
	{
		*head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}		
		temp->next = newn;
		newn->prev = temp;
	}
}		
		
int Count(PNODE head)
{
	int count = 0;
	
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}				
		
void InsertAtPos(PPNODE head,int value,int pos)
{
	PNODE newn = NULL;
	PNODE temp = *head;
	int i = 0;
	int size = Count(*head);
	
	if((pos<1) || (pos>size+1))
	{
		return;
	}
	
	if(pos == 1)
	{
		InsertFirst(head,value);
	}
	else if(pos == size+1)
	{
		InsertLast(head,value);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = value;
		newn->next = NULL;
		newn->prev = NULL;
		
		for(i=1;i<=pos-2;i++)
		{
			temp = temp->next;
		}
		
		newn->next =temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		
	}	
				
}					

void DeleteFirst(PPNODE head)
{
	if(*head == NULL)
	{
		return;
	}
	else if( (*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}						
	
void DeleteLast(PPNODE head)
{
	PNODE temp = *head;
	
	if(*head == NULL)
	{
		return;
	}
	else if( (*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		free(temp);
		temp->prev->next = NULL;
		
	}
}					 		
		
void DeleteAtPos(PPNODE head,int pos)
{
	PNODE temp = *head;
	int size = Count(*head);
	int i = 0;
	
	if((pos<1) || (pos>size))
	{
		return;
	}
	
	if(pos == 1)
	{
		DeleteFirst(head);
	}
	else if(pos == size)
	{
		DeleteLast(head);
	}
	else
	{
						
		for(i=1;i<=(pos-2);i++)
		{
			temp=temp->next;
		}
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
	}		
}			
				
