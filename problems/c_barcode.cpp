//https://codeforces.com/contest/225/problem/C

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

int f[1005][2];// 0 black 1 white
int s[1005];
char c[1005];
int a[1005][1005];

int main(){
	memset(f,112233,sizeof(f));
	f[0][0]=0;f[0][1]=0;
int n,m,x,y;
cin>>n>>m>>x>>y;
char cc;
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		cin>>cc;
		a[i][j]=(cc=='#')?1:0;
	}
}
s[0]=0;
for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
		s[i]=s[i]+a[j][i];
	}
	s[i]+=s[i-1];
}

for(int i=x;i<=m;i++){
	for(int j=x;j<=y;j++){
		if(i-j>=0){
			f[i][0]=min(f[i][0],f[i-j][1]+(s[i]-s[i-j]));
			f[i][1]=min(f[i][1],f[i-j][0]+(n*j)-(s[i]-s[i-j]));
		}
	}
}
cout<<min(f[m][0],f[m][1])<<endl;



return 0;
}
