#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}; typedef struct node node;
void insert_At_End();
void Print(node *);
void tersten(node *);
void insert_first();
void add_than();
void sil();
node *head=NULL;
int main() {
	int a;
	printf("kac tane dugum olusturulacak");
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		insert_At_End();
	}
	
	Print(head);
	insert_first();
	Print(head);
    add_than();
    Print(head);
    sil();
	Print(head);
	getchar();
	

}
void insert_At_End() {
	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
		printf("enter a data"); scanf("%d", &head->data);
		head->next = NULL;
		head->prev = NULL;
	}
	else {
		node *temp = head;
		node *temp2 = (node*)malloc(sizeof(node));
		printf("enter a data"); scanf("%d", &temp2->data);
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = temp2;
		temp2->prev = temp;
		temp2->next = NULL;

	}
}
void Print(node *head) {
	node *p = head;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	getchar();
}
void tersten(node *head) {
	node *p = head;
	while (p->next!= NULL) {
		p = p->next;
	}
	while (p != NULL) {
		printf("\t");
		printf("%d\n", p->data);
		p = p->prev;
	}
	getchar();
}
void insert_first() {
	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
		printf("enter a insert of first node data"); scanf("%d", &head->data);
		head->next = NULL;
		head->prev = NULL;
	}
	else {
		node *yeni, *temp = head;
		yeni = (node*)malloc(sizeof(node));
		printf("enter a insert of first new node data "); scanf("%d", &yeni->data);
		yeni->next = temp;
		temp->prev = yeni;
		yeni->prev = NULL;
		head = yeni;
	}
}
void add_than(){
	node *q,*p=head;
	int a;
	printf("hangi dugumden once eklenecek");scanf("%d",&a);
	node *yeni=(node*)malloc(sizeof(node));
	 	printf("yeni node enter a data");scanf("%d",&yeni->data);
     while(p->data!=a && p->next!=NULL){
     	     q=p;
     	     p=p->next;
	 }
	    
	 if(p->data==a){
	 	q->next=yeni;
	 	yeni->prev=q;
	 	yeni->next=p;
	 	p->prev=yeni;
	 }
	 else if(p->next==NULL){
	 	p->next=yeni;
	 	yeni->prev=p;
	 	yeni->next=NULL;
	 }
    	
	}
	void sil(){
		int a;
		printf("hangi dugum silinecek");scanf("%d",&a);
		node *q,*s,*temp=head;
		if(temp->data==a){
			head->next=temp->next;
			temp->next->prev=head;
			head->prev=NULL;
			free(temp);
		}
		else{
			while(temp->data!=a && temp->next!=NULL){
				    temp=temp->next;
				  
			}
			temp->prev->next=temp->next;
			if(temp->next!=NULL){
				temp->next->prev=temp->prev;
			}
			free(temp);
	
		}
	}
	
	
	
	

















