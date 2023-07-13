//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int n, int wt[], int val[], int W){
	// if(maxWeight==0) return 0;
	if(n==0){
		if(wt[0]<= W) return val[0];
		return 0;
	}

	int notTake= 0+ f(n-1, wt, val, W);
	int take= INT_MIN;
	if(wt[n] <= W) take= val[n] + f(n-1, wt, val, W- wt[n]);

	return max(take, notTake);
}
    int knapSack(int maxWeight, int weight[], int value[], int n) {
        vector<vector<int>>dp(n, vector<int>(maxWeight+1, 0));

	for(int w = weight[0]; w<= maxWeight; w++) dp[0][w]= value[0];

	for(int i=1; i<n; i++){
		for(int j=1; j<=maxWeight; j++){
			int notTake= dp[i-1][j];
			int take= INT_MIN;
			if(weight[i] <= j) take= value[i]+ dp[i-1][j- weight[i]];

			dp[i][j ]= max(take, notTake);
		}
	}
	return dp[n-1][maxWeight];
}

};


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends