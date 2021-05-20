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

int n=100000;
vector<bool> isprime(n,true);
vector<int> factor(n,0);

void is_prime(){
	//Sieve of Eratosthenes
	isprime[0]=false;
	isprime[1]=false;
	factor[1]=1;
	for(int i=2;i<n;i++){
		if(isprime[i]){
			factor[i]=i;
			if(i*1ll*i < n){
				for(int j = i*i;j<n;j+=i){
					isprime[j]=false;
					factor[j]=i;
				}
			}
		}
	}
}


vector<int> find_factor(int k){
	std::vector<int> v;
	while(k>1){
		v.push_back(factor[k]);
		k=k/factor[k];
	}
	return v;
}

ll modExpo(int x,int y,int m){
	ll res=1;
	if(y == 0){return 1;}
	x = x%m;
	while(y>0){
		if(y%2==0){
			x=(x*x)%m;
			y=y/2;
		}else{
			res=(res*x)%m;
			x=(x*x)%m;
			y=y/2;
		}
	}
	return res;
}

int main()
{
	fastio
	isprime();
	
	return 0;
}
