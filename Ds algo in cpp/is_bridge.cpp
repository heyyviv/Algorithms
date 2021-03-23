#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
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

bool visited[100000];
int tin[100000],low[100000];
vector<vector<int> > adj(100000);
int counter=0;

void dfs(int c,int p = -1){
  visted[c]=true;
  timer++;
  tin[c]=low[c]=timer;
  for(int child : adj[c]){
    if(child == p){continue;}
    else if(visited[child]){
      low[c] = min(low[c],tin[child]);
    }else{
      dfs(child,c);
      low[c] = min(low[c],low[child]);
      if(low[c] < tin[child]){
        cout<<c<<" "<<child<<" is a bridge"<<endl;
      }
    }
  }
}

void bridge(int n){
  memset(visited,false,100000);
  memset(tin,-1,100000);
  memset(low,-1,100000);
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      dfs(i);
    }
  }
}

int main(){
  fastio

}
