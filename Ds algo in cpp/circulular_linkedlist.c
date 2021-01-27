#include<stdlib.h>
#include<stdio.h>

struct ListNode {
  int data;
  struct ListNode* next;
}

int sizeList(struct ListNode* head){
  struct ListNode* cur=head;
  int l=0;
  if(cur==NULL){return 0;}
  do{
    cur=cur->next;
    l++;
  }while(cur!=head);
  return l;
}

void addNodeLast(struct ListNode* head,int data,int pos){
    struct ListNode* cur=head;
    struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data=data;
    while(cur->next!=head){
      cur=cur->next;
    }
    newNode->next=newNode;
    if(head){
      newNode->next=head;
      cur->next=newNode;
    }else{
      head=newNode;
    }
}

void addNodeStart(struct ListNode* head,int data,int pos){
    struct ListNode* cur=head;
    struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data=data;
    while(cur->next!=head){
      cur=cur->next;
    }
    newNode->next=newNode;
    if(head){
      newNode->next=head;
      cur->next=newNode;
      head=newNode;
    }else{
      head=newNode;
    }
}



int main(){

}
