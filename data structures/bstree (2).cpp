#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int data;
	int height;
	tree *left;
	tree *right;
}tree;
tree *insertnode(tree *root,int data){
	if(root==NULL){
		root=(tree*)malloc(sizeof(tree));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
	}
	else{
		if(data>root->data)
		       root->right=insertnode(root->right,data);
		else 
		       root->left=insertnode(root->left,data);       
		
		
	}
	return root;
}
int max(tree *root){
	if(root!=NULL){
		if(root->right==NULL)
		       return root->data;
		max(root->right);
	}
}
int min(tree *root){
	if(root!=NULL){
		if(root->left==NULL)
		       return root->data;
		min(root->left);       
	}
}
tree *delete_node(tree *root,int data){
     if(root->data==data){
     	if(root->left==NULL && root->right==NULL){
     		free(root);
     		return NULL;
		 }
		 else if(root->right!=NULL){
		 	root->data=min(root->right);
		 	root->right=delete_node(root->right,min(root->right));
		 	return root;
		 }
		 else if(root->left!=NULL){
		 	root->data= max(root->left);
		 	root->left=delete_node(root->left,max(root->left));
		 	return root;
		 }
	 }
	 else{
	 	if(data>root->data)
	 	         root->right=delete_node(root->right,data);
	 	else
		         root->left=delete_node(root->left,data);         
	 	
	 	
	 }

return root;

   
}
void inorder(tree *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d %d\n",root->data,root->height);
		inorder(root->right);
	}
}
void preorder(tree *root){
	
	if(root!=NULL){
		
		printf("%3d\n",root->data);		
		preorder(root->left);
		preorder(root->right);
	}

}
void postorder(tree *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->data);
	}
}
int size_node(tree *root){
	if(root==NULL)
	        return 0;
	else return size_node(root->left)+1+size_node(root->right);        
}
void mirror(tree *root){
	if(root!=NULL){
		tree * temp;
		mirror(root->left);
		mirror(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
int height(tree *root){
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
tree *rightRotate(tree *z){
	tree *temp=z->left;
	z->left=temp->right;
	temp->right=z;
	z->height=height(z);
	temp->height=height(temp);
}
tree *leftRotate(tree *z){
	tree *temp=z->right;
	z->right=temp->left;
	temp->left=z;
	z->height=height(z);
	temp->height=height(temp);
	return temp;
}
tree *leftRightRotate(tree *z){
	z->left=leftRotate(z->left);
	return rightRotate(z);
}
tree * rightLeftRotate(tree *z){
	z->right=rightRotate(z->right);
	return leftRotate(z);
}
tree *avl(tree *root,int data){
	if(root!=NULL){
		if(data<root->data)
			      root->left=avl(root->left,data);
		else if(data>root->data)
		          root->right=avl(root->right,data);
		else
		        return root;
		root->height=height(root);
		if(height(root->left)-height(root->right)>1 && data <root->left->data)
		            return rightRotate(root);				  	      
		if(height(root->left)-height(root->right)>1 && data >root->left->data)
		            return leftRightRotate(root);
		if(height(root->left)-height(root->right)<-1 && data >root->right->data)
		            return leftRotate(root);
		if(height(root->left)-height(root->right)<-1 && data <root->left->data)
		            return rightLeftRotate(root);					            
	}
	else
	{
	tree *root1;
	root1=(tree*)malloc(sizeof(tree));
	root1->right=NULL;
	root1->left=NULL;
	root1->data=data;
	root1->height=height(root);
	return root1;
  }
return root;
}
int main(void){
	tree *root=NULL;
	root=avl(root,41);
	root=avl(root,20);
	root=avl(root,11);
	root=avl(root,29);
	root=avl(root,24);
	root=avl(root,36);
	root=avl(root,65);
	root=avl(root,50);
	root=avl(root,72);
    root=avl(root,26);
	
	
	//mirror(root);
	
	inorder(root);
	
	preorder(root);
	printf("dugum sayisi %d\n",size_node(root));
	printf("yukseklik  %d",height(root));
	
}
