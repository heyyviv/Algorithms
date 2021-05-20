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
//https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/



class WordFilter {
public:
	map<string,int>  data;
    WordFilter(vector<string>& words) {
        for(int it=0;it<words.size();it++){
        	string word = words[it];
        	for(int i=0;i<word.size();i++){
        		for(int j=0;j<word.size();j++){
        			string ans = word.substr(0,i+1)+"#"+word.substr(j);
        			cout<<ans<<endl;
        			data[ans]=it;
        		}
        	}
        }
    }
    
    int f(string prefix, string suffix) {
    	string ans = prefix+"#"+suffix;
        return (data.find(ans) != data.end()) ? data[ans]:-1;
    }
};



int main(){
	fastio

	return 0;
}