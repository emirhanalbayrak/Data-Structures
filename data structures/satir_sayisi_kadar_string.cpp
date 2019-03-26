#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void string();
int main(void){
	string();
}
void string(){
	char string[20];
	printf("klavyeden veri giriniz");
	gets(string);
	int boyut=strlen(string);
	int satir_sayisi=0,i=0;
	while(string[i]!=NULL){
		satir_sayisi=i+1;
		int j=i;
		int k=i;
		int b=0;
		while(k!=-1){
		
			printf("%c",string[j]);
			j++;	
			k--;
			b++;
		}
		i=i+b;
		
		printf("\n");
		
	}
}
