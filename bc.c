#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

int maxi(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else if(a<b)
	{
		return b;
	}
	else if(a==b)
	{
		return a;
	}
}


typedef struct stack
{
	int*A;
	int f;
	int i;
	int top;
}stack;

void init(stack*s,int fractional,int integer)
{
	s->f=fractional;
	s->i=integer;
	s->top=0;
	s->A=(int*)malloc(sizeof(int)*(fractional+integer));
}

int isempty(stack s)
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

int isfullint(stack s)
{
	if(s.top==s.i)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull(stack s)
{
	if(s.top==s.f+s.i)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void push(stack*s, int d)
{
	if(isfull(*s))
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

int pop(stack*s)
{
	if(isempty(*s))
	{
		return INT_MIN;
	}
	else
	{
		return s->A[s->top--];
	}
}

int peak(stack s)
{
	return s.A[s.top];
}



	
void disp(stack s)
{
	int n=0;
	for(int i=0;i<(s.f+s.i); i=i+1)
	{
		int a=(peak(s));
		n=(n*10)+a;
		pop(&s);
	}
	int num=0;
	int j=0;
	while(j<(s.f+s.i))
	{
		int b=n%10;
		num=(num*10)+b;
		n=n/10;
		j=j+1;
	}
	
	float numfin=num/pow(10,s.top-s.i);
	int p=s.f;
	printf("\nThe number is %f\n",numfin);
	return;
}

void add(stack s1,stack s2)
{
	stack sadd;
	int carry=0;
	if((s1.f<=s2.f)&&(s1.i<=s2.i))
	{
		init(&sadd,s2.f,s2.i);
		int p=s2.f-s1.f;
		for(int q=0; q<p; q=q+1)
		{
			int n2=peak(s2);
			push(&sadd,n2);
			pop(&s2);
		}
		while(!(isempty(s2)))
		{
			int n1=peak(s1);
			int n2=peak(s2);
			int sum=n1+n2+carry;
			if(sum<=9)
			{
				push(&sadd,sum);
				carry=0;
			}
			else if(sum>9)
			{
				push(&sadd,sum%10);
				carry=1;
			}
			pop(&s1);
			pop(&s2);
		}
	}
	else if((s1.f<=s2.f)&&(s1.i>s2.i))
	{
		init(&sadd,s2.f,s1.i);
		int p=s2.f-s1.f;
		for(int q=0; q<p; q=q+1)
		{
			int n2=peak(s2);
			push(&sadd,n2);
			pop(&s2);
		}
		while(!(isempty(s1)))
		{
			int n1=peak(s1);
			int n2=peak(s2);
			int sum=n1+n2+carry;
			if(sum<=9)
			{
				push(&sadd,sum);
				carry=0;
			}
			else if(sum>9)
			{
				push(&sadd,sum%10);
				carry=1;
			}
			pop(&s1);
			pop(&s2);
		}
	}
	else if((s1.f>s2.f)&&(s1.i>s2.i))
	{
		init(&sadd,s1.f,s1.i);
		int p=s1.f-s2.f;
		for(int q=0; q<p; q=q+1)
		{
			int n1=peak(s1);
			push(&sadd,n1);
			pop(&s1);
		}
		while(!(isempty(s1)))
		{
			int n1=peak(s1);
			int n2=peak(s2);
			int sum=n1+n2+carry;
			if(sum<=9)
			{
				push(&sadd,sum);
				carry=0;
			}
			else if(sum>9)
			{
				push(&sadd,sum%10);
				carry=1;
			}
			pop(&s1);
			pop(&s2);
		}
	}
	else if((s1.f>s2.f)&&(s1.i<=s2.i))
	{
		init(&sadd,s1.f,s2.i);
		int p=s1.f-s2.f;
		for(int q=0; q<p; q=q+1)
		{
			int n1=peak(s1);
			push(&sadd,n1);
			pop(&s1);
		}
		while(!(isempty(s1)))
		{
			int n1=peak(s1);
			int n2=peak(s2);
			int sum=n1+n2+carry;
			if(sum<=9)
			{
				push(&sadd,sum);
				carry=0;
			}
			else if(sum>9)
			{
				push(&sadd,sum%10);
				carry=1;
			}
			pop(&s1);
			pop(&s2);
		}
	}
		
			
	
	int no=0;
	for(int j=0; j<sadd.f+sadd.i;j=j+1)
	{
		int c=peak(sadd);
		no=(no*10)+c;
		pop(&sadd);
	}
	float num;
	if(((isempty(s1))&&(carry==1))||((isempty(s2))&&(carry==1)))
	{
		num=no+pow(10,sadd.i);
		num=num/pow(10,sadd.f);
	}
	else
	{
		num=no/pow(10,sadd.f);
	}
	printf("\nThe addition of two numbers is %f\n",num);
	return;
}

int main()
{
	stack st1,st2;
	init(&st1,3,4);
	init(&st2,3,2);

	
	push(&st1,4);
	push(&st1,8);
	push(&st1,3);
	push(&st1,1);
	push(&st1,7);
	
	push(&st2,9);
	push(&st2,1);
	push(&st2,7);
	push(&st2,3);
	push(&st2,2);
	
	
	
	if((st1.f<st2.f)&&(st1.i==st2.i))
	{
		for(int i=0; i<(st2.f-st1.f);i=i+1)
		{
			push(&st1,0);
			st1.f=st1.f+1;
		}
	}
	else if((st1.f>st2.f)&&(st1.i==st2.i))
	{
		for(int i=0; i<(st1.f-st2.f); i=i+1)
		{
			push(&st2,0);
			st2.f=st2.f+1;
		}
	}
	
	
	
	disp(st1);
	disp(st2);
	
	add(st1,st2);
	
	return 0;
}

	
	
	
			
			 
	
	
	 
	


