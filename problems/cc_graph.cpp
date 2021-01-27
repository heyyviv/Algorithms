/*
link - https://www.codechef.com/LRNDSA08/problems/RBTREE


To find the level of any node xx, find  Log_{2}x

hints https://discuss.codechef.com/t/official-contest-8-hints-dsa-learning-series/72900
​
 x⌋
​
 x⌋
*/


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
#define INF 10000999
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define PI 3.1415926535
using namespace std;





int main() {
  fastio
  int q;
  cin>>q;
  int temp=0;
  while(q--){
    string w;
    cin>>w;
    if(w=="Qi"){
      temp=temp^1;
    }else{
      int x,y;
      cin>>x>>y;
      int lx=log2(x);
      int ly=log2(y);
      int numr=0,numb=0;
      if(ly>lx){
        swap(ly,lx);
        swap(x,y);
      }
      while(lx!=ly){
        if(temp%2==lx%2){
          numb+=1;
        }else{
          numr+=1;
        }
        x=x/2;
        lx--;
      }
      int layer=lx;
      while(x!=y){
        if(temp%2==layer%2){
          numb+=2;
        }else{
          numr+=2;
        }
        x=x/2;
        y=y/2;
        layer--;
      }
      if(layer%2==temp%2){
        numb++;
      }else{
        numr++;
      }
      if(w[1]=='r')
        cout<<numr<<endl;
      else
        cout<<numb<<endl;
    }

  }


  return 0;

}
