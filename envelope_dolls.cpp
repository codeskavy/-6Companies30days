#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    static bool comp(vector<int>a,vector<int>b){

        if(a[0]==b[0]){
            return a[1]>b[1];
        }

        else{

            return a[0]<b[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);

        vector<int>temp;

        temp.push_back(arr[0][1]);

        for(int i=1;i<arr.size();i++){

            if(temp.back()<arr[i][1]){
                temp.push_back(arr[i][1]);
            }

            else{
                auto ind=lower_bound(temp.begin(),temp.end(),arr[i][1])-temp.begin();
                temp[ind]=arr[i][1];
            }
        }
    return temp.size();
    }
};