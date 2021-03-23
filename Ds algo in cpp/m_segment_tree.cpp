//https://www.spoj.com/problems/KQUERY/
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

int arr[30001];
vector<int> ST[4*30001];

void buildST(int si,int ss,int se){
  if(ss==se){
    ST[si].push_back(arr[ss]);
    return ;
  }
  int mid=(ss+se)/2;
  buildST(2*si,ss,mid);
  buildST(2*si+1,mid+1,se);
  int l=0,r=0;
  while(l<ST[2*si].size() && r<ST[2*si+1].size()){
    if(ST[2*si][l]<ST[2*si+1][r]){ST[si].push_back(ST[2*si][l]);l++;}
    else{ST[si].push_back(ST[2*si+1][r]);r++;}
  }
  while(l<ST[2*si].size()){ST[si].push_back(ST[2*si][l]);l++;}
  while(r<ST[2*si+1].size()){ST[si].push_back(ST[2*si+1][r]);r++;}
  return ;
}

int query(int si,int ss,int se,int qs,int qe,int num){
  if(qs>se || qe<ss){return 0;}
  if(ss>=qs && se<=qe){
    return ST[si].end() - upper_bound(ST[si].begin(),ST[si].end(),num);
  }
  int mid=(ss+se)/2;
  int l=query(2*si,ss,mid,qs,qe,num);
  int r=query(2*si+1,mid+1,se,qs,qe,num);
  return l+r;
}

int main()
{
    fastio
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>arr[i];
    }
    buildST(1,1,n);
    int q;
    cin>>q;
    int i,j,k;
    while(q--){
      cin>>i>>j>>k;
      cout<<query(1,1,n,i,j,k)<<endl;

    }




    return 0;
}
