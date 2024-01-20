#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct node
{	
	int data;
	struct node *prev,*next;
}node;

typedef struct list
{
	node *front,*rear;
}list;

void init(list*head)
{	
	head->front=NULL;
	head->rear=NULL;
}

int isempty(list head)
{
	if(head.front==NULL)
	{
		return 1;
	}
	return 0;
}

void append (list*head,int d)
{
	node*nn=(node*)malloc(sizeof(node));
	nn->next=NULL;
	nn->prev=NULL;
	nn->data=d;
	
	if (isempty(*head)==0)
	{
		node*temp=head->front;
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
		nn->prev=temp;
		head->rear=nn;
	}
	else
	{
		head->front=nn;
		head->rear=nn;
	}
}

void dispLR(list head)
{
	node*p;
	printf("The linked list printed from left to right is:-\n");
	p=head.front;
	
	printf("[");
	while (p!=NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("]\n");
}

void dispRL(list head)
{	
	node*p;
	printf("The linked list printed from right to left is:-\n");
	p=head.rear;
	
	printf("[");
	while (p!=NULL)
	{	
		printf("%d",p->data);
		p=p->prev;
	}
	printf("]\n");
}

void freelist(list*head)
{
	node*p,*q;
	p=head->front;
	
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	head->front=NULL;
	head->rear=NULL;
}

int leng(list head)
{
	node*p;
	p=head.rear;
	int count=0;
	while(p!=NULL)
	{
		count=count+1;
		p=p->prev;
	}
	
	return count;
}


int main()
{
	list*head;
	int size=10;
	head=(list*)malloc(sizeof(list)*size);
	
	if(head!=NULL)
	{
		for(int i=0; i<size;i=i+1)
		{
			list p=*(head+i);
			init(&p);
		}
		printf("Initialisation is successful.\n");
	}
	
	
	int c=0;
	char s[100];
	scanf("%s",s);
	
	int l=0;
	while(*(s+l)!='\0')
	{
		char c=*(s+l);
		int d=(int)c-48;
		append(&a,d);
		l=l+1;
	}
	
	*(head)
	
	dispLR(a);
	dispRL(a);	
	return 0;
}

	
	
