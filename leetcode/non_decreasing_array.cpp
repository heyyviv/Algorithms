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

//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3731/

	class Solution {
	public:
	    bool checkPossibility(vector<int>& nums) {
	        std::vector<int> v;
	        for (int i = 0; i < nums.size()-1; i++)
	        {
	        	/* code */
	        	if(nums[i]>nums[i+1]){
	        		v.push_back(i);
	        	}
	        }
	        if(v.size()>1){return false;}
	        if(v.size() == 0){return true;}
	        int k=v[0];
	        if(k>0){
	        	if(nums[k+1]-nums[k-1] >= 1){return true;}
	      		return false;
	        }
	        return true;
	    }
	};

int main(){
	return 0;
}