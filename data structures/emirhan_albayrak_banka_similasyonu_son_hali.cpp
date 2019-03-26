#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define data_size 20

struct node{
	int siraNo;
	int gelis_suresi;
	int gise;
	int islem_zamani;
	int cikis_zamani;
	struct node *next;
};typedef struct node node;
int musteri=0;
int bekleme =0;
int cikis=0;
int bekleme2=0;
int cikis2=0;
int bekleme3=0;
int cikis3=0;
int ortalama1=0;
int ortalama2=0;
int ortalama3=0;
int en_uzun_bekleyen1=0;
int en_uzun_bekleyen2=0;
int en_uzun_bekleyen3=0;
struct gise_1{
	int musteri_sayisi_1;
	struct node *rear;
	struct node *front;
};typedef struct gise_1 gise_1;
struct gise_2{
	int musteri_sayisi_2;
	struct node *rear;
	struct node *front;
};typedef struct gise_2 gise_2;
struct gise_3{
	int musteri_sayisi_3;
	struct node *rear;
	struct node *front;
};typedef struct gise_3 gise_3;
 
typedef enum boolean{
	True=1,False=0
};typedef enum boolean boolean;
boolean isEmpty1(gise_1 *q){
	if(q->musteri_sayisi_1==0)
	      return True;
	else
	      return False;      
}
boolean isEmpty2(gise_2 *q){
	if(q->musteri_sayisi_2==0)
	      return True;
	else
	      return False;      
}
boolean isEmpty3(gise_3 *q){
	if(q->musteri_sayisi_3==0)
	      return True;
	else
	      return False;      
}
boolean isFull1(gise_1 *q){
	if(q->musteri_sayisi_1==data_size)
	       return True;
	else
	       return False;       
}
boolean isFull2(gise_2 *q){
	if(q->musteri_sayisi_2==data_size)
	       return True;
	else
	       return False;       
}
boolean isFull3(gise_3 *q){
	if(q->musteri_sayisi_3==data_size)
	       return True;
	else
	       return False;       
}
void first_value_1(gise_1 *q){
	q->front=q->rear=NULL;
	q->musteri_sayisi_1=0;
}
void first_value_2(gise_2 *q){
	q->front=q->rear=NULL;
	q->musteri_sayisi_2=0;
}
void first_value_3(gise_3 *q){
	q->front=q->rear=NULL;
	q->musteri_sayisi_3=0;
}

void enqueue1(gise_1 *q,int zaman){
	if(!isFull1(q)){
	
		node *temp=(node*)malloc(sizeof(node));
		temp->siraNo=q->musteri_sayisi_1+1; 
		temp->gelis_suresi=zaman;
		temp->gise=1;
		
		temp->next=NULL;
	    if(isEmpty1(q)){
	    	q->front=q->rear=temp;
		}
		else{
		q->rear->next=temp;
		q->rear=temp;
	}
	
	q->musteri_sayisi_1++;}

  else{
  	 printf("alan dolu");
  }
	    	
}
void enqueue2(gise_2 *q,int zaman){
	if(!isFull2(q)){
			node *temp=(node*)malloc(sizeof(node));
		temp->siraNo=q->musteri_sayisi_2+1;
		temp->gelis_suresi=zaman;
		temp->gise=2;
		
		temp->next=NULL;
	    if(isEmpty2(q)){
	    	q->front=q->rear=temp;
		}
		else{
		q->rear->next=temp;
		q->rear=temp;
	}
	q->musteri_sayisi_2++;
	}
	else{
		printf("alan dolu");
	}
		
}
void enqueue3(gise_3 *q,int zaman){
	if(!isFull3(q)){
		node *temp=(node*)malloc(sizeof(node));
		temp->siraNo=q->musteri_sayisi_3+1;
		temp->gelis_suresi=zaman;
		temp->gise=3;
		
		temp->next=NULL;
	    if(isEmpty3(q)){
	    	q->front=q->rear=temp;
		}
		else{
		q->rear->next=temp;
		q->rear=temp;
	}
	q->musteri_sayisi_3++;
		
	}
	else{
		printf("alan dolu");
	}	
}
void dequeue1(gise_1 *q,int musteri){
	int x=0;
	if(!isEmpty1(q)){
		int sure=0;
		int toplam=0;
		struct node *p=q->front;
		int y=p->gelis_suresi;
		int z=p->gise;
		bekleme=cikis-y;
		if(bekleme<0){
			bekleme=0;
		}
	    ortalama1+=bekleme;
	    if(bekleme>=en_uzun_bekleyen1){
	    	en_uzun_bekleyen1=bekleme;
		}
		
	    int rastgele=rand()%4;
	    if(rastgele==0){
	    	    
	     p->islem_zamani=3+rand()%8;
	    cikis=p->islem_zamani+p->gelis_suresi+bekleme;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik  EFT  islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme,cikis,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
	    
		}
		else if(rastgele==1){
			   
	    p->islem_zamani=10+rand()%11;
	    cikis=p->islem_zamani+p->gelis_suresi+bekleme;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Kredi Cekme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme,cikis,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
		    
		}
		else if(rastgele==2){
				
	    p->islem_zamani=2+rand()%11;
	    cikis=p->islem_zamani+p->gelis_suresi+bekleme;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Fatura Odeme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme,cikis,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
	    
		}
		else if(rastgele==3){
				
	    p->islem_zamani=2+rand()%6;
	    cikis=p->islem_zamani+p->gelis_suresi+bekleme;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Para Cekme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme,cikis,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");		
		}
		
		
		
		q->front=q->front->next;
		free(p);
		q->musteri_sayisi_1--;
	}
	else{
		printf("silinecek liste yok\n");
	}
	
}
void dequeue2(gise_2 *q,int musteri){
	if(!isEmpty2(q)){
		int sure=0;
		int toplam=0;
		struct node *p=q->front;
		int y=p->gelis_suresi;
		int z=p->gise;
		bekleme2=cikis2-y;
		if(bekleme2<0){
			bekleme2=0;
		}
		ortalama2+=bekleme2;
	if(bekleme2>=en_uzun_bekleyen2){
	    	en_uzun_bekleyen2=bekleme2;
		}
		
	    int rastgele=rand()%4;
	    if(rastgele==0){
	    	    
	     p->islem_zamani=3+rand()%8;
	    cikis2=p->islem_zamani+p->gelis_suresi+bekleme2;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik  EFT  islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme2,cikis2,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
	    
		}
		else if(rastgele==1){
			   
	    p->islem_zamani=10+rand()%11;
	    cikis2=p->islem_zamani+p->gelis_suresi+bekleme2;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Kredi Cekme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme2,cikis2,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
		    
		}
		else if(rastgele==2){
				
	    p->islem_zamani=2+rand()%11;
	    cikis2=p->islem_zamani+p->gelis_suresi+bekleme2;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Fatura Odeme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme2,cikis2,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
	    
		}
		else if(rastgele==3){
				
	    p->islem_zamani=2+rand()%6;
	    cikis2=p->islem_zamani+p->gelis_suresi+bekleme2;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Para Cekme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme2,cikis2,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");	
		}
		
		q->front=q->front->next;
		free(p);
		q->musteri_sayisi_2--;
	}
	else{
		printf("silinecek liste yok\n");
	}
	
}
void dequeue3(gise_3 *q,int musteri){
		
	if(!isEmpty3(q)){
		int sure=0;
		int toplam=0;
		struct node *p=q->front;
		int y=p->gelis_suresi;
		int z=p->gise;
		bekleme3=cikis3-y;
		if(bekleme3<0){
			bekleme3=0;
		}
		ortalama3+=bekleme3;
	    if(bekleme3>=en_uzun_bekleyen3){
	    	en_uzun_bekleyen3=bekleme3;
		}
		
	    int rastgele=rand()%4;
	    if(rastgele==0){
	    	    
	     p->islem_zamani=3+rand()%8;
	    cikis3=p->islem_zamani+p->gelis_suresi+bekleme3;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik  EFT  islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme3,cikis3,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
	    
		}
		else if(rastgele==1){
			   
	    p->islem_zamani=10+rand()%11;
	    cikis3=p->islem_zamani+p->gelis_suresi+bekleme3;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Kredi Cekme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme3,cikis3,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
		      
		}
		else if(rastgele==2){
				
	    p->islem_zamani=2+rand()%11;
	    cikis3=p->islem_zamani+p->gelis_suresi+bekleme3;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Fatura Odeme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme3,cikis3,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
	    
		}
		else if(rastgele==3){
				
	    p->islem_zamani=2+rand()%6;
	    cikis3=p->islem_zamani+p->gelis_suresi+bekleme3;
		printf("-------------------------------------------------------------------------------------------\n");
		printf("Musteri-%d  %d. Gisede %d. dakikada bankaya geldi\n",musteri+1,p->gise,p->gelis_suresi);
		printf("Musteri-%d  %d  Dakikalik Para Cekme islemi yapti %d dakika bekledi %d. Dakikada %d. Giseden cikti\n",musteri+1,p->islem_zamani,bekleme3,cikis3,p->gise);
		printf("--------------------------------------------------------------------------------------------\n");
	    
		
			
		}
		
		q->front=q->front->next;
		free(p);
		q->musteri_sayisi_3--;
	}
	else{
		printf("silinecek liste yok\n");
	}
	
}
void getir(gise_1 *q,gise_2 *p,gise_3 *k);
void ortalama_bekleme_suresi(int,int,int);
void en_fazla_bekleme(int en_uzun_bekleme1,int en_uzun_bekleme2,int en_uzun_bekleme3);
void en_fazla_musteri(int,int,int);
void siraya_ekle(gise_1 *q,gise_2 *p,gise_3 *k,int zaman);
int main(void){
    int zaman,rastgele,en_fazla_bekleyen=0,i=0,count1,count2,count3;
    gise_1 *q=(gise_1*)malloc(sizeof(gise_1));
    gise_2 *p=(gise_2*)malloc(sizeof(gise_2));
    gise_3 *k=(gise_3*)malloc(sizeof(gise_3));
    first_value_1(q);
    first_value_2(p);
    first_value_3(k);
    
	printf("simulasyon kac dakika calisacak ?");
	scanf("%d",&zaman);
	srand(time(NULL));
	
	for(i=0;i<zaman;i++){
		
		
		rastgele=rastgele+rand()%6;
		if(rastgele<=zaman){
			siraya_ekle(q,p,k,rastgele);
		}
		
	}
	count1=q->musteri_sayisi_1;
	count2=p->musteri_sayisi_2;
	count3=k->musteri_sayisi_3;
	getir(q,p,k);
	en_fazla_musteri(count1,count2,count3);
	en_fazla_bekleme(en_uzun_bekleyen1,en_uzun_bekleyen2,en_uzun_bekleyen3);
	ortalama_bekleme_suresi(count1,count2,count3);
	getir(q,p,k);
	
}
void en_fazla_musteri(int count1,int count2,int count3){
	int en_fazla_bekleyen;
	if(count1>=count2 && count1>=count3){
		en_fazla_bekleyen=count1;
		printf("\t1. Gisede en fazla musteri sayisi %d\n",en_fazla_bekleyen);
	}
	else if(count2>=count3){
		en_fazla_bekleyen=count2;
		printf("\t2. Gisede en fazla musteri sayisi %d\n",en_fazla_bekleyen);
	}
	else{
		en_fazla_bekleyen=count3;
		printf("\t3. Gisede en fazla musteri sayisi %d\n",en_fazla_bekleyen);
	}
}
void en_fazla_bekleme(int en_uzun_bekleyen1,int en_uzun_bekleyen2,int en_uzun_bekleyen3){
	if(en_uzun_bekleyen1>=en_uzun_bekleyen2 && en_uzun_bekleyen1>=en_uzun_bekleyen3){
	    	printf("\t1. gisede en fazla bekleyen %d. dakika\n",en_uzun_bekleyen1);
	}
	else if(en_uzun_bekleyen2>=en_uzun_bekleyen3){
			printf("\t2. gisede en fazla bekleyen %d. dakika \n",en_uzun_bekleyen2);
	}
	else{
			printf("\t3. gisede en fazla bekleyen %d. dakika\n",en_uzun_bekleyen3);
	}
}
void siraya_ekle(gise_1 *q,gise_2 *p,gise_3 *k,int zaman){
         int secim;
		if(q->musteri_sayisi_1<=p->musteri_sayisi_2 && q->musteri_sayisi_1<=k->musteri_sayisi_3 ){
			enqueue1(q,zaman);
		   
		}    
		else if(p->musteri_sayisi_2<=k->musteri_sayisi_3){
			enqueue2(p,zaman);
		    
		    secim=2;
		}
		         
		else{
			enqueue3(k,zaman); 
		    
		}
		
		
		                
	}	  	        

void ortalama_bekleme_suresi(int a,int b,int c){
	printf("\t1. gisede ortalama bekleme suresi %d   :\n",ortalama1/a);
	printf("\t2. gisede ortalama bekleme suresi %d   :\n",ortalama2/b);
	printf("\t3. gisede ortalama bekleme suresi %d   :\n",ortalama3/c);
}
void getir(gise_1 *q,gise_2 *p,gise_3 *k){
	while( !isEmpty1(q) || !isEmpty2(p) || !isEmpty3(k)){
		
		dequeue1(q,musteri);
		musteri=musteri+1;
		dequeue2(p,musteri);
		musteri=musteri+1;
		dequeue3(k,musteri);
		musteri=musteri+1;
		
	}
}

























