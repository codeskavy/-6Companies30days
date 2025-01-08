#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int num) {
        
        string ans="";
        while(num--){

            ans=ans+(char)((num)%26+'A');
            num=(num)/26;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};