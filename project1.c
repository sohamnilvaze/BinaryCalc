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

typedef struct stack2
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
}

/*typedef struct node
{
	int data;
	struct node*next;
}node;

typedef node* list;

typedef struct stack2
{
	list l;
	node*top;
}stack2;

void initlist(list*l)
{
	*l=NULL;
	return;
}

void initstack2(stack2*s)
{
	initlist(&(s->l));
	return;
}

int isemptylist(list l)
{
	if(l==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isemptystack(stack2 s)
{
	if(s.top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void insertlist(list*l,int d)
{
	node *nn=(node*)malloc(sizeof(node));
	if(nn)
	{
		nn->data=d;
		nn->next=NULL;
	}
	else
	{
		return;
	}
	
	nn->next=*l;
	*l=nn;
	return;
}

void deletelist(list*l)
{
	node*p;
	if(*l==NULL)
	{
		return;
	}
	*l=p->next;
	free(p);
	return;
}

void push2(stack2*s, int d)
{
	insertlist(&(s->l),d);
	s->top=s->l;
	return;
}

int peek2(stack2 s)
{
	if(isemptystack(s))
	{
		return INT_MAX;
	}
	else
	{
		return s.top->data;
	}
}

int pop2(stack2*s){
	if(isemptystack(*s))
	{
		return INT_MAX;
	}
	else
	{
		int j=peek2(*s);
		deletelist(&(s->l));
		s->top=s->l;
		return j;
	}
}

void disp2(stack2 s)
{
	if(isemptystack(s))
	{
		printf("The stack is empty.\n");
		return;
	}
	else
	{
		node*p=s.top;
		while(p!=NULL)
		{
			printf("%d\n",p->data);
			p=p->next;
		}
		return;
	}
}*/




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
	init2(&n,10);
	int k=0;
	while(k<j)
	{
		char c=*(postfix+k);
		int d=(int)c;
		if((48<=d)&&(57>=d))
		{
			int num=0;
			while((48<=(int)(*(postfix+k)))&&(57>=(int)(*(postfix+k))))
			{
				int a=(int)(*(postfix+k))-48;
				num=(num*10)+a;
				k=k+1;
			}
			push2(&n,num);
		}
		else if(d==32)
		{
			k=k+1;
		}
		else if(d==43)
		{
			int n1=pop2(&n);
			int n2=pop2(&n);
			int res=n1+n2;
			push2(&n,res);
			k=k+1;
		}
		else if(d==45)
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
		}
	}
	
	int ans=peek2(n);
	
	printf("\n%d\n",ans);
	
				
			
	return 0;
}

			
			
			
			
				
