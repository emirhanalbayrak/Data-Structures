#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void fonksiyon();
int main(void){
	fonksiyon();
}
void fonksiyon(){
	char s[4];
	printf("klavyeden bir veri giriniz");
	gets(s);
	int i=0;
	while(s[i]!=45 || s[i+1]!=49){
		if(*s>=65 && *s<=90 || *s>=97 && *s<=122){
			printf("harf girdiniz\n");
		}
		else if(*s>=48 && *s<=57){
			printf("sayi girdiniz\n");
		}
		else{
			printf("ozel karakter girdiniz\n");
		}
		printf("klavyeden bir veri giriniz");
		gets(s);
		
	}
}
