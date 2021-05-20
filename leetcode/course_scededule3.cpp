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

//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3729/


bool sortc(vector<int>& v1,vector<int>& v2){
		return v1[1]<v2[1];
	}

class Solution {
public:

	
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),sortc);
        int time=0;
        priority_queue<int> heap;
        for(int i=0;i<courses.size();i++){
        	if(time+courses[i][0] <= courses[i][1]){
        		heap.push(courses[i][0]);
        		time += courses[i][0];
        	}else if( !heap.empty() && heap.top() > courses[i][0]){
        		
        		time += courses[i][0] -heap.top();
        		heap.pop();
        		heap.push(courses[i][0]);
        	}
        }
        return heap.size();
    }
};

int main(){
	fasio

	return 0;
}