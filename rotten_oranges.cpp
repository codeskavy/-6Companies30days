#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int time=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;//0
            int c=q.front().first.second;//0
            int t=q.front().second;//0
            time=max(t,time);//0
            q.pop();//{}

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];//-1
                int ncol=c+dcol[i];//0
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return time;
    }
};