#include<stdio.h>
#include<stdlib.h>
#define data_size 5
struct queue {
	int front;
	int rear;
	int cnt;
	int data[data_size];
}; typedef struct queue queue;
typedef enum boolean {
	True = 1, False = 0
}; typedef enum  boolean boolean;
void first_value(queue *);
boolean isFull(queue *);
boolean isEmpty(queue *);
void first_value(queue *);
void enqueue(queue *, int);
int dequeue(queue *);
boolean isFull(queue *q) {
	if (q->cnt == data_size)
		return True;
	else return False;
}
boolean isEmpty(queue *q) {
	if (q->cnt == 0)
		return True;
	else return False;
}

int main() {
	queue *q=(queue*)malloc(sizeof(queue));
	first_value(q);
	enqueue(q, 5);
	enqueue(q, 6);
	enqueue(q, 7);
	enqueue(q, 8);
	enqueue(q, 9);enqueue(q, 10);
	printf("%d\n", dequeue(q));
	enqueue(q, 10);
	printf("%d\n", dequeue(q));

	printf("%d\n", dequeue(q));
	printf("%d\n", dequeue(q));
	printf("%d\n", dequeue(q));
	printf("%d\n", dequeue(q));



 return 0;

}
void first_value(queue *q) {
	q->front = 0;
	q->rear = -1;
	q->cnt = 0;
}
void enqueue(queue *q, int x) {
	if (!isFull(q)) {
		q->rear++;
		q->cnt++;
		if (q->rear == data_size) {
			/*eklenecek eleman dizinin boyutunu aþýyorsa  rear ilk elemaný göstersin */
			q->rear = 0;
		}
		q->data[q->rear] = x;
	}
	else printf("alan yok\n");
}
int dequeue(queue *q) {
	if (!isEmpty(q)) {
		int x = q->data[q->front];
		q->front++;
		q->cnt--;
		if (q->front == data_size) {
			/*tasma hatasýný önlemek için son son eleman silindiðinde front ilk elemaný göstersin*/
			q->front = 0;
		}
		return x;
	}
	
}
























