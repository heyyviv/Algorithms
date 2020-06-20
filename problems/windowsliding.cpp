/*
question at https://www.spoj.com/problems/HOTELS/
maximum sum of element fo a array given a limit
linear complexity
*/

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#define INF (unsigned)!((int)0)
using namespace std;

long long int calculate(long long int arr[],long long int k,long long int n){
    long long int start=0,maxi=0,sum=0;
    for(long long int i=0;i<n;i++){
        sum=sum+arr[i];
        while(sum>k){
            sum=sum-arr[start];
            start++;
        }
        if(sum>maxi){
            maxi=sum;
        }
    }
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,k;
    cin>>n>>k;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<calculate(arr,k,n)<<endl;

return 0;

}
