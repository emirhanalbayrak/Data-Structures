#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define data_size 50
struct stack{
	int cnt;
	char data[data_size];
};typedef struct stack stack;
struct queue{
	int front;
	int rear;
	int cnt;
	char data[data_size]; 
};typedef struct queue queue;
void first_value_stack(stack *stk){
	stk->cnt=-1;
}
void first_value_queue(queue *q){
	q->front=-0;
	q->rear=-1;
	q->cnt=0;
}
void enqueue(queue *q,char x){
	
		q->rear++;
		q->cnt++;
		if(q->rear==data_size){
			q->rear=0;
		}
		q->data[q->rear]=x;
	
	
	
}
char dequeue(queue *q){
	char x=q->data[q->front];
	q->front++;
	q->cnt--;
	if(q->front==data_size){
		q->front=0;
	}
	return x;	
}
void push(stack *s,char x){
	 
	 s->data[++s->cnt]=x;
}
char pop(stack *s){
	char x=s->data[s->cnt--];
	return x;
}

int main(void){
	int durum=1;
 stack *s=(stack*)malloc(sizeof(stack));
 queue *q=(queue*)malloc(sizeof(queue));
 first_value_queue(q);
 first_value_stack(s);
 char a[]="kavak";

 for(int i=0;i<strlen(a);i++){
 	push(s,a[i]);
 	enqueue(q,a[i]);
 }
 for(int k=0;k<strlen(a);k++){
 	if(dequeue(q)!=pop(s)){
 		durum=0;
 		break;
	 }
	 
 }
 if(durum==1){
 	printf("polindrom");
 }
 else{
 	printf("polindrom degil");
 }
 	
}
