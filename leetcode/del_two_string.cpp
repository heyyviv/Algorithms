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

//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3734/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1=word1.length();
        int w2 = word2.length();
        return w1+w2-2*lcs(word1,word2,w1,w2);
    }

    int lcs(string word1,string word2,int w1,int w2){
    	if(w1 ==0 || w2==0){return 0;}
    	int arr[w1+1][w2+1];
    	for(int i=0;i<=w1;i++){
    		for(int j=0;j<=w2;j++){
                if(i==0||j==0){arr[i][j]=0;
                }else if(word1[i-1]==word2[j-1]){
    				arr[i][j] = 1+arr[i-1][j-1];
    			}else{
    				arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
    			}
    		}
    	}
    	return arr[w1][w2];
    }
};

int main(){
	return 0;
}