#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>nums,int l,int r){

        int n=nums.size();
        int prev=-1;
        for(int i=0;i<n;i++){

            if((l<=i) && (i<=r)) continue;
            if(prev>=nums[i]) return false;
            prev=nums[i];
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                if(helper(nums,i,j)) ans++;

            }
        }
    return ans;
    }
};
