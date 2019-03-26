#include<stdio.h>
#include<stdlib.h>
struct btree{
	int data;
	btree *right;
	btree *left;
};
btree *insert(btree *root,int data){
	if(root==NULL){
		root=(btree*)malloc(sizeof(btree));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else{
		if(root->data>data){
			root->left=insert(root->left,data);
		}
		       
		else
		       root->right=insert(root->right,data);       
	}
	return root;
}
void mirror(btree *root){
	btree *temp;
	if(root==NULL)
	           return;
	 mirror(root->left);
	 mirror(root->right);
	 temp=root->left;
	 root->left=root->right;
	 root->right=temp;
	
}
void inorder(btree *root){
	if(root==NULL)
	          return;
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	
}
void preorder(btree *root){
	if(root==NULL)
	         return;
	printf("%d  ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(btree *root){
	if(root==NULL)
	       return;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
}
int main(void){
	btree *node=NULL,*root=NULL;
	int a;
	do{
		printf("Agaca veri eklemek icin sayi giriniz");
	    scanf("%d",&a);
		if(a!=-1)
		    root=insert(root,a);
		   
	}
	while(a!=-1);
	mirror(root);

	printf("inorder   :");
	inorder(root);
	printf("\n");
	
	printf("preorder  :");
	preorder(root);
	printf("\n");
	printf("postorder :");
	postorder(root);
}
