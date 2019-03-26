#include<stdio.h>
#include<stdlib.h>
struct bstree{
	int data;
	bstree *left;
	bstree *right;
};typedef struct bstree bstree;
bstree *insert(bstree *root,int data){
	if(root==NULL){
		root=(bstree*)malloc(sizeof(bstree));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else {
		if(data>root->data)
		     root->right=insert(root->right,data);
		else
		     root->left=insert(root->left,data);     
	}
	return root;
}
void inorder(bstree *root){
	if(root!=NULL){
				inorder(root->left);
				printf("%d ",root->data);
				inorder(root->right);
	}
}
 void mirror(bstree *root){
 	bstree *temp;
 	if(root==NULL)
 	         return;
    else{
		    mirror(root->left);
		 	mirror(root->right);
		 	temp=root->left;
		 	root->left=root->right;
		 	root->right=temp;
	}
 	
 }
 int main(void){
 	bstree *node=NULL;
 	node=insert(node,15);
 	node=insert(node,12);
 	node=insert(node,20);
 	node=insert(node,6);
 	node=insert(node,13);
 	node=insert(node,17);
 	node=insert(node,22);
 	inorder(node);
 	mirror(node);
 	printf("\n");
 	inorder(node);
 	
 	
 	
 }
