/*
https://codeforces.com/contest/469/problem/B
*/

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
#define pp pair<int,int>
using namespace std;



int main(){
//	fastio
int p,q,l,r;
cin>>p>>q>>l>>r;
int temp[1004]={0};
int a[p],b[p];
for(int i=0;i<p;i++){
	cin>>a[i]>>b[i];
}
int ans=0;
int c,d;
for(int j=0;j<q;j++){
	cin>>c>>d;
	for(int i=0;i<p;i++){
		int y=b[i]-c;
		int x=a[i]-d;
		if(x>r||y<l){continue;}
		for(int k=max(l,x);k<=min(r,y);k++){
			if(!temp[k]){ans++;temp[k]=1;}
		}
	}
}
cout<<ans;
return 0;
}
