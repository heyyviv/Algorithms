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

vector<vector<int> > adj;
vector<int> level,subtree;
int n;
void dfs(int cur=1,int par=0){
  subtree[cur]=1;
  level[cur]=level[par]+1;
  for(int neib : adj[cur]){
    if(neib == par){
      continue;
    }
    dfs(neib,cur);
    subtree[cur]+=subtree[neib];
  }
}

int main(){
  cin>>n;
  //n is nodes in tree so edges are n-1
  adj.resize(n+1);
  level.resize(n+1);
  subtree.resize(n+1);
  for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  level[0]=-1;
  dfs();
  cout<<"LEVEL OF NODE"<<endl;
  for(int i=1;i<=n;i++){
    cout<<i<<"\t"<<level[i]<<endl;
  }
  cout<<"SUBTREE SIZE"<<endl;
  for(int i=1;i<=n;i++){
    cout<<i<<"\t"<<subtree[i]<<endl;
  }


  return 0;
}
