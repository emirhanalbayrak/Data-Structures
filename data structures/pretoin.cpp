#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define data_size 50
char *stack[data_size];
int top=0;
void push(char *s);
char *pop();
char *pretoin(char*);

int main(void){
	char s[8]="+a-*bcd";
	strrev(s);
	pretoin(s);
	printf("%s",stack[0]);
}
void push(char *s){
	if(top==data_size-1){
		printf("alan dolu");
	}
	else{
		int uzunluk=strlen(s);
	stack[top]=(char*)malloc((uzunluk+1)*sizeof(char));
	strcpy(stack[top],s);
	*(stack[top]+(uzunluk+1))=NULL;
	top++;
	}
	
}
char *pop(){
	if(top==0)
	       printf("dur\n");
	else
	     return stack[top--];
	 
}
char *pretoin(char *s){
	char *c1,*c2,prefix[20];
	for (int j = 0; j < 20; j++)
				prefix[j] = '\0';
	
	while(*s!=NULL){
		if(*s=='+'||*s=='-'||*s=='*'||*s=='/'){
		   c1=pop();
		   c2=pop();
		   strcat(prefix,c1);
		   strcat(prefix,s);
		   strcat(prefix,c2);
		   int temp=strlen(c1)+strlen(c2);
		   prefix[temp+1]=NULL;
		   push(prefix);
		   for (int j = 0; j < 20; j++)
				prefix[j] = '\0';
		}
		else{
			push(s);
		}
	   s++;	
	}
	return stack[0];
}
