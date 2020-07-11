//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1047
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
#define INF 0x3f3f
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
using namespace std;

int main()
{
    long int i,j,k,lena,lenb,result[1000],carry,l,temp;
    char a[270],b[270];
    while(scanf("%s%s",&a,&b)==2)
    {
        lena=strlen(a);
        lenb=strlen(b);
        memset(result,0,sizeof(result));
        k=0;
        for(i=lenb-1;i>=0;i--)
        {
            k+=1;
            l=k-1;
            carry=0;
            for(j=lena-1;j>=0;j--)
            {
                l+=1;
                temp=(b[i]-48)*(a[j]-48)+carry+result[l];
                result[l]=temp%10;
                carry=temp/10;
            }
            if(carry>0)
            {
                l+=1;
                result[l]=carry;
            }
 
        }
        if(strcmp(a,"0")==0 ||strcmp(b,"0")==0 )
            printf("0");
        else
        {
            for(i=l;i>=1;i--)
                printf("%ld",result[i]);
        }
 
        printf("\n");
    }
    return 0;
}
