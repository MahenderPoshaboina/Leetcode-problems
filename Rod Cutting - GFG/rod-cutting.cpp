//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int n, int N, int price[], vector<vector<int>> &dp){
        if(n==0) return N* price[0];
        if(dp[n][N] != -1) return dp[n][N];
        int NotTake= f(n-1, N, price, dp);
        int take= INT_MIN;
        int rodL= n +1;
        if(rodL <= N) take = price[n]+ f(n, N- rodL, price, dp);
        
        return dp[n][N]=max(take, NotTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(n-1,n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends