/*

Write a program to reverse the direction of a given singly-linked list. In otherwords, after the reversal
all pointers should now point backwards. Your algorithmshould take linear time.

*/


#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#define INF 10000999
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
#define PI 3.1415926535
using namespace std;

struct Node {
	int d;
	struct Node *next;
};

void insert(struct Node **head,int data){
	struct Node *temp;
	temp =(struct Node*)malloc(sizeof(struct Node));
	temp->d=data;
	temp->next=(*head);
	(*head)=temp;
}

void output(struct Node *head){
	if(head!=NULL){
		cout<<head->d<<endl;
		output(head->next);
	}
}

void reverse(struct Node **head){
	struct Node *next=NULL;
	struct Node *prev=NULL;
	struct Node *cur=(*head);
	while(cur!=NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	(*head)=prev;
}

int main(){
int n;
cout<<"enter size of list";
cin>>n;
int a;
struct Node *head=NULL;
for(int i=0;i<n;i++){
	cin>>a;
	insert(&head,a);
}
cout<<"original"<<endl;
output(head);
reverse(&head);
cout<<"after reversing"<<endl;
output(head);

return 0;
}
