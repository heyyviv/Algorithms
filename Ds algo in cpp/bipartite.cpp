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
#define INF 0x3f3f
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
using namespace std;
const int v=4;

string bipartite(int G[][v],int src){
	int color[v];
	for(int i=0;i<v;i++){
		color[i]=-1;
	}

	stack<int> st;
	st.push(src);
	while(!st.empty()){
		int x=st.top();
		st.pop();
		if(G[x][x]==1){
			return "NO";
		}
		for(int i=0;i<v;i++){
			if(G[x][i]==1 and color[i]==-1){
				color[i]=1-color[x];
				st.push(i);
			}else if(G[x][v]==1 && color[x]==color[v]){
				return "NO";
			}

		}

	}
	return "YES";
}

int main()
{

	int G[][v] = {{0, 1, 0, 1},
	        {1, 0, 1, 0},
	        {0, 1, 0, 1},
	        {1, 0, 1, 0}
	    };

cout<<bipartite(G,0);
return 0;
}
