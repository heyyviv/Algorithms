#include<iostream>
using namespace std;

class BST{

	int data;
	BST *left,*right;
public:
	BST();
	BST(int);
	BST* insert(BST *,int);
	void inorder(BST *);
	BST* deletetree(BST *,int);
	BST* minvalue(BST*);

};

BST :: BST(): data(0),left(NULL),right(NULL){}

BST :: BST(int value){
	data=value;
	left=right=NULL;
}

BST* BST:: insert(BST * root,int data){
	if(!root){
		return new BST(data);
	}
	if(data>root->data){
		root->right=insert( root->right,data);
	}else{
		root->left=insert(root->left,data);
	}
	return root;
}

BST* BST:: minvalue(BST* current){
	BST* temp=current;
	while(temp!=NULL && temp->left!=NULL){
		temp=temp->left;
	}
	return temp;
}
BST* BST:: deletetree(BST* root,int key){
	if(root==NULL){
		return root;
	}
	if(root->data<key){
		root->left=deletetree(root->left,key);
	}else if(root->data>key){
		root->right=deletetree(root->right,key);
	}else{
		if(root->left == NULL){
			BST* temp=root->right;
			free(root);
			return temp;
		}else if(root->right == NULL){
			BST *temp=root->left;
			free(root);
			return temp;
		}
		BST* temp=minvalue(root->right);
		root->data=temp->data;
		root->right=deletetree(root->right,temp->data);

	}
	return root;

}

void BST :: inorder(BST* root){
	if(!root){
		return ;
	}
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

int main(){
	BST b,*root=NULL;
	root=b.insert(root,50);
	b.insert(root,99);
	b.insert(root,32);
	b.insert(root,66);
	b.inorder(root);
	b.deletetree(root,32);
	b.inorder(root);
	return 0;

}