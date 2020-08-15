//https://acm.timus.ru/problem.aspx?space=1&num=1054

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
const int N=32;
int arr[N];
bool poss=false;

int tower(int n,int from,int to,int aux){
	if(n==0){
		return 0;
	}
	if(arr[n-1]==from){
		return tower(n-1,from,aux,to);
	}else if(arr[n-1]==to){
		return pow(2,n-1)+tower(n-1,aux,to,from);
	}
	return poss=true;
}


int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
	cin>>arr[i];
}
int move=tower(n,1,2,3);
cout<<(poss?-1:move)<<endl;
return 0;
}
