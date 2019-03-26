#include<stdio.h>
#include<stdlib.h>
#define data_size 12


void insertto_max_heap(int *array,int data,int index){
	if(index==data_size)
	        printf("alan yok");
	else{
		array[index]=data;
		while(index!=1 &&array[index/2]<array[index]){
			int temp;
			temp=array[index/2];
			array[index/2]=array[index];
			array[index]=temp;
			index=index/2;
		}
	}
	
}
int delete_max_heap(int *array,int index){
	int max,i=1;
	if(index==1)
	          printf("hesap bos");
	else{
		max=array[i];
		array[i]=array[index-1];
		array[index-1]=0;
		while(array[i]<array[2*i] || array[i]<array[2*i+1] ){
			if(array[2*i]>array[2*i+1]){
				int temp=array[i];
				array[i]=array[2*i];
				array[2*i]=temp;
				i=i*2;
			}
			else{
				int temp=array[i];
				array[i]=array[2*i+1];
				array[2*i+1]=temp;
				i=2*i+1;
			}
			
		}
		
		
	}          
	return max;
}
int main(void){
	int array[data_size];
	int index=1;
	insertto_max_heap(array,21,index++);
	insertto_max_heap(array,15,index++);
	insertto_max_heap(array,18,index++);
	insertto_max_heap(array,11,index++);
	insertto_max_heap(array,13,index++);
	insertto_max_heap(array,1,index++);
	insertto_max_heap(array,9,index++);
	insertto_max_heap(array,2,index++);
	insertto_max_heap(array,7,index++);
	insertto_max_heap(array,5,index++);
printf("%d\n",delete_max_heap(array,index));	
printf("%d\n",delete_max_heap(array,index));
printf("%d\n",delete_max_heap(array,index));
printf("%d\n",delete_max_heap(array,index));
printf("%d\n",delete_max_heap(array,index));	
printf("%d\n",delete_max_heap(array,index));
printf("%d\n",delete_max_heap(array,index));
printf("%d\n",delete_max_heap(array,index));
printf("%d\n",delete_max_heap(array,index));		
printf("%d\n\n",delete_max_heap(array,index));

printf("%d",index);

}






