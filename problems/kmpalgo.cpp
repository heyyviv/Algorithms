/* question at   https://www.spoj.com/problems/NHAY/
  pattern searching algorithm
*/

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#define INF (unsigned)!((int)0)
using namespace std;

void lpc(string pat,int p,int* lp){
    int l=0;
    int i=1;
    lp[0]=0;
    while(i<p){
        if(pat[l]==pat[i]){
            l++;
            lp[i]=l;
            i++;
        }else{
            if(l!=0){
                l=lp[l-1];
            }else{
                lp[i]=0;
                i++;
            }
        }
    }
}

void kmp(string pat,string txt){
    int p=pat.length();
    int t=txt.length();
    int occ=0;
    int lp[p];
    lpc(pat,p,lp);
    
    int i=0,j=0;
    while(i<t){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        if(j==p){
            cout<<i-j<<endl;
            j=lp[j-1];
            occ=1;
        }else if(i<t && txt[i]!=pat[j]){
            if(j!=0){
            j=lp[j-1];
        }else{
            i=i+1;
        }
        }

    }
    if(occ==0){
        cout<<endl;
    }
}

int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    int n;
    while(cin>>n){
        string pat,txt;
        cin>>pat>>txt;
       //cout<<n<<txt<<pat;
        kmp(pat,txt);


    }

    

return 0;

}
