#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int>arr,int l,int r){

    for(int i=l;i<=r;i++){
        int ans=INT_MIN;
        ans=max(ans,arr[i]);
        }
}

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>ans;
        
        int l=0;
        int r=k-1;
        
        int maxi=INT_MIN;
        
        for(int i=0;i<k;i++){
            
            maxi=max(maxi,arr[i]);
        }
        
        ans.push_back(maxi);
        
        while(r<n-1){
            
            if(arr[l]==maxi){
                maxi=findMax(arr,l+1,r);
            l++;
            r++;
            maxi=max(maxi,arr[r]);
            ans.push_back(maxi);
            }
            
        }
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); 

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

