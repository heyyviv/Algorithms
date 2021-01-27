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
#include<bits/stdc++.h>
#include<array>
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define PI 3.1415926535
using namespace std;


int main()
{
    fastio
    int n,a,b,c;
    int rem,k;
    cin>>n>>a>>b>>c;
    int ans=0;
    for(int i=0;i*a<=n;i++){
      for(int j=0;i*a+j*b<=n;j++){
        rem=n-a*i-b*j;
        if(rem%c==0){
          k=rem/c;
          ans=max(ans,i+j+k);
        }
      }
    }
    cout<<ans<<endl;
    return 0;
}
