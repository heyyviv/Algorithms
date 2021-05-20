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


int gcd(int a,int b){
	int t;
	while(b!=0){
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int lcm(int a,int b){
	return (a*b)/gcd(a,b);
}

int main(){

	return 0;
}