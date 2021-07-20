//                                            Singly Circular Linked List.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;	

void InsertFirst(PPNODE head,PPNODE tail,int value);
void Display(PNODE head,PNODE tail);
void InsertLast(PPNODE head,PPNODE tail,int value);
void InsertAtPos(PPNODE head,PPNODE tail,int value,int pos);

void DeleteFirst(PPNODE head,PPNODE tail);
void DeleteLast(PPNODE head,PPNODE tail);
void DeleteAtPos(PPNODE head,PPNODE tail,int pos);

int Count(PNODE head,PNODE tail);

int main()
{
	PNODE first = NULL;
	PNODE last = NULL;
	int iret = 0;
	int choice = 0;
	int value = 0;
	int pos = 0;
	
	
	while(choice <=8)
	{

	printf("\n 1 Display List\n");
	printf(" 2 Count Element \n");
	printf("\n Insertion Operations \t Deletion Operations\n\n");
	printf(" 3 Insert at First \t 6 Delete from First\n");
	printf(" 4 Insert at Last \t 7 Delete from Last\n");
	printf(" 5 Insert at Position \t 8 Delete from Position\n\n");
	
	
	printf("Enter your choice\n");
	scanf("%d",&choice);
	
	
	switch(choice)
	{
		case 1:
			Display(first,last);
			break;
			
		case 2:
			iret = Count(first,last);
			printf("NUmber of element in the list is %d\n",iret);
			break;		
			
		case 3:
			printf("Enter element\n");
			scanf("%d",&value);
			InsertFirst(&first,&last,value);
			break;
			
		case 4:
			printf("Enter element\n");
			scanf("%d",&value);
			InsertLast(&first,&last,value);
			break;
			
		case 5:
			printf("Enter element and Position\n");
			scanf("%d%d",&value,&pos);
			InsertAtPos(&first,&last,value,pos);
			break;
			
		case 6:
			DeleteFirst(&first,&last);
			break;
			
		case 7:
			DeleteLast(&first,&last);
			break;
			
		case 8:
			printf("Enter position at which you want to delete\n");
			scanf("%d",&pos);
			DeleteAtPos(&first,&last,pos);
			break;
			
		default:
			printf("You have entered wrong choice\n");
			break;
	}
	}
	

return 0;
}

void InsertFirst(PPNODE head,PPNODE tail,int value)
{

	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = value;
	newn->next = NULL;
	
	if((*head == NULL) && (*tail == NULL))
	{
		*head = newn;
		*tail = newn;
		(*tail)->next = *head;
	}
	else
	{
		newn->next =*head;
		*head = newn;
		(*tail)->next = *head;
	}
}

void Display(PNODE head,PNODE tail)
{
	if((head == NULL) &&(tail == NULL))
	{
		return;
	}
	
	do
	{
		printf("%d-> ",head->data);
		head= head->next;
	}
	while(head != tail->next);	
	printf("\n");	


}

void InsertLast(PPNODE head,PPNODE tail,int value)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = value;
	newn->next = NULL;
	
	if((*head == NULL) &&(*tail == NULL))
	{
		*head = newn;
		*tail = newn;
		(*tail)->next = *head;
	}
	else
	{
		(*tail)->next = newn;
		*tail = newn;
	}		

}

void DeleteFirst(PPNODE head,PPNODE tail)
{
	if((*head == NULL) && (*tail == NULL))
	{
		return;
	}
	
	if(*head == *tail)
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
	}
	else
	{
		*head = (*head)->next;
		free((*tail)->next);
		(*tail)->next = *head;
	}		
	
}

void DeleteLast(PPNODE head,PPNODE tail)
{
	PNODE temp = *head;
	
	if((*head == NULL) &&(*tail == NULL))
	{
		return;
	}
	
	if(*head == *tail)
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
	}
	else
	{
		while(temp->next != *tail)
		{
			temp =temp->next;
		}
		free(*tail);
		*tail = temp;
		(*tail)->next = *head;
	}			
}


void InsertAtPos(PPNODE head,PPNODE tail,int value,int pos)
{
	PNODE newn = NULL;
	PNODE temp = *head;
	int size = Count(*head,*tail);
	int i =0;
	
	if((pos<1) && (pos>size))
	{
		return;
	}
	
	if(pos == 1)
	{
		InsertFirst(head,tail,value);
	}
	else if(pos == size+1)
	{
		InsertLast(head,tail,value);
	}
	
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = value;
		newn->next = NULL;
		
		for(i = 1; i<=pos-2;i++)
		{
			temp= temp->next;	
		}
		
		newn->next = temp->next;
		temp->next = newn;			
	}	
}

int Count(PNODE head,PNODE tail)
{
	int cnt = 0;
	
	while(head != tail->next)
	{
		cnt++;
		head = head->next;
	}
	return cnt;
}		


void DeleteAtPos(PPNODE head,PPNODE tail,int pos)
{

	PNODE temp = *head;
	PNODE temp1 = NULL;
	int i = 0;
	int size = Count(*head,*tail);
	
	if((pos<1) && (pos>size))
	{
		return;
	}	
	
	if((*head == NULL) && (*tail == NULL))
	{
		return;
	}
	
	if( pos == 1)
	{
		DeleteFirst(head,tail);
	}
	else if(pos == size)
	{
		DeleteLast(head,tail);
	}
	else
	{
		for(i = 1; i<=pos-2; i++)
		{
			temp=temp->next;
		}
		
		temp1 = temp->next;
		temp->next = temp1->next;
		free(temp1);
	}				
	
}	
		

