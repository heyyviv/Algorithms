//https://www.codechef.com/JAN21A/problems/ANTSCHEF

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
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<vector<int> > v(n);
      map<int,int> grid;
      int p;
      for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
          cin>>p;
          v[i].push_back(p);
          grid[abs(p)]++;
        }
      }

      ll ans=0;
      for(auto i: grid){
        if(i.second>1){ans++;}
      }

      for(auto line : v){
        vector<int> pos,neg;
        for(auto ant: line){
          if(ant<0){neg.push_back(ant);}
          else{pos.push_back(ant);}
        }
        reverse(pos.begin(),pos.end());
        while(true){
          int closest;
          if(pos.empty() && neg.empty()){break;}
          else if(neg.empty()){
            closest=pos.back();
          }else if(pos.empty()){closest=neg.back();}
          else{
            closest=(abs(neg.back())<pos.back())?neg.back():pos.back();
          }
          if(closest<0){
            if(grid[abs(closest)]>1){
              ans+=neg.size()-1;
            }else{
              ans+=pos.size();
            }
          }else{
            if(grid[abs(closest)]>1){
              ans+=pos.size()-1;
            }else{
              ans+=neg.size();
            }
          }
          if(closest<0){neg.pop_back();}
          else{pos.pop_back();}
        }

      }

    cout<<ans<<endl;

    }


    return 0;
}
