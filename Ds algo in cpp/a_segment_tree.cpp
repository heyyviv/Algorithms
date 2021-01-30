//https://www.spoj.com/problems/RMQSQ/
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

int arr[100001],ST[400004];

void buildST(int si,int ss,int se){
  if(ss==se){
    ST[si]=arr[ss];
    return ;
    }
    int mid=(ss+se)/2;
    buildST(2*si,ss,mid);
    buildST(2*si+1,mid+1,se);
    ST[si]=min(ST[si*2],ST[2*si+1]);
}

int query(int si,int qs,int qe,int ss,int se){
    if(ss>=qs && se<=qe){return ST[si];}
    if(qe<ss|| qs>se){return INT_MAX;}

    int mid=(ss+se)/2;
    int l=query(2*si,qs,qe,ss,mid);
    int r=query(2*si+1,qs,qe,mid+1,se);
    return min(l,r);
}

int main()
{
    fastio
    int q,n,l,r;
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>arr[i];
    }
    buildST(1,1,n);
    cin>>q;

    for(int i=0;i<q;i++){
      cin>>l>>r;
      cout<<query(1,l+1,r+1,1,n)<<endl;;
    }




    return 0;
}
