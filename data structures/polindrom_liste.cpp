#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
     char key;
     struct node *next;
};typedef struct node node;
struct kuyruk{
	int cnt;
	node *front;
	node *rear;
};typedef struct kuyruk kuyruk;
struct stack{
	int cnt;
	struct node *top;
};typedef struct stack stack;
void first_value_stack(stack *s){
	s->cnt=0;
	s->top=NULL;
}
void first_value_kuyruk(kuyruk *q){
	q->cnt=0;
	q->front=q->rear=NULL;
}
void enqueue(kuyruk *q,char c){
	node *temp=(node*)malloc(sizeof(node));
	temp->key=c;
	temp->next=NULL;
	if(q->cnt==0){
		q->front=q->rear=temp;
	}
	else{
		q->rear->next=temp;
		q->rear=temp;
	}
	
}
char dequeue(kuyruk *q){
		node *p=q->front;
		char c=p->key;
		q->front=q->front->next;
		free(p);
		q->cnt--;
		return c;
	
	

}
void push(stack *stk,char c){
	
	
		node *temp=(node*)malloc(sizeof(node));
		temp->key=c;
		temp->next=stk->top;
		stk->top=temp;
	
}
char pop(stack *stk){

	
		node *temp=stk->top;
		stk->top=stk->top->next;
		char c=temp->key;
		free(temp);
		stk->cnt--;
		return c;
		
	
}
int main(void){
	stack *s=(stack*)malloc(sizeof(stack));
	kuyruk *q=(kuyruk*)malloc(sizeof(kuyruk));
	first_value_stack(s);
	first_value_kuyruk(q);
	int durum=1;
	char a[]="kavak";
	for(int i=0;i<strlen(a);i++){
		push(s,a[i]);
		enqueue(q,a[i]);
	}
	for(int k=0;k<strlen(a);k++){
		if(pop(s)!=dequeue(q)){
			durum=0;
			break;
		}
	}
	if(durum==1){
		printf("polindrom");
	}
	else{
		printf("deðil");
	}
	
}











