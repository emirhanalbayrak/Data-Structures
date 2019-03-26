#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

struct node{
	int data;
	struct node *next;
};

typedef struct{
	int cnt;
	struct node *top;
}stack;

void initialization(stack *stk){
	stk->cnt=0;
	stk->top=NULL;
}

void push(stack *stk, int c){
	if(stk->cnt == STACK_SIZE)
		{
			printf("Stack is Full");
			return ;
		}
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=c;
	temp->next=stk->top;
	stk->top=temp;
	stk->cnt++;
}


int pop(stack *stk){
	if(stk->cnt==0){
		printf("Stack is Empty");
		return 0;
	}
	struct node *temp=stk->top;
	stk->top=stk->top->next;
	int x=temp->data;
	free(temp);
	stk->cnt--;
	return x;
}




int main() {
	stack s;
	initialization(&s);
	push(&s,4);
	push(&s,7);
	push(&s,3);
	push(&s,17);
	push(&s,21);
	push(&s,20);
	push(&s,12);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	initialization(&s);	
	printf("%d\n", pop(&s));
	push(&s,18);	
	
	
	
}
