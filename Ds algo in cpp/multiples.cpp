//https://www.spoj.com/problems/EASYMATH/
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

int arr[4];
ll gcd(ll a,ll b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}

ll lcm(ll a,ll b){
	return (a*b) /gcd(a,b);
}

ll multiples( int id,int cnt,ll me,ll upto){
	if(id==5){
		if(cnt%2==1){
			return -me/upto;
		}
		else{
			return me/upto;
		}
	}
	ll ret=0;
	ret+=multiples(id+1,cnt+1,me,lcm(upto,arr[id]));
	ret+=multiples(id+1,cnt,me,upto);
	return ret;
}


int main()
{
	int t;
	cin>>t;
	while(t--){
		ll m,n,a,d;
		cin>>m>>n>>a>>d;
		arr[0]=a;
		arr[1]=a+d;
		arr[2]=a+2*d;
		arr[3]=a+3*d;
		arr[4]=a+4*d;
		cout<<multiples(0,0,n,1)-multiples(0,0,m-1,1)<<endl;
	}
    
}
