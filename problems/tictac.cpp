//https://www.spoj.com/problems/TOE1/
//TOE1 - Tic-Tac-Toe ( I )
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
#define INF 100000000000
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
#define PI 3.1415926535
using namespace std;


bool is_win(string x){
	bool a1=(x[0]!='.' && x[0]==x[3]&&x[3]==x[6])||(x[1]!='.' && x[1]==x[4]&&x[4]==x[7])||(x[2]!='.' && x[2]==x[5]&&x[5]==x[8]);
	bool a2=(x[0]!='.'&& x[0]==x[4]&&x[4]==x[8])||(x[2]!='.'&& x[2]==x[4]&&x[4]==x[6]);
	bool a3=(x[0]!='.' && x[0]==x[1]&&x[1]==x[2])||(x[3]!='.'&&x[3]==x[4]&&x[4]==x[5])||(x[6]!='.'&&x[6]==x[7]&&x[7]==x[8]);
	return a1||a2||a3;
}


int main()
{
fastio
int t;
cin>>t;
while(t--){
	string last,a;
	for(int i=0;i<3;i++){
		cin>>a;
		last+=a;
	}
	string start=".........";
	queue<pair<string,bool> > qu;
	qu.push({start,1});
	string ans="no";
	while(qu.size()!=0){
		string cur=qu.front().first;
		bool curm=qu.front().second;
		qu.pop();
		if(cur==last){ans="yes";break;}
		if(is_win(cur)){continue;}
		for(int i=0;i<9;i++){
			if(cur[i]=='.'){
				cur[i]=curm?'X':'O';
				if(cur[i]==last[i]){
					qu.push({cur,1^curm});
				}
				cur[i]='.';
			}
		}
	}
	cout<<ans<<endl;
}


return 0;
}
