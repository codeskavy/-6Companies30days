#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n=img.size();
        int m=img[0].size();
    

        vector<vector<int>>res(n,vector<int>(m,0));
        vector<int>directions={-1,0,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int count=0;
                int sum=0;

               for(int xi:directions){
                    for(int yi:directions){

                    int x=i+xi;
                    int y=j+yi;

                    if(x>=0 && x<n && y>=0 && y<m){
                        sum+=img[x][y];
                        ++count;
                    }
                }
               }
               res[i][j]=floor(sum/count); 

            }
        }

        return res;





    }
};