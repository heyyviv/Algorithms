//http://codeforces.com/contest/405/problem/A     question

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#define mod 100000009
#define INF 0x3f3f
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;



int main()
{


  int n;
  cin>>n;
  int arr[n];
  int min=100;
  int max=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]>max){max=arr[i];}
    if(arr[i]<min){min=arr[i];}
  }
  int range=max-min+1;
  vector<int> counting(range);
  vector<int> output(n);
  for(int i=0;i<n;i++){
    counting[arr[i]-min]++;
    //cout<<"counting"<<endl;
  }
  for(int i=1;i<counting.size();i++){
    counting[i]+=counting[i-1];
    //cout<<"counting loop2 "<<counting[i]<<endl;
  }
  for(int i=n-1;i>=0;i--){

    output[counting[arr[i]-min]-1]=arr[i];
    counting[arr[i]-min]--;
    //cout<<"counting loop2 "<<output[counting[arr[i]-max]-1]<<endl;
  }
  for(int i=0;i<n;i++){
    //cout<<"counting loop4"<<endl;
    cout<<output[i]<<" ";
  }


return 0;
}
