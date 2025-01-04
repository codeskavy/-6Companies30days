#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPal(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void recurse(string s,string s1,string s2,int ind,int& maxi,int n){
       if(ind==n){
        if(isPal(s1) && isPal(s2)){
            maxi=max(maxi,(int)(s1.size()*s2.size()));
        }
        return;
       }
       recurse(s,s1,s2,ind+1,maxi,n);

       s1.push_back(s[ind]);
       recurse(s,s1,s2,ind+1,maxi,n);
       s1.pop_back();  

       s2.push_back(s[ind]);
       recurse(s,s1,s2,ind+1,maxi,n);
       s2.pop_back();
    }
    int maxProduct(string s) {
        string s1="",s2="";
        int maxi=0,n=s.size();
        recurse(s,s1,s2,0,maxi,n);    
        return maxi;
    }
};