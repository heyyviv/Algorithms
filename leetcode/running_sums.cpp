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

//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3730/


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
    	int l=nums.size();
        vector<int> k(l,0);
        k[0]=nums[0];
        for(int i=1;i<l;i++){
        	k[i]=k[i-1] + nums[i];
        }
        return k;
    }
};

int main(){
	return 0;
}