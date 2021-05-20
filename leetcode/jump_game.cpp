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

//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,cend=0,cfar=0;
        for(int i=0;i<nums.size()-1;i++){
        	cfar=max(cfar,i+nums[i]);
        	if(i==cend){
        		jump++;
        		cend=cfar;
        	}
        }
        return jump;
    }

    
};

int main(){
	return 0;
}