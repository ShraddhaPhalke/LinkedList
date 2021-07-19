//program to create linked list.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head,int value);
void InsertLast(PPNODE head,int value);
void InsertAtPos(PPNODE head,int value,int pos);

void DeleteFirst(PPNODE head);
void DeleteLast(PPNODE head);
void DeleteAtPos(PPNODE head,int pos);

void Display(PNODE head);
int Count(PNODE haed);

int main()
{
	PNODE first = NULL;
	int iret = 0;
	int choice = 0;
	int value = 0;
	int pos = 0;
	
	while(choice <=8)
	{

	printf("\n 1 Display List\n");
	printf(" 8 Count Element \n");
	printf("\n Insertion Operations \t Deletion Operations\n\n");
	printf(" 2 Insert at First \t 5 Delete from First\n");
	printf(" 3 Insert at Last \t 6 Delete from Last\n");
	printf(" 4 Insert at Position \t 7 Delete from Position\n\n");
	
	
	printf("Enter your choice\n");
	scanf("%d",&choice);
	
	
	switch(choice)
	{
		case 1:
			Display(first);
			break;
			
		case 2:
			printf("Enter element\n");
			scanf("%d",&value);
			InsertFirst(&first,value);
			break;
			
		case 3:
			printf("Enter element\n");
			scanf("%d",&value);
			InsertLast(&first,value);
			break;
			
		case 4:
			printf("Enter element and Position\n");
			scanf("%d%d",&value,&pos);
			InsertAtPos(&first,value,pos);
			break;
			
		case 5:
			DeleteFirst(&first);
			break;
			
		case 6:
			DeleteLast(&first);
			break;
			
		case 7:
			printf("Enter position at which you want to delete\n");
			scanf("%d",&pos);
			DeleteAtPos(&first,pos);
			break;
			
		case 8:
			iret = Count(first);
			printf("NUmber of element in the list is %d\n",iret);
			break;	
			
		default:
				return 0;
	
	}
	}

return 0;
}

void InsertFirst(PPNODE head,int value)
{

	PNODE NewN = NULL;
	
	NewN = (PNODE)malloc(sizeof(NODE));
	
	NewN->data = value;
	NewN->next = NULL;
	
	if(*head == NULL)   //linked list is empty.
	{
		*head = NewN;
	}
	else
	{
		NewN->next = *head;
		*head = NewN;
	}	
}	

void Display(PNODE head)
{
	printf("\nElements from linked list are\n");
	while(head != NULL)
	{
		printf("%d ->",head->data);
		head = head->next;
	}
	printf("NULL\n");	

}

int Count(PNODE head)
{
	int cnt = 0;
	
	while(head != NULL)
	{
		cnt++;
		head = head->next;
	}	
	
	return cnt;
}

void InsertLast(PPNODE head,int value)
{
	PNODE NewN = NULL;
	PNODE temp = *head;
	
	NewN = (PNODE)malloc(sizeof(NODE));
	
	
	NewN->data = value;
	NewN->next = NULL;
	
	if(*head == NULL)
	{
		*head = NewN;
	}
	else 
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = NewN; 
	}	
}

void InsertAtPos(PPNODE head,int value,int pos)
{
	PNODE temp = *head;
	
	PNODE NewN = NULL;
	
	int size = Count(*head);
	int i = 0;
	
	if((pos<1) ||(pos>size))
	{
		return;
	}
	
	if(pos == 1)
	{
		InsertFirst(head,value);
	}
	else if(pos == size-1)
	{
		InsertLast(head,value);
	}
	else
	{
		NewN = (PNODE)malloc(sizeof(NODE));
		
		NewN->data = value;
		NewN->next = NULL;
		
		for(i = 1;i<=(pos-2);i++)
		{
			temp=temp->next;
		}
			
		NewN->next = temp->next;
		temp->next = NewN;	
	}
}

void DeleteAtPos(PPNODE head,int pos)
{
	PNODE temp = *head;
	PNODE temp1 = *head;
	
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
	else if(pos == size-1)
	{
		DeleteLast(head);
	}	
	else
	{
		for(i=1;i<=pos-2;i++)
		{
			temp =temp->next;
		}
		temp1 = temp->next;
		
		temp->next = temp1->next;
		free(temp1);			
	}
	
	
}

void DeleteFirst(PPNODE head)
{
	PNODE temp = *head;
	
	if(*head == NULL)
	{
		return;
	}
	else
	{
		*head = (*head)->next;
		free(temp);
	}	
}

void DeleteLast(PPNODE head)
{
	PNODE temp = *head;
	
	if(*head == NULL)
	{
		return;
	}
	else if((*head)->next == NULL)
	{
		free(temp);
		*head = NULL;
		
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
						
	}
}


