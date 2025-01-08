#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
    TreeNode* st = NULL;
    unordered_map<TreeNode*, TreeNode*> par;
    
    void markParentNodes(TreeNode* root, TreeNode* parent, int start) {
        if(!root) return; 

        par[root] = parent;  
        if(root -> val == start) st = root;     
        markParentNodes(root -> left, root, start);       
        markParentNodes(root -> right, root, start);     
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        markParentNodes(root, NULL, start);
        
        int time = -1;
        unordered_set<TreeNode*> vis; 
        queue<TreeNode*> q; q.push(st);   
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                auto curr = q.front();  q.pop();
                vis.insert(curr);
                
                if(curr -> left and !vis.count(curr -> left)) q.push(curr -> left);
                
                if(curr -> right and !vis.count(curr -> right)) q.push(curr -> right);
                
                if(par[curr] and !vis.count(par[curr])) q.push(par[curr]);
            }
            time++;
        }
        
        return time;
    }
};