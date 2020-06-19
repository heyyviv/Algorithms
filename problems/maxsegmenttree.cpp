
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<algorithm>
#define INF 0x3f3f
using namespace std;
struct Node{
    int maxprefix;
    int maxsufffix;
    int maxsubaray;
    int totalsum;
    Node(){
        maxprefix=maxsubaray=maxsubaray=-INF;
        totalsum=-INF;
    }
};
int midi(int start,int end){
    return (end+start)/2;
}

/*int max(int a,int b){
    return (a<b)?b:a;
}*/

Node merge(Node left,Node right){
    Node ss;
    ss.maxprefix=max(left.maxprefix,left.totalsum+right.maxprefix);
    ss.maxsufffix=max(right.maxsufffix,right.totalsum+left.maxsufffix);
    ss.totalsum=left.totalsum+right.totalsum;
    ss.maxsubaray=max({left.maxsubaray,right.maxsubaray,left.maxsufffix+right.maxprefix});
    return ss;
}

void contstrucUtil(Node* tree,int start,int end,int arr[],int index){
    if(start==end){
        tree[index].maxsubaray=arr[start];
        tree[index].maxprefix=arr[start];
        tree[index].maxsufffix=arr[start];
        tree[index].totalsum=arr[start];
        return ;
    }
    int mid=midi(start,end);
    contstrucUtil(tree,start,mid,arr,2*index);
    contstrucUtil(tree,mid+1,end,arr,2*index+1);
    tree[index]=merge(tree[2*index],tree[2*index+1]);
}

Node* constructtree(int arr[],int n){
    int x=(int)(ceil(log2(n)));
    int size=2*(int)(pow(2,x))-1;
    Node* tree=new Node[size];
    contstrucUtil(tree,0,n-1,arr,1);
    return tree;
}

Node queryutil(Node* tree,int ss,int se,int qs,int qe,int index){
    if(ss>qe||se<qs){
        Node nnull;
        return nnull;
    }
    if(ss>=qs && se<=qe){
        return tree[index];
    }
    int mid=midi(ss,se);
    Node left=queryutil(tree,ss,mid,qs,qe,2*index);
    Node right=queryutil(tree,mid+1,se,qs,qe,2*index+1);
    Node yes=merge(left,right);
    return yes;
}

int query(int start,int end,Node* tree,int n){
    Node pp=queryutil(tree,0,n-1,start,end,1);
    return pp.maxsubaray;
}

int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* tree=constructtree(arr,n);
    int k;
    cin>>k;
    int start,end;
    for(int i=0;i<k;i++){
        cin>>start>>end;
        cout<<query(start-1,end-1,tree,n)<<endl;
    }


return 0;

}

