#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        //2 1 4 7 3 2 5 
        int n=arr.size();
        int ans=0;
        int i=1;
        int upper,lower;

        while(i<n){
            upper=0;
            lower=0;

            while(i<n && arr[i-1]==arr[i]) i++;
            while(i<n && arr[i-1]<arr[i]){
                upper++; 
                i++;
            }

            while(i<n && arr[i-1]>arr[i]){
                lower++;
                i++;
            }

            if(upper && lower){
                ans=max(ans,lower+upper+1);
            }
        }
    return ans;
    }
};