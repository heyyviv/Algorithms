/*
We have seen how dynamic arrays enable arrays to grow while still achievingconstant-time amortized performance. This problem concerns extending dynamicarrays to let them
 both grow and shrink on demand.(a)  Consider an underflow strategy that cuts the array size in half whenever thearray falls below half full. Give an example sequence of insertions
  and deletionswhere this strategy gives a bad amortized cost.(b)  Then, give a better underflow strategy than that suggested above, one thatachieves constant amortized cost
  per deletion

*/

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
#define INF 10000999
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
#define PI 3.1415926535
using namespace std;

class Dynarray{
private:
	int size=1;
	int *array;
	int current=0;
public:
	Dynarray(){
		array=(int*)malloc(size*sizeof(int));
	}
	void insert(int data){
		array[current]=data;
		current++;
		if((size-current)<3){
			size=2*size;
			int *temp=(int*)malloc(size*sizeof(int));
			for(int i=0;i<current;i++){
				temp[i]=array[i];
			}
			free(array);
			array=temp;
		}

	}
	int at(int id){
		if(id<current){
			return array[id];
		}
		return 69;
	}
	int length(){
		return size;
	}
	void remove(int id){
		for(int i=id;i<size-1;i++){
			array[i]=array[i+1];
		}
		current--;
		if(current<=(size/4)){
			size=size/2;
			int* temp=(int*)malloc(size*sizeof(int));
			for(int i=0;i<current;i++){
				temp[i]=array[i];
			}
			array=temp;
		}
	}
};

int main(){
int n;
cout<<"size of array"<<endl;
cin>>n;
Dynarray numbers=Dynarray();
int temp;
for(int i=0;i<n;i++){
	cin>>temp;
	numbers.insert(temp);
	cout<<"size of current array "<<numbers.length()<<endl;
}
cout<<"enter 3 queries "<<endl;
for(int i=0;i<3;i++){
	cin>>temp;
	cout<<"element is "<<numbers.at(temp)<<endl;
}
cout<<"delete 5 element"<<endl;
for(int i=0;i<5;i++){
	cin>>temp;
	numbers.remove(temp);
	cout<<"size of current array "<<numbers.length()<<endl;
}
return 0;
}
