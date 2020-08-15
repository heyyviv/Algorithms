//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
//439 - Knight Moves

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
#define INF 10000000
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
#define PI 3.1415926535
using namespace std;
int board[10][10];
int n=8;
void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j]=INF;
		}
	}
}
void DFS(int u1,int u2,int move){
	if(u1<0 || u1>=n ||u2<0 ||u2>=n){return ;}
	if(move>=board[u1][u2]){return ;}
	board[u1][u2]=move;
	DFS(u1-2,u2-1,move+1);  DFS(u1-2,u2+1,move+1);
	DFS(u1-1,u2+2,move+1);   DFS(u1+1,u2+2,move+1);
	DFS(u1+2,u2-1,move+1);  DFS(u1+2,u2+1,move+1);
	DFS(u1+1,u2-2,move+1);  DFS(u1-1,u2-2,move+1);
}


int main()
{
fastio
string s1,s2;
while(cin>>s1>>s2){
	int u1=s1[0]-'a';
	int u2=s1[1]-'1';
	int v1=s2[0]-'a';
	int v2=s2[1]-'1';
	init();
	DFS(u1,u2,0);
	//printf("To get from %s to %s takes %d knight moves \n",s1,s2,board[v1][v2]);
	cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<board[v1][v2]<<" knight moves."<<endl;
}



return 0;
}
