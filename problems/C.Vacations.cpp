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
int arr[102][3];// 0 rest 1 contest 2 gym

//https://codeforces.com/contest/699/problem/C url
int main(){
//fastio
for(int i=0;i<102;i++){
	arr[i][1]=0;arr[i][0]=0;arr[i][2]=0;
}
int n;
cin>>n;
int a;

for(int i=1;i<=n;i++){
	cin>>a;

	arr[i][0]=max(arr[i-1][0],max(arr[i-1][1],arr[i-1][2]));

 if(a==1||a==3){
	arr[i][1]=max(arr[i-1][0]+1,arr[i-1][2]+1);
	}
	if(a==2||a==3){
		arr[i][2]=max(arr[i-1][0]+1,arr[i-1][1]+1);
	}

}
int kk=max(arr[n][0],max(arr[n][1],arr[n][2]));
cout<<n-kk<<endl;
}
