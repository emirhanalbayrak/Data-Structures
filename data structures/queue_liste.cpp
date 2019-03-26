#include<stdio.h>
#include<stdlib.h>
 
struct node{
	int key;
	struct node *next;
};typedef struct node node;
struct queue{
	int cnt;
	struct node *front;
	struct node *rear;
};typedef struct queue queue;
typedef enum boolean{
	True=1,False=0
};typedef enum boolean boolean;
boolean isEmpty(queue *q){
	if(q->cnt==0)
		return True;
	else 
	    return False;
}
/*boolean isFull(queue *q){
	if(q->count==data_size)
	    return True;
    else 
        return False;
}*/

void first_value(queue *q){
	q->front=q->rear=NULL;
	q->cnt=0;
}
void enqueue(queue *q,int x){
		node *temp=(node*)malloc(sizeof(node));
		temp->key=x;
		temp->next=NULL;
	    if(isEmpty(q)){
	    	q->front=q->rear=temp;
		}
		else{
		q->rear->next=temp;
		q->rear=temp;
	}
	q->cnt++;
		
}
int dequeue(queue *q){
	if(!isEmpty(q)){
		struct node *p=q->front;
		int x=p->key;
		q->front=q->front->next;
		free(p);
		q->cnt--;
		return x;
	}
	else{
		printf("silinecek liste yok\n");
	}
	
}
int main(void){
	queue *q=(queue*)malloc(sizeof(queue));
	first_value(q);
	enqueue(q,5);
	enqueue(q,10);
	enqueue(q,15);
	printf("%d\n",dequeue(q));
	
}


















