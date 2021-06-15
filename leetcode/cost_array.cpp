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

//https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int cc[1004];
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1){return 0;}
        int c = ff(cost,0);
        int k = ff(cost,1);
        return min(c,k);
    }

    int ff(vector<int>& cost,int s){
    	if(s>=cost.size()){return 0;}
        if(cc[s]!=0){return cc[s];}
    	int c = cost[s]+min(ff(cost,s+1),ff(cost,s+2));
        cc[s]=c;
    	return c;
    }
};

int main(){

}