#include<stdio.h>
#include<stdlib.h>

struct ListNode {
  int data;
  struct ListNode* next;
};

// time complexity : O(n)
//space complexity : O(1)
int ListSize(struct ListNode *head){
  struct ListNode *cur=head;
  int l=1;
  while(cur!=NULL){
    l++;
    cur=cur->next;
  }
  return l;
}

void insertNode(struct ListNode *head,int data,int pos){
  struct ListNode* p;
  struct ListNode* q;
  struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
  newNode->data=data;
  if(head==NULL){head->data=data;return ;}
  int cur=1;
  p=head;
  if(pos==1){
    newNode->next=head;
    head=newNode;
  }else{
    while(p!=NULL && cur<pos){
      cur++;
      q=p;
      p=p->next;
    }
    q->next=newNode;
    newNode->next=p;
  }

}

void deleteNode(struct ListNode* head,int pos){
  if(head==NULL){return ;}
  struct ListNode* p;
  struct ListNode* q;
  int cur=1;
  p=head;
  if(pos==1){
    head=head->next;
    free(p);
    return ;
  }else{
    while(p!=NULL && cur<pos){
      cur++;
      q=p;
      p=p->next;
    }
    if(p==NULL){return;}
    q->next=p->next;
    free(p);
  }

}

void show(struct ListNode* head){
  struct ListNode* cur=head;
  while(cur!=NULL){
    printf("%d \n",cur->data);
    cur=cur->next;
  }
}


int main(){
  struct ListNode* head =(struct ListNode*)malloc(sizeof(struct ListNode));
  int n;
  scanf("%d",&n);
  int d,p;
  scanf("%d %d",&d,&p);
  head->data=d;
  n--;
  for(int i=0;i<n;i++){
    scanf("%d %d",&d,&p);
    insertNode(head,d,p);
  }
  printf("%d \n",ListSize(head));
  show(head);
  //enter code to create linked list data structure;
  return 0;
}
