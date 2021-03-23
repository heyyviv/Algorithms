//https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/?layout=old

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

vector<vector<int> > arr(100005);
vector<int> vis(100005,0);

void dfs(int i){
	vis[i]=1;
	for(int v : arr[i]){
		if(vis[v]==0){dfs(v);}
	}
}

int main()
{


	fastio
	int n,e;
	cin>>n>>e;
	int u,v;
	for(int i=0;i<e;i++){
		cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	int c=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
			c++;
		}
	}

	cout<<c<<endl;


	return 0;
}
