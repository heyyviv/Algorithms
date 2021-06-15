#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
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

//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3736/


#define ll unsigned long long 

class Solution {
public:
	vector<ll> v = {1,2,3,4,5,6,7,8,9};
    int superpalindromesInRange(string left, string right) {
        ll rig = stoll(right);
        ll lef = stoll(left);
        for(int i=1;i<=10000;i++){
        	string l=to_string(i);
        	string r=l;
        	reverse(r.begin(),r.end());
        	v.push_back(stoll(l+r));
        	for(int d=0;d<10;d++){
        		v.push_back(stoll(l+to_string(d)+r));
        	}
        }
        int ans=0;
        for(ll t : v){
        	ll t1=t*t;
        	if(t1>rig){continue;}
        	if(t1>=lef){
        		if(is_p(t1)){
        			ans++;
        		}
        	}

        }

        return ans;
    }
    bool is_p(ll k){
    	string gg = to_string(k);
    	string gg1=gg;
    	reverse(gg1.begin(),gg1.end());
    	return gg == gg1;
    }
};

int main(){
	return 0;
}