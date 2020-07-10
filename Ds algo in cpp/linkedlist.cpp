#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

void push(Node** head,int data){
	Node* new_node=new Node();
	new_node->data=data;
	new_node->next=NULL;
	if(*head==NULL){
		*head=new_node;
		return;
	}
	Node* temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
	return;
}

void printlist(Node** head){
	Node *temp=*head;
	while(temp->next!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	return;
}



int main(){
	Node* head = NULL;
	push(&head,5);
	push(&head,6);
	push(&head,18);
	push(&head,33);
	push(&head,66);
	printlist(&head);
	return 0;

}