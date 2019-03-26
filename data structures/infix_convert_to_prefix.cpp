#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void infix_to_prefix(char *);
int first(char);
void push(char);
char pop();
char stack[50];
int top = -1;
void push(char s) {
	stack[++top] = s;
}
char pop() {
	if (top == -1) {
		return -1;
	}
	else {
		return stack[top--];
	}
}
int first(char s) {
	if (s == '+' || s == '-')
		return 1;
	else if (s == '*' || s == '/')
		return 2;

}
int main(void) {
	int uzunluk = 0, i = 0,j=0;
	char s[9] = "a+b*c-d";
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
	infix_to_prefix(dizi);
	getchar();
}
void infix_to_prefix(char *s) {
	char dizi[8];
	int i = 0;
	while (*s != NULL) {

		if (*s == '*' || *s == '/' || *s == '+' || *s == '-') {
			
			if (first(*s) >= first(stack[top])) {
				push(*s);
			}
			else {
				while (top != -1) {
					char c = pop();
					dizi[i] = c;
					i++;
				}
				push(*s);
			}

		}
		else {
			dizi[i] = *s;
			i++;
		}
		s++;
	}
	while (top != -1) {
		char c = pop();
		dizi[i] = c;
		i++;
	}
	dizi[i] = NULL;
	int k = 0;
	while (dizi[k] != NULL) {
		printf("%c", dizi[k]);
		k++;
	}
	printf("\n...............................\n");
	int lenght=strlen(dizi);
	for(int i=lenght-1;i>=0;i--){
		printf("%c",dizi[i]);
	}
	
	
	
	getchar();
}

