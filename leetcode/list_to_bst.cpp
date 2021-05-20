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

//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
	vector<int> v;
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
        //TreeNode *gg = new TreeNode();
        return NULL;}
        while(head!=NULL){
        	v.push_back(head->val);
        	head=head->next;
        }
        int mid = v.size()/2;
        TreeNode *gg = new TreeNode(v[mid]);
        gg->val = v[mid];
        gg->left = getdata(0,mid-1);
        gg->right = getdata(mid+1,v.size()-1);
        return gg;
        
    }

    TreeNode* getdata(int st,int ed){
    	if(st>ed){return NULL;}
    	int mid =st +  (ed-st)/2;
        
    	TreeNode *gg = new TreeNode(v[mid]);
        gg->val = v[mid];
        gg->left = getdata(st,mid-1);
        gg->right = getdata(mid+1,ed);
        return gg;
        
    }

};

int main(){


	return 0;
}