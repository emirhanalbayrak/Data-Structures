#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void post_to_pre(char*);
char stack[50];
char stack2[50];
int top = -1;
int top1 = -1;
void push(char s) {
	stack[++top] = s;
}
void push2(char s) {
	stack2[++top1] = s;
}
char pop() {
	if (top == -1) {
		return -1;
	}
	else {
		return stack[top--];
	}
}
char pop2() {
	if (top1 == -1) {
		return -1;
	}
	else {
		return stack2[top1--];
	}
}
int first(char s) {
	if (s == '+' || s == '-')
		return 1;
	else if (s == '*' || s == '/')
		return 2;

}
int main(void){
	char *s="abc*+d-";
	int uzunluk = 0, i = 0,j=0;
	
	char dizi[9];
	uzunluk = strlen(s);
	for (i = uzunluk - 1; i >= 0; i--) {
		dizi[j] = s[i];
		j++;
		//printf("%3c\n", s[i]);
	}
	for (int i = 0; i < uzunluk; i++) {
		//printf("%c", dizi[i]);
	}
	post_to_pre(dizi);
	getchar();
	
}
void post_to_pre(char *s){
	char dizi[20];
	int i=0;
 while(*s!=NULL){
 	
	if(*s=='+'||*s=='-'||*s=='*'||*s=='/'){
		if(first(*s)<=first(stack[top])){
			
			push(*s);
		}
		else{
		char c,b,a;
		a=pop();
		b=pop2();
		c=pop();
		dizi[i]=a;
		i++;
		dizi[i]=b;
		i++;
		dizi[i]=c;
		i++;
		}
		push(*s);
		
	}
	else{
		push2(*s);
	}
	
	s++;
}
dizi[i]=NULL;
int k=0;
while(dizi[k]!=NULL){
	printf("%c",dizi[k]);
	k++;	
}
}

