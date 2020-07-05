// question at https://www.codechef.com/LRNDSA05/problems/KPRIME
//
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#define INF 0x3f3f
#define ll long long int
#define endl "\n"
using namespace std;
const int n=1e5 +5;
 int A[n];
int prefix[n][6];
int prime[n];
vector<pair<int,int> > v[n];

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    cout.tie(NULL);
	
	for(int i=2;i<n;i++){
		if(prime[i]!=0) continue;
		prime[i]=i;
		for(int j=2*i;j<n;j=j+i){
		prime[j]=i;
		}
	}
	for(int i=2;i<n;i++){
		int x=i;
		map<int,int> M;
		while(x!=1){
			M[prime[x]]++;
			x=x/prime[x];
		}
		for(auto pp: M ){
			v[i].push_back(pp);
		}
	}
	
	for(int i=1;i<n;i++){
		A[i]=v[i].size();}
	
	for(int i=1;i<n;i++){
		for(int k=0;k<6;k++){
			prefix[i][k]=prefix[i-1][k]+(A[i]==k);
		}
	}
	int t;
	cin>>t;
	while(t--){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<prefix[r][k]-prefix[l-1][k]<<endl;
	}
	

return 0;
 
}

