#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        string temp="";
        unordered_map<char,int>mpp;
        int x=0,y=0;
        vector<int>arr(10);
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) x++;
            else{
                mpp[secret[i]]++;
            }
        }

        for(int i=0;i<secret.size();i++){

            if(secret[i]!=guess[i]){
                if(mpp[guess[i]]>0){
                    y++;
                    mpp[guess[i]]--;
                }
            }
        }

        temp=to_string(x)+'A'+to_string(y)+'B';

        return temp;
    }
};