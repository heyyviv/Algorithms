'''
question on https://www.spoj.com/problems/DIVSUM/
solution explanation on https://www.math.upenn.edu/~deturck/m170/wk3/lecture/sumdiv.html  based on number theory
'''


#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<algorithm>
#define INF (unsigned)!((int)0)
using namespace std;


int main()
{
int t;
cin>>t;
while(t>0){
   long long int n;
   cin>>n;
   long long int k=n;
   long long int sum=1;
   for(long long int  i=2;i<=sqrt(n);i++){
   		long long int term=1;
   		long long int mterm=1;
   		while(n%i==0){
   			n=n/i;

   			term=term*i;
   			mterm=mterm+term;
   		}
   		sum=sum*mterm;
   }
   if(n>=2){
   	sum=sum*(1+n);
   	cout<<n<<"n"<<endl;
   }
   cout<<sum-k<<endl;

t--;
}
return 0;

}
