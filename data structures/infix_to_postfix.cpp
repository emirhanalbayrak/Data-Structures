#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[20];
int top=-1;
void infix_to_postfix(char *);
void push(char );
char pop();
int first(char);
int main(void){
	char *s="a+b-c-d";
    infix_to_postfix(s);
	}

int first(char a){
	if(a=='+'||a=='-')
	return 1;
	else if(a=='*'||a=='/')
	return 2;
}
void push(char s){
	
    stack[++top]=s;
	
}
char pop(){
	if(top==-1)
	return -1;
	else return stack[top--];
}
void infix_to_postfix(char *s){
	while(*s!=NULL){
		if(*s=='('){
			push(*s);
		}
		else if(*s==')'){
			while(*s!='('){
				printf("%c",pop());
			}
		}
		else{
			while(first(stack[top])>=first(*s)){
				    printf("%c",pop());
			}
			push(*s);
		}
			 
	     s++;	
	}
	while(top!=-1){
		printf("%c",pop());
	}

	
	
}
