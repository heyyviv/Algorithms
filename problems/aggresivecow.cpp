/* question on https://www.spoj.com/problems/AGGRCOW/
this is a problem for discrete binary search
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;
int n,c;

bool place(int mid){
    int start=arr[0];
    int cow=1;
    for(int i=1;i<n;i++){
        if(arr[i]-start>=mid){
            cow++;
            start=arr[i];
        }
        if(cow==c){
            return 1;
        }
    }
    return 0;
}

int binary(int li,int hi){
    int mid;
    int ok;
    while(li<=hi){
        mid=li+(hi-li)/2;

        if(place(mid)){
            ok=mid;
            li=mid+1;
        }else{
        hi=mid-1;}
    }
    return ok;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        arr.clear();
        cin>>n>>c;
        for(int i=0;i<n;i++){
            int ar;
            cin>>ar;
            arr.push_back(ar);
        }
        sort(arr.begin(),arr.end());
        int lo=0;
        int hi=arr[n-1]-arr[0]+1;
        int temp=binary(lo,hi);
        cout<<temp<<endl;

        t--;
    }


return 0;
}
