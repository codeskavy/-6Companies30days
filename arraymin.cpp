#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n=nums.size();
        int sum=0;

        sort(nums.begin(),nums.end());
        
        int k=nums[n/2];
        
        int moves=0;

        for(int i=0;i<n;i++){
            
            moves+=abs(k-nums[i]);
            

        }
    return moves;
    }
};