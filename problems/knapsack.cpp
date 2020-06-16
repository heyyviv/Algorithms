'''question at https://www.spoj.com/problems/PARTY/
'''

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct pass{
    int fun;
    int money;
};
typedef struct pass timepass;

int max(int a,int b){
    return (a>b)?a:b;
};

timepass knapsack(int b,int n,int fun[],int fee[]){
    timepass ss;
int dp[n+1][b+1];
for(int i=0;i<n+1;i++){
    for(int j=0;j<b+1;j++){
        if(i==0||j==0){
            dp[i][j]=0;
        }else if(fee[i-1]<=j){
            dp[i][j]=max(fun[i-1]+dp[i-1][j-fee[i-1]],dp[i-1][j]);
         }else{
            dp[i][j]=dp[i-1][j];
         }
    }
}
int minmoney=0;
int maxfun=dp[n][b];

    for(int i=0;i<=b;i++){
        if(dp[n][i]==maxfun){
            minmoney=i;
            break;
        }
    }
    
    ss.fun=maxfun;
    ss.money=minmoney;
    return ss;
}

int main()
{
while(true){
    int b,n;
    cin>>b>>n;
    if(b==0 &&n==0) break;

    int fun[n];
    int fee[n];
    for(int i=0;i<n;i++){
        cin>>fee[i]>>fun[i];
    }
    timepass sss=knapsack(b,n,fun,fee);
    cout<<sss.money<<" "<<sss.fun<<endl;

}    
return 0;

}
