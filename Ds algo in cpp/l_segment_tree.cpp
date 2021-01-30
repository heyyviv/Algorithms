//https://www.codechef.com/problems/MULTQ3
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
#include<array>
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define PI 3.1415926535
using namespace std;

struct node{
  int arr[3];
};
node ST[400004];
int lazy[400004];

 void buildST(int si,int ss,int se){
   if(ss==se){
     ST[si].arr[0]=1;
     ST[si].arr[1]=0;
     ST[si].arr[2]=0;
     return ;
   }
   int mid=(ss+se)/2;
   buildST(2*si,ss,mid);
   buildST(2*si+1,mid+1,se);
   ST[si].arr[0]=ST[2*si].arr[0]+ST[2*si+1].arr[0];
   ST[si].arr[1]=ST[2*si].arr[1]+ST[2*si+1].arr[1];
   ST[si].arr[2]=ST[2*si].arr[2]+ST[2*si+1].arr[2];
 }

 void shift(int si){
   int a=ST[si].arr[2];
   ST[si].arr[2]=ST[si].arr[1];
   ST[si].arr[1]=ST[si].arr[0];
   ST[si].arr[0]=a;
 }

 void update(int si,int qs,int qe,int ss,int se){
   if(lazy[si]!=0){
     int add=lazy[si];
     lazy[si]=0;
     if(ss!=se){
     lazy[2*si]+=add;
     lazy[2*si+1]+=add;
   }
     add%=3;
     for(int i=0;i<add;i++){
       shift(si);
     }
   }
   if(ss>qe || se<qs){return ;}
   if(qs<=ss && qe>=se){
     shift(si);
     if(ss!=se){
       lazy[2*si]++;
       lazy[2*si+1]++;
     }
     return ;
   }
   int mid=(ss+se)/2;
   update(2*si,qs,qe,ss,mid);
   update(2*si+1,qs,qe,mid+1,se);
   ST[si].arr[0]=ST[2*si].arr[0]+ST[2*si+1].arr[0];
   ST[si].arr[1]=ST[2*si].arr[1]+ST[2*si+1].arr[1];
   ST[si].arr[2]=ST[2*si].arr[2]+ST[2*si+1].arr[2];


 }

 int query(int si,int qs,int qe,int ss,int se){
   if(lazy[si]!=0){
     int add=lazy[si];
     lazy[si]=0;
     if(ss!=se){
     lazy[2*si]+=add;
     lazy[2*si+1]+=add;}

     add%=3;
     for(int i=0;i<add;i++){
       shift(si);
     }


   }
   if(ss>qe || se<qs){return 0;}
   if(ss>=qs && se<=qe){return ST[si].arr[0];}
   int mid=(ss+se)/2;
   int l=query(2*si,qs,qe,ss,mid);
   int r=query(2*si+1,qs,qe,mid+1,se);
   return l+r;

 }


int main()
{
    fastio
    int n,q;
    cin>>n>>q;

    int c,a,b;
    buildST(1,1,n);
    while(q--){
      cin>>c>>a>>b;
      if(c==0){
        update(1,a+1,b+1,1,n);
      }else{
        cout<<query(1,a+1,b+1,1,n)<<endl;
      }
    }




    return 0;
}
