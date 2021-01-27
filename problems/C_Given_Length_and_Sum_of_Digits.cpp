//https://codeforces.com/problemset/problem/489/C


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

bool can(int l,int s){
  return l>0 && s<=9*l ;
}

int main()
{
    fastio
    int m,s;
    cin>>m>>s;
    string a,b;
    if(s==0){
      cout<<( m==1?"0 0":"-1 -1")<<endl;
      return 0;
    }

    for(int i=0;i<m;i++){
      int t=min(s,9);
      b+=t+'0';
      s-=t;
    }
    if(s>0){cout<<"-1 -1"<<endl; return 0;}
    for(int i=m-1;i>=0;i--){
      a+=b[i];
    }
    int i=0;
    for(i=0;a[i]=='0';i++);
    a[i]--;a[0]++;
    cout<<a<<" "<<b<<endl;


    return 0;
}
