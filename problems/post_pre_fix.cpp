#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
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
#define INF 10000999
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
#define PI 3.1415926535
using namespace std;

bool isoperator(char c){
  return (!isalpha(c) && !isdigit(c));
}

int priority(char c){
  if(c=='+' || c=='-'){
    return 1;
  }else if(c=='*' || c=='/'){
    return 2;
  }else if(c=='^'){
    return 3;
  }
  return 0;

}

string infix_to_postfix(string s){
  s='('+s+')';
  int l=s.size();
  stack<char> char_stack;
  string output="";
  for(int i=0;i<l;i++){
    if(isalpha(s[i])||isdigit(s[i])){
      output+=s[i];
    }else if(s[i]=='('){
      char_stack.push(s[i]);
    }else if(s[i]==')'){
      while(char_stack.top()!='('){
        output+=char_stack.top();
        char_stack.pop();
      }
      char_stack.pop();
    }else{
      if(isoperator(s[i])){
        while(priority(char_stack.top())>=priority(s[i])){
          output+=char_stack.top();
          char_stack.pop();
        }
        char_stack.push(s[i]);
      }
    }
  }
  return output;
}

string infix_to_prefix(string s){
  int l=s.length();
  reverse(s.begin(),s.end());
  for(int i=0;i<l;i++){
    if(s[i]=='('){
      s[i]==')';
    }else if(s[i]==')'){
      s[i]='(';
    }
  }
  string prefix=infix_to_postfix(s);
  reverse(s.begin(),s.end());
  return s;
}

int main() {
  fastio




  }
  return 0;

}
