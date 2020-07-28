//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=305

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#define mod 100000009
#define INF 100000000000
#define PI 3.14159265358979323846
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;

ll fact(int n,int m){
	if(m==0){
		return 1;
	}
	if(m>n/2){return fact(n,n-m);}
	ll res=1;
	for(int i=1;i<=m;i++){
		res=res*(n-i+1);
		res=res/i;
	}
	return res;
}

int main(){
	fastio
int n,m;
while(1){
	cin>>n>>m;
	if(n==0 && m==0){break;}
	ll kk=fact(n,m);
	cout<<n<<" things taken "<<m<<" at a time is "<<kk<<" exactly."<<endl;
}
	return 0;
}
