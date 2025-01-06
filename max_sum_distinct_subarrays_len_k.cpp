#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>mpp;
        long long sum=0;
        long long maxi=0;

        for(int i=0;i<n;i++){

            mpp[nums[i]]++;
            sum+=nums[i];

            if(i>=k){
                int last=nums[i-k];
                mpp[last]--;
                sum-=last;

                 if (mpp[last] == 0) {
                    mpp.erase(last);
                }

            }
            if(i>=k-1 && mpp.size()==k){
            maxi=max(maxi,sum);
        }
        }
        
    return maxi;

    }
};