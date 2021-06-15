
//https://leetcode.com/problems/trapping-rain-water/submissions/

//https://www.youtube.com/watch?v=fTD6Se3ZtEo


class Solution {
public:
    int trap(vector<int>& h) {
        if(h.size() == 0){return 0;}
        int water=0;
        int l=h.size();
        int left[l],right[l];
        left[0]=h[0];
        right[l-1]=h[l-1];
        for(int i=1;i<l;i++){
            left[i]=max(left[i-1],h[i]);
        }
        for(int i=l-2;i>=0;i--){
            right[i]=max(right[i+1],h[i]);
        }
        for(int i=0;i<l;i++){
            water+=min(right[i],left[i])-h[i];
        }
        return water;
    }
};