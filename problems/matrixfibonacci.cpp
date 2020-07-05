#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<array>
#define INF 0x3f3f
#define ll long long int
#define endl "\n"
using namespace std;

void multiply(ll F[2][2],ll M[2][2]){
	ll x = F[0][0] * M[0][0] + F[0][1] * M[1][0]; 
    ll y = F[0][0] * M[0][1] + F[0][1] * M[1][1]; 
    ll z = F[1][0] * M[0][0] + F[1][1] * M[1][0]; 
    ll w = F[1][0] * M[0][1] + F[1][1] * M[1][1]; 
      
    F[0][0] = x; 
    F[0][1] = y; 
    F[1][0] = z; 
    F[1][1] = w; 

}

void power(ll F[2][2],ll n){
if(n==0||n==1){
	return ;
}
ll M[2][2]={{1,1},{1,0}};
power(F,n/2);
multiply(F,F);
if(n%2!=0){
	multiply(F,M);
}

}

ll fib(ll n){
	if(n==0) return 0;

	ll F[2][2]={{1,1},{1,0}};
	power(F,n-1);
	//cout<<F[0][0]<<F[0][1]<<endl;
	//cout<<F[1][0]<<F[1][1]<<endl;
	
	return F[0][1];
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    cout.tie(NULL);
	
int t;
cin>>t;
while(t--){
	ll n;
	cin>>n;
	ll x=pow(2,floor(log2(n)));
	//cout<<x<<endl;
	cout<<fib(x)%10<<endl;


}
return 0;
 
}