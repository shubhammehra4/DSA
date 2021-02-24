#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int size;
	int top;
	int *S;
};
void create(struct Stack *st)
{
	printf("Enter Size ");
	scanf("%d", &st->size);
	st->top = -1;
	st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{
	int i;
	for (i = 0; i <= st.top; i++)
		printf("%d ", st.S[i]);
	printf("\n");
}

void push(struct Stack *st , int x)
{
	if (st->top == st->size - 1)
		printf("Stack Overflow \n");
	else
	{
		st->top++;
		st->S[st->top] = x;
	}
}

int pop(struct Stack *st)
{
	int x = -1;
	if (st->top == -1)
		printf("Stack Underflow");
	else
	{
		x = st->S[st->top--];
	}
	return x;
}
int main()
{
	struct Stack st;
	create(&st);
	push(&st, 87);
	push(&st, 86);
	push(&st, 7);
	push(&st, 78);
	Display(st);
	printf("poppping %d\n", pop(&st));
	Display(st);
}
