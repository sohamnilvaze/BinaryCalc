#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct stack1
{
	char *a;
	int top;
	int size;
}stack1;

void init1(stack1*s,int len)
{
	s->top=-1;
	s->size=len;
	s->a=(char*)malloc(sizeof(char)*len);
	return;
}

int isfull1(stack1 s)
{
	if (s.top==s.size-1)
	{
		return 1;
		
	}
	else
	{
		return 0;
	}
}

int isempty1(stack1 s)
{
	if (s.top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push1(stack1*s, char d)
{
	if (isfull1(*s))
	{
		printf("The stack is full.");
		return;
	}
	else
	{
		s->top=s->top+1;
		s->a[s->top]=d;
		return;
	}
}

char pop1(stack1*s)
{
	char e='#';
	if (!isempty1(*s))
	{
		e=s->a[s->top--];
		//s->top=s->top-1;
	}
	return e;
}

char peek1(stack1 s)
{	
	return s.a[s.top];
}

/*typedef struct stack2
{
	int*A;
	int size;
	int top;
}stack2;

void init2(stack2*s,int S)
{
	s->top=0;
	s->size=S;
	s->A=(int*)malloc(sizeof(int)*S);
	return;
}

int isempty2(stack2 s)
{
	if(s.top==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull2(stack2 s)
{
	if(s.top==s.size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push2(stack2*s, int d)
{
	if(isfull2(*s))
	{
		return;
	}
	else
	{
		s->top=s->top+1;
		s->A[s->top]=d;
		return;
	}
}

int pop2(stack2*s)
{
	if(isempty2(*s))
	{
		return INT_MIN;
	}
	else
	{
		return s->A[s->top--];
	}
}

int peek2(stack2 s)
{
	return s.A[s.top];
}

void disp2(stack2 s)
{
	int l=s.top;
	for(int i=0; i<l; i=i+1)
	{
		printf("%d\n",s.A[s.top]);
		s.top=s.top-1;
	}
	return;
}*/

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
	p=head.front;
	int count=0;
	while(p!=NULL)
	{
		count=count+1;
		p=p->next;
	}
	
	return count;
}
typedef struct stack2
{
	list*a;
	int size;
	int top;
}stack2;

void init2(stack2*s,int S)
{
	s->a=(list*)malloc(sizeof(list)*S);
	s->size=S;
	s->top=-1;
}

int isempty2(stack2 s)
{
	if(s.top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull2(stack2 s)
{
	if(s.top==s.size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push2(stack2*s,list l)
{
	if(isfull2(*s))
	{
		return;
	}
	else
	{
		s->top=s->top+1;
		s->a[s->top]=l;
		return;
	}
}

list pop2(stack2*s)
{	
	return s->a[s->top--];
}

list peek2(stack2 s)
{
	return s.a[s.top];
}

	
		
		
	




int precedence(char c){
    if(c == '+')
        return 10;
    else if(c == '-')
        return 10;
    else if(c == '*')
        return 20;
    else if(c == '/')
        return 20;
    else if(c == '%')
        return 20;
    else if(c == '^')
        return 30;
    else if(c == '(')
        return 5;
    return 0;
}

int tonum(char s[10])
{
	int len=0;
	while(s[len]!='\0')
	{
		len=len+1;
	}
	
	
	int num=0;
	for(int k=0;k<len; k=k+1)
	{
		int a=((int)s[k])-48;
		num=(num*10)+a;
	}
	
	return num;
}

int main()
{
	char s[100];
	printf("Enter the expression:-\n");
	fgets(s,100,stdin);
	stack1 m;
	init1(&m,100);
	
	char postfix[100];
	int j=0;
	char c;
	int i=0;
	while( s[i]!='\0')
	{
		c=s[i];
		if(isdigit(c))
		{
			postfix[j++]=c;
			if(!(isdigit(s[i+1])))
			{
				postfix[j++]=' ';
			}
		}
		else if(c=='(')
		{
			push1(&m,c);
		}
		else if(c==')')
		{
			while(!(isempty1(m))&&(peek1(m)!='('))
			{
				postfix[j++]=pop1(&m);
				postfix[j++]=' ';
			}
			if(peek1(m)=='(')
			{
				pop1(&m);
			}
			
		}
		else
		{
			if((c=='+')||(c=='-')||(c=='*')||(c=='/'))
			{
				if(isempty1(m))
				{
					push1(&m,c);
				}
				else 
				{
					while(!(isempty1(m))&&(precedence(peek1(m))>=precedence(c)))
					{
						postfix[j++]=pop1(&m);
						postfix[j++]=' ';
					}
					push1(&m,c);
				}
			}
		}
		
		i=i+1;
	}
	while(!(isempty1(m)))
	{
		postfix[j++]=pop1(&m);
		postfix[j++]=' ';
	}
	
	printf("\nThe postfix string is:-\n");
	for (int i=0; i<j; i=i+1)
	{
		printf("%c",postfix[i]);
	}
	
	stack2 n;
	init2(&n,100);
	int k=0;
	while(k<j)
	{
		char c=*(postfix+k);
		int d=(int)c;
		if((48<=d)&&(57>=d))
		{
			list p;
			init(&p);
			while((48<=(int)(*(postfix+k)))&&(57>=(int)(*(postfix+k))))
			{
				int r=(int)*(postfix+k)-48;
				append(&p,r);
				k=k+1;
			}
			list q=p;
			push2(&n,q);
			dispLR(q);
			freelist(&p);
		}
		
		
		else if(d==32)
		{
			k=k+1;
		}
		else if(d==43)
		{
			list res,n1,n2;
			init(&res);
			init(&n1);
			init(&n2);
			n1=pop2(&n);
			//dispLR(n1);
			n2=pop2(&n);
			//dispLR(n2);
			node* a=n1.rear;
			node* b=n2.rear;
			int l1=leng(n1);
			int l2=leng(n2);
			if(l1<l2)
			{
				int dif=l1;
				int carry=0;
				for(int i=0; i<dif; i=i+1)
				{
					int ano=(int)(a->data)-48;
					int bno=(int)(b->data)-48;
					int sum=ano+bno+carry;
					if(sum<=9)
					{
						
						append(&res,sum);
						carry=0;
					}
					else if(sum>9)
					{
						sum=sum%10;
						append(&res,sum);
						carry=1;
					}
					a=a->prev;
					b=b->prev;
				}
				
				//for(int j=0; j<l2-l1; j=j+1)
				while(b!=n2.front)
				{
					append(&res,b->data);
					b=b->prev;
				}
			}
			
			else if(l1>l2)
			{
				int dif=l2;
				int carry=0;
				for(int i=0; i<dif; i=i+1)
				{
					int ano=(int)(a->data)-48;
					int bno=(int)(b->data)-48;
					int sum=ano+bno+carry;
					if(sum<=9)
					{
						append(&res,sum);
						carry=0;
					}
					else if(sum>9)
					{
						sum=sum%10;
						append(&res,sum);
						carry=1;
					}
					a=a->prev;
					b=b->prev;
				}
				
				//for(int j=0; j<l1-l2; j=j+1)
				while(a!=n1.front)
				{
					append(&res,a->data);
					a=a->prev;
				}
			}
			
			push2(&n,res);
			
			
				
				
				
				
					
					
			
		}
		/*else if(d==45)
		{
			int n1=pop2(&n);
			int n2=pop2(&n);
			int res=n1-n2;
			push2(&n,res);
			k=k+1;
		}
		else if(d==42)
		{
			int n1=pop2(&n);
			int n2=pop2(&n);
			int res=n1*n2;
			push2(&n,res);
			k=k+1;
		}
		else if(d==47)
		{
			int n1=pop2(&n);
			int n2=pop2(&n);
			int res=n1/n2;
			push2(&n,res);
			k=k+1;
		}*/
	}
	
	//int ans=peek2(n);
	
	//printf("\n%d\n",ans);
	
				
			
	return 0;
}

			
			
			
			
				
