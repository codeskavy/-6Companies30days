#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<int>&A,int k){
        int res=0,i=0,n=A.size();

        for(int j=0;j<n;j++){
            k-=A[j]%2;

            while(k<0){
                k+=A[i++]%2;

            }
            res+=j-i+1;
        }
    return res;
    }
    int numberOfSubarrays(vector<int>& A, int k) {
        return helper(A,k)- helper(A,k-1);
    }
};