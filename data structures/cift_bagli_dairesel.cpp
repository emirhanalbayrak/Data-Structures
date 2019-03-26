#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node *next;
	struct node *prev;
};typedef struct node node;
 node *head=NULL;
void ekle();
void yazdir(node *);
void insert_first();
void add_then();
void sil();
int main(){
	int a;
	printf("kac eleman eklenecek");scanf("%d",&a);
	for(int i=0;i<a;i++){
		ekle();
	}
     yazdir(head);
     insert_first();
     yazdir(head);
     add_then();
     yazdir(head);
     sil();
     yazdir(head);
}
void ekle(){
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		printf("enter a data");scanf("%d",&head->key);
		head->next=head;
		head->prev=head;
	}
	else{
		node *p=head;
		node *temp=(node*)malloc(sizeof(node));
		printf("enter a data ");scanf("%d",&temp->key);
		while(p->next!=head){
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
		head->prev=temp;
		temp->next=head;
		
	}
}
void yazdir(node *head){
	 node *temp=head;
	 printf("%d\n",temp->key);
	 
	 temp=temp->next;
	 while(temp!=head){
	 	printf("%d\n",temp->key);
	 	temp=temp->next;
	 	 	 
	 }
	
}
void insert_first(){
	node *temp=head,*yeni;
	yeni=(node*)malloc(sizeof(node));
	printf("enter a new data insert of firs node");scanf("%d",&yeni->key);
	head->prev->next=yeni;
	yeni->next=head;
	yeni->prev=head->prev;
	head->prev=yeni;
	head=yeni;
}
void add_then(){
	node *p=head;
	int a;
	node*yeni=(node*)malloc(sizeof(node));
	printf("hangi ara numaradan once eklenecek");scanf("%d",&a);
	
	if(p->key==a){
		insert_first();
	}
	else{
	    printf("enter a key");scanf("%d",&yeni->key);
	
		while(p->key!=a && p->next!=head){
			p=p->next;
		}
	if(p->key==a){
		   	p->prev->next=yeni;
		    yeni->prev=p->prev;
		    yeni->next=p;
		    p->prev=yeni;
	}
	else{
		ekle();
	}
	
	}
}
 void sil(){
 	int a;
 	node *p=head;
 	printf("hangi oge silinecek\n");
 	scanf("%d",&a);
 	if(p->key==a){
 		head->prev->next=p->next;
 		p->prev=head->prev;
 		head=p->next;
 		free(p);
	 }
	 else {
	 	p=p->next;
	 	while(p->key!=a && p!=head){
	 		p=p->next;
		 }
		 if(p->key==a){
		 p->prev->next=p->next;
		 p->next->prev=p->prev;
		 free(p);
	   }
	   else if(p==head ){
	   	printf("silinecek oge yok");
	   }
	 }
 }	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

