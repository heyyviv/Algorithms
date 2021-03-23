#include<stdio.h>
#include<stdlib.h>
#include<queue>

struct node{
  int data;
  node* left;
  node* right;
};

node* newNode(int data){
  struct node* nn= (struct node*)malloc(sizeof(struct node));
  nn->data=data;
  nn->left=NULL;
  nn->right=NULL;
  return nn;
}

node* insert(struct node* root,int data){
  if(root == NULL){
    root=newNode(data);
  }else if(root->data <=data){
    root->left=insert(root->left,data);
  }else{
    root->right=insert(root->right,data);
  }
  return root;
}

bool search(struct node* root,int data){
  if(root==NULL){
    return false;
  }else if(root->data==data){
    return true;
  }else if(root->data <= data){
    return search(root->right,data);
  }else{
    return search(root->left,data);
  }
}

int findHeight(struct node* root){
  if(root==NULL){
    return -1;
  }
  int l=findHeight(root->left);
  int r=findHeight(root->right);
  return max(l,r)+1;
}

void levelOrder( struct node* root){
  if(root==NULL){
    return ;
  }
  queue<struct node*> q;
  q.push(root);
  while(!q.empty()){
    struct node* cur=q.front();
    if(cur->left!=NULL){q.push(cur->left);}
    if(cur->right!=NULL){q.push(cur->right);}
    q.pop();
  }

}

void preoder(struct node* root){
  if(root==NULL){return ;}
  printf("%d ",root->data );
  preoder(root->left);
  preoder(root->right);
}

void postorder(struct node* root){
  if(root==NULL){return ;}
  preoder(root->left);
  preoder(root->right);
  printf("%d ",root->data );

}

void inorder(struct node* root){
  if(root==NULL){return ;}
  preoder(root->left);
  printf("%d ",root->data );
  preoder(root->right);

}

bool isBST(struct node* root,int maxV,int minV){
  if(root==NULL){return true;}
  if(root->data>minV && root->data<maxv
      && isBST(root->left,minV,root->data)
      && isBST(root->right,root->data,maxV)){
        return true;
      }
      return false;
}

bool binaryUTIL(struct node* root){
  if(isBST(root,INT_MAX,INT_MIN)){
    return true;
  }else{
    return false;
  }
}

struct node* findMIN(struct node* root){
  while(root->left!=NULL){
    root=root->left;
  }
  return root;
}

struct node* deleteNode(struct node* root,int data){
  if(root==NULL){return NULL;}
  else if(root->data < data){root->right=deleteNode(root->right,data);}
  else if(root->data > data){root->left=deleteNode(root->left,data);}
  else{
    if(root->left==NULL && root->right==NULL){
      return NULL;
    }else if(root->left==NULL){
      struct node* temp=root;
      root=root->right;
      free(temp);
      return root;
    }else if(root->right==NULL){
      struct node* temp=root;
      root=root->left;
      free(temp);
      return root;
    }else{
      struct node* temp=findMIN(root->right);
      root->data=temp->data;
      root->right=deleteNode(root->right,temp->data);

    }
  }
}

int main(){

  return 0;
}
