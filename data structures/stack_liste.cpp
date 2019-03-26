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
    push(40);
	printf("%d\n", pop(head));
	printf("%d\n",pop(head));
	printf("..........\n");
	 //listede hangi elemanýn kaldýgýný ogrenmek icin yaz fonksiyonu node *head tipinde parametre aldý.
	 yaz(head);

	
	
	getchar();
}
void push(int x){
	
	if (head==NULL) {
		head = (node*)malloc(sizeof(node));
		head->key = x;
		head->next = NULL;
		head->prev = NULL;
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
		x++;
	    
	}
}
int pop(node *head) {
	node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}if (temp->prev == NULL) {
		/*LIFO mantýgýna gore son dugumun silinmesi icin once son dugumun tuttugu degeri return ettim.
		  bu if ile stackte eger tek eleman kalmýssa onun silebilmek icin kontrol ettim */
		int rvalue = temp->key;
		free(temp);
		return rvalue;
	}
	else {
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
