#include<stdio.h>
#include<stdlib.h>

struct ListNode {
  int data;
  struct ListNode* next;
  struct ListNode* prev;
};

void insertNode(struct ListNode* head,int pos,int data){
  struct ListNode* p;
  int cur=1;
  struct ListNode* newNode = ( struct ListNode*)malloc(sizeof(struct ListNode));
  newNode->data=data;
  p=head;
  if(pos==1){
    newNode->next=p;
    newNode->prev=NULL;
    if(p){
      p->prev=newNode;
    }
    head=newNode;
    return ;
  }else{
    while(p->next!=NULL && cur<(pos-1)){
      cur++;
      p=p->next;
    }
    if(cur!=pos){return ;}
    newNode->next=p->next;
    newNode->prev=p;
    if(p->next){
      p->next->prev=newNode;
    }
    p->next=newNode;
    return ;

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
    head->prev=NULL;
  }else{
    while(p->next!=NULL && cur<(pos-1)){
      cur++;
      p=p->next;
    }
    q=p->prev;
    q->next=p->next;
    if(p->next){
      p->next->prev=q;
    }else{
      q->next=NULL;
    }

    return ;
  }
}

void showList(struct ListNode* head){
  struct ListNode* cur=head;
  while(cur!=NULL){
    printf("%d /n",cur->data);
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
  head->next=NULL;
  head->prev=NULL;
  n--;
  for(int i=0;i<n;i++){
    scanf("%d %d",&d,&p);
    insertNode(head,d,p);
  }
  showList(head);

  return 0;
}
