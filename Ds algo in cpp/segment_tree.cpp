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
#define INF 10000999
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
#define PI 3.1415926535
using namespace std;

int l_child(int x){return 2*x;}
int r_child(int x){return 2*x+1;}
int N;

void build(int* ST,int* A,int x=1,int l=1,int r=N+1){
  if(l==r-1){ST[x]==A[l]; return ;}
  int mid=(l+r)/2;
  build(l_child(x),l,mid);
  build(r_child(x),mid,r);
  ST[x]=combine(ST[l_child(x)],ST[r_child(x)]);

}
int combine(int a,int b){
  return a+b;
}

int query(int* ST,int L,int R,int x=1,int l=1,int r=N-1){
  if(l>=R||r<=L){return 0;}
  if(l>=L && r<=R){return ST[x];}
  int mid=(l+r)/2;
  return combine(query(ST,L,R,))
}

void point_update(int pos,int val,int x=1,int l=1,int r=N-1){
  if(pos<l || pos >=r){return ;}
  if(l == r-1){
    ST[x]=val;
    A[pos]=val;
    return ;
  }
  int mid=(l+r)/2;
  update(pos,val,lc,l,mid);
  update(pos,val,rc,mid,r);
  ST[x]=combine(ST[lc],ST[rc]);
}

int main(){
  cin>>N;
  int ST[4*N],A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  build(&ST,&A);

}
