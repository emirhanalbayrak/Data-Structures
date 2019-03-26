#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node *next;
	struct node *prev;
	int key;
}; typedef struct node node;
void push(int);
void yaz(node*);
int pop(node*);
int x = 0;
node *head=NULL;
int main() {
	node *s;
	push(10);
	push(20);
	push(30);
	yaz(head);
	printf("..%d\n", pop(head));
	printf("...%d\n", pop(head));
	yaz(head);
	
	getchar();
}
void push(int x) {
	
	if (head==NULL) {
		head = (node*)malloc(sizeof(node));
		head->key = x;
		head->next = NULL;
		head->prev = NULL;
		x++;
	}
	else {
	node *p = head;
		node *yeni = (node*)malloc(sizeof(node));
		yeni->key = x;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = yeni;
		yeni->prev = p;
		yeni->next = NULL;
		p->prev = NULL;
		x++;
	    
	}
	

}
int pop(node *head) {
	node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	if (temp->next==NULL && temp->prev == NULL) {
		//listede sadece tek dugum kaldýgýnda
		int rvalue = temp->key;
		free(temp);
		return rvalue;
	}
	else {
		//listede birden fazla dugum varsa
		int value = temp->key;
		temp->prev->next = temp->next;
		free(temp);
		return value;
	}
}
void yaz(node *head) {
	node *p = head;
	while (p != NULL) {
		printf("%d\n", p->key);
		p = p->next;
   }
}
