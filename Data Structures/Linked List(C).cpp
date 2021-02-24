#include<stdio.h>
#include<stdlib.h>
clTabCtrl
struct Node
{
	int data;
	struct Node* next;
}*first=NULL;

void Create(int A[], int n)clTabCtrl
{
	int i;
	struct Node *t,*last;
	first=(struct Node*)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	for (i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void RecDisplay(struct Node *p)
{
	while(p!=NULL)
	{
		print("%d ",p->data);
		RecDisplay(p->next);
	}
	printf("\n");
}

int Count(struct Node *p)
{
	if(p==0)
		return 0;
	else
		return Count(p->next)+1;
}

struct Node *LSearch(struct Node *p,int key)
{
	while(p!=NULL)
	{
		if(key==p->data)
			return p;
		p=p->next;
	}
	return NULL;
}

struct Node *DynamicLSearch(struct Node *p,int key)//changes the linked list's order
{
	struct Node *q=NULL;
	while(p!=NULL)
	{
		if(key==p->data)
		{
			q->next=p->next;
			p->next=first;
			first=p;
			return p;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}

void Insert (struct Node *p,int index,int x)
{
	int i;
	struct Node *t;
	if(index<0 || index> Count(p))
		return;
	else
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		
		if(index==0)
		{
			t->next=first;
			first=t;
		}
		else
		{
			for(i=0;i<index-1;i++)
				p=p->next;
			t->next=p->next;
			p->next=t;
		}
	}
}

int Delete(strucy Node *p,int pos)//pos should be started from 1
{
	struct Node *q=NULL;
	int i,x=-1;
	if(pos<1 ||pos>Count(p))
		return -1;
	else if(pos==1)
	{
		q=first;
		x=first->data;
		first=first->next;
		free(p);
		return x;	
	}
	else
	{
		for(i=0;i<pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		
		q->next=p->next;
		x=p->next;
		free(p);
		return x;
	}
}

int isSorted(struct Node *p)
{
	int x=-65536;
	while(p!=NULL)
	{
		if(p->data < x)
			return 0;
		x=p->data;
		p=p->next;
	}	
	return 1;
}

void Reverse1(struct Node *p)
{
	int *A,i=0;
	struct Node *q=p;
	
	A=(int *)malloc(sizeof(int)*count(p));
	
	while(q!=NULL)
	{
		A[i]=q->data;
		q=q->next;
		i++;
	}
	q=p;
	i--;
	while(q!=NULL)
	{
		q->data=A[i];
		q=q->next;
		i--;
	}
}
void Reverse2(struct Node *p)
{
	struct Node *q=NULL,*r=NULL;
	
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}
void Reverse3(struct Node *q,struct Node *p)
{
	if(p)
	{
		Reverse3(p,p->next);
		p->next=q;
	}
	else
        first=q;
}

int main()
{
	struct Node *temp;
	int A[]={1,2,3,4,5};
	
	Create(A,5);
	
	Display(first);
	RecDisplay(first);
	int len=Count(first);
	temp=LSearch(first,2)
	if(temp)
		printf("Key is found %d\n",temp->data);
	else
		printf("Not found\n");
	Insert(first,0,10);
	Insert(first,3,90);
	
	
	return 0;
}
