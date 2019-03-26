#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * toinfix(char *);
char *word[100];
int yer = 0;
void push(char *);
char *pop();
void push(char *c) {
	int uzunluk = strlen(c);
	word[yer] = (char*)malloc((uzunluk + 1) * sizeof(char));
	strcpy(word[yer], c);
	*(word[yer] + (uzunluk + 1)) = '\0';
	yer++;

}

char *pop() {
	if (yer == 0)
		printf("poppps");

	return word[--yer];
}
int main(void) {

	char *s = "ABC*DE/F-G*-H*+";
	printf("Postfix : %s\n", s);
	toinfix(s);
	int length = strlen(word[0]);
	printf("infix   : %s\n", word[0]);
	return EXIT_SUCCESS;
}
char *toinfix(char *s) {
	int i, j, boyut = strlen(s);
	int temp = 0;
	char *op1, *op2;
	char str[20];
	for (j = 0; j < 20; j++)
		str[j] = '\0';
	for (i = 0; i < boyut; i++) {
		char c = *(s + i);
		char *d = (char*)malloc(sizeof(char) * 6);
		d[0] = c;
		d[1] = '\0';
		d[2] = '(';
		d[3] = '\0';
		d[4] = ')';
		d[5] = '\0';
		if ((c == '*') || (c == '/') || (c == '+') || (c == '-')) {			op2 = pop();
			op1 = pop();
			temp = strlen(op2) + strlen(op1);
			strcat(str, d + 2);
			strcat(str, op1);
			strcat(str, d);
			strcat(str, op2);
			strcat(str, d + 4);
			str[temp + 3] = '\0';
			push(str);
			for (j = 0; j < 20; j++)
				str[j] = '\0';

		} else {
			push(d);
		}
	}
	return word[0];
}

