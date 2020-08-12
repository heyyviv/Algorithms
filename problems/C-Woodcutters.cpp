//https://codeforces.com/contest/545/problem/C

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#define mod 100000009
#define INF INT_MAX
#define PI 3.14159265358979323846
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define pp pair<int,int>
using namespace std;

int main(){
//fastio

int n;
cin>>n;
ll xc[n],hc[n];
for(int i=0;i<n;i++){cin>>xc[i]>>hc[i];}
int tree=0;
ll px=0;
ll left;
ll right;
tree=min(2,n);
for(int i=1;i<n-1;i++){
	left=xc[i]-xc[i-1];

	right=xc[i+1]-xc[i];

	if(left-px>hc[i]){
		px=0;
		tree++;//cout<<i<<endl;
		//xc[i]=xc[i]-1;
		continue;
	}

	if(right>hc[i]){
		px=hc[i];
		tree++;//cout<<i<<endl;

		continue;
	}
	px=0;
}
cout<<tree<<endl;

return 0;
}
