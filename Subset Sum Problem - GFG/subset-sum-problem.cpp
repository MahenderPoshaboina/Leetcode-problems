//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // bool f(int n, vector<int> arr, int sum, vector<vector<bool>> &dp){
    //     if(sum ==0) return true;
    //     if(n==0) return arr[0]==sum;
    //     if(dp[n][sum] != false) return dp[n][sum];
    //     bool notTake= f(n-1, arr, sum, dp);
    //     bool take= false;
    //     if(sum>= arr[n]) take= f(n-1, arr, sum-arr[n], dp);
        
    //     return dp[n][sum]= take || notTake;
    // }
    bool isSubsetSum(vector<int>& arr, int sum) {
    
        int n= arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i=0; i<n; i++) dp[i][0]= 1;
        
        dp[0][arr[0]]= true;
        
        for(int i=1; i<n; i++){
            for(int target= 0; target<=sum; target++){
                bool notTake= dp[i-1] [target];
                bool take= false;
                if(arr[i] <= target) take= dp[i-1][target-arr[i]];
        
                dp[i][target]= take | notTake;
            }
        }
        return dp[n-1][sum];
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends