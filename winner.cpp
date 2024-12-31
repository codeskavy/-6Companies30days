#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class CircularList{

    vector<int>items;

    public:

    CircularList(vector<int>data):items(data){}

    int size() const {
        return items.size();
    }

    int get(int index){
        return items[index%items.size()];
    }
    void erase(int index) {
        items.erase(items.begin() + (index % items.size()));
    }

    int getLast() const {
        return items.front(); 
    }

};
class Solution {
public:
    int findTheWinner(int n, int k) {

        vector<int>arr;

        for(int i=1;i<=n;i++) arr.push_back(i);
        
        CircularList cl(arr);

        int start=0;

        while(cl.size()>1){
            start = (start + k - 1) % cl.size();
            cl.erase(start); 
        }
    
    return cl.getLast();
   
    }
};