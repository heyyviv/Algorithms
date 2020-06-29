#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<cmath>
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);

ll fib(ll n) 
{ 
    ll F[2][2] = {{1, 1}, {1, 0}}; 
    if (n == 0) 
        return 0; 
    power(F, n - 1); 
  
    return F[0][0]; 
} 
  

void power(ll F[2][2], ll n) 
{ 
    if(n == 0 || n == 1) 
       return; 
    ll M[2][2] = {{1, 1}, {1, 0}}; 
      
    power(F, n / 2); 
    multiply(F, F); 
      
    if (n % 2 != 0) 
        multiply(F, M); 
} 
  
void multiply(ll F[2][2], ll M[2][2]) 
{ 
    ll x = (F[0][0] * M[0][0])%mod + (F[0][1] * M[1][0])%mod; 
    ll y = (F[0][0] * M[0][1])%mod + (F[0][1] * M[1][1])%mod;
    ll z = (F[1][0] * M[0][0] )%mod+ (F[1][1] * M[1][0])%mod; 
    ll w = (F[1][0] * M[0][1] )%mod+ (F[1][1] * M[1][1])%mod; 
      
    F[0][0] = x%mod; 
    F[0][1] = y%mod; 
    F[1][0] = z%mod; 
    F[1][1] = w%mod; 
} 


int main()
{
	fastio
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll food=fib(n);
		//complexity log n
		//to find sum of nth fib nunber we have to find fib(n+2)-1;
		

		cout<<food<<endl;

		
	}

return 0;
 
}