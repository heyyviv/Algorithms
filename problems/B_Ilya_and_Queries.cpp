//https://codeforces.com/problemset/problem/313/B


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

void swap(ll *r,ll *s)
{
   ll temp = *r;
   *r = *s;
   *s = temp;
   return; }

int getmid(int s,int e){
  return s+(e-s)/2;
}

int STutil(int arr[],int ss,int se,int* st,int si){
  if(ss==se){
    st[si]=arr[ss];
    return arr[ss];
  }
  int m=getmid(ss,se);
  st[si]=STutil(arr,ss,m,st,2*si+1)+STutil(arr,m+1,se,st,2*si+2);
  return st[si];
}

int* STcon(int arr[],int n){
  int x=(int)ceil(log2(n));
  int l=2*(int)pow(2,x)-1;
  int* st=new int[l];

  STutil(arr,0,n-1,st,0);
  return st;
}

int gsumUtil(int* st,int ss,int se,int l,int r,int si){
  if(l<=ss && r>=se){ return st[si];}
  if(ss>r || se<l){return 0;}
  int m=getmid(ss,se);
  return gsumUtil(st,ss,m,l,r,2*si+1)+gsumUtil(st,m+1,se,l,r,2*si+2);
}

int gsum(int* st,int n,int l,int r){
  if(l<0||l>r||r>n-1){
    return -1;
  }
  return gsumUtil(st,0,n-1,l,r,0);
}

int main()
{
    fastio
    string s;
    cin>>s;
    int n=s.size();

    int arr[n];
    arr[n-1]=0;
    for(int i=0;i<n-1;i++){
      if(s[i]==s[i+1]){arr[i]=1;}
      else{arr[i]=0;}
    }

    int* st=STcon(arr,n);


    int m,l,r;
    cin>>m;
    while(m--){
      cin>>l>>r;
      cout<<gsum(st,n,l-1,r-2)<<endl;
    }


    return 0;
}
