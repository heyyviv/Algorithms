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


//https://leetcode.com/explore/featured/card/june-leetcoding-challenge-2021/603/week-1-june-1st-june-7th/3764/

class Solution {
public:
	int arr[51][51];
	int r,c;
	int pos[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
	int cal(int i,int j,vector<vector<int>>& grid){
		arr[i][j]=1;
		int ans=1;
		for(int k=0;k<4;k++){
			int nr = i+pos[k][0];
			int nc = j+pos[k][1];
			if(((nr<r) && nr>=0) && ((nc<c) && nc>=0)){
				if(arr[nr][nc] == 0 && grid[nr][nc] == 1){ans +=cal(nr,nc,grid);}
				
			}
		}
		return ans;
	}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         r=grid.size();
         c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
        	for(int j=0;j<c;j++){
        		if(grid[i][j]==1 && arr[i][j] == 0){
        			ans = max(ans,cal(i,j,grid));
        		}
        	}
        }
        return ans;
    }

};