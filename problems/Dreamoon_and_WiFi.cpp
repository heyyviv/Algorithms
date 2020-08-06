\*
https://codeforces.com/contest/476/problem/B?f0a28=1
The order of moves won't change the final position, so we can move all '?'s to the end of the string.
We have the following information:
1. the correct final position
2. the position that Dreamoon will be before all '?'s
3. the number of '?'s
We can infer that the distance and direction dreamoon still needs to move in the '?' part from 1. and 2., and furthur translate that to how many +1s and -1s dreamoon will need to move.
What's left is a combinatorial problem, the probability would be .
So we can compute that formula within O(n) time assuming n is the length of commands, but since N is small so we can brute force every possible choice of '?' with some recursive or dfs like search in O(2 n) time complexity.
Note that the problem asks for a precision of 10 - 9, so one should output to 11 decimal places or more.
time complexity: O(n), assuming n is the length of commands.

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
string a,b;
cin>>a>>b;
int l=a.length();
int c1=0,c2=0,cq=0;
for(int i=0;i<l;i++){
	c1+=a[i]=='+'?1:-1;
}
for(int i=0;i<b.length();i++){
	if(b[i]=='?'){cq++;}
	else{
		c2+=b[i]=='+'?1:-1;
	}
}
int dist=c1-c2;
double ans;
if((cq+dist)%2!=0||cq<abs(dist)){
	ans=0.00;
}else{
	int m=(abs(dist)+cq)/2;
	int c=1;
	for(int i=0;i<m;i++){
		c*=(cq-i);
	}
	for(int i=2;i<=m;i++){
		c/=i;
	}
	ans=(double)c/(1<<cq);
}
printf("%.12f\n",ans);

return 0;
}
