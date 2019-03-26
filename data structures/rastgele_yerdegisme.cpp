#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(void){
	char *s="emirhan";
	int boyut=strlen(s);
	int i=0;
	char *yeni=(char*)malloc((boyut+1)*sizeof(char));
	for(int k=0;k<boyut;k++){
		*(yeni+k)='\0';
	}
	
	while(1){
		    srand(time(NULL));
	        int rastgele=0+rand()%7;
			if(*(yeni+rastgele)=='\0'){
			    *(yeni+rastgele)=*(s+rastgele);
			    printf("%c",*(yeni+rastgele));
			
		     }
		     
        }
		
	
	
}

