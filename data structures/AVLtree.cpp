#include<stdlib.h>
#include<stdio.h>
typedef struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
}node;
int height(node*);
int maxvalue(node*);
node *rightRotate(node*);
node *leftRotate(node*);
node *insert(node*);
node *rightRotate(node *z){
    /*
           3 =z
		  / 	
	    2=y
	   / 
	  1=x
	*/	
  node *temp=z->left;
  z->left=temp->right;
  temp->right=z;
  z->height=height(z);
  temp->height=height(temp);
  return temp;	
}
node *leftRotate(node *z){
	  /*
           3 =z
		   	\
	         2=y
	           \
	            1=x
	*/	
	node *temp=z->right;
	z->right=temp->left;
	temp->left=z;
	z->height=height(z);
	temp->height=height(temp);
	return temp;
	
}
node *leftRightRotate(node *z){
	z->left=leftRotate(z->left);
	return rightRotate(z);
}
node *rightLeftRotate(node *z){
	z->right=rightRotate(z->right);
	return leftRotate(z);
}
int height(node *root){
	if(root==NULL)
	          return -1;
	else{
		
		int left_height,right_height;
		left_height=height(root->left);
		right_height=height(root->right);
		if(right_height>left_height)
		           return right_height+1;
		else
		           return left_height+1;           
	}          
}
int maxvalue(node *root){
	if(root!=NULL){
		
	if(root->right==NULL)
	           return root->data;	
		
	maxvalue(root->right);	
		
	}
	
	
}
node *insert(node * root,int data){
	if(root==NULL){
	    root=(node*)malloc(sizeof(node));
		root->right=NULL;
		root->left=NULL;
		root->data=data;
		root->height=-1;	
	}
	else{
	   if(data<root->data)
	   	      root->left=insert(root->left,data);
	   	
	   else
		      root->right=insert(root->right,data);	
	}
	return root;
}
void inorder(node *root){
	if(root!=NULL){
	inorder(root->left);
	printf("%d-%d\n",root->data,height(root));
	inorder(root->right);
	}
	
	
}
node *avl(node *root,int data){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->data=data;
		root->left=root->right=NULL;
		
		
	}
 else {
		if(data<root->data)
		           root->left=avl(root->left,data);
		else if(data>root->data)
		           root->right=avl(root->right,data);
				   
				   root->height=height(root);
	if(height(root->left)-height(root->right)>1 && data<root->left->data)
	                      return rightRotate(root);
	if(height(root->left)-height(root->right)>1 && data>root->left->data)
	                      return leftRightRotate(root);
	if(height(root->left)-height(root->right)<-1 && data>root->right->data)
	                      return leftRotate(root);
	if(height(root->left)-height(root->right)<-1 && data<root->right->data)                      
						   return rightLeftRotate(root);          	
	}
					   
    return root;						                        
}
int main(void){
	node * root=NULL;
	root=avl(root,10);
	root=avl(root,9);
	root=avl(root,20);
	root=avl(root,30);
	root=avl(root,19);
	root=avl(root,29);
	height(root);
	//root=avl(root,10);
	//root=avl(root,11);
	
	
	inorder(root);
	
}









