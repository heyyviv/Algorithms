// codeforces C. Registration System


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
    int n;
    cin>>n;
    map<string,int> reg;
    string name;
    while(n--){
      cin>>name;
      if(reg.find(name) != reg.end()){
        cout<<name<<reg[name]<<endl;
        reg[name]++;
      }else{
        cout<<"OK"<<endl;
        reg[name]++;
      }
    }

    return 0;
}
