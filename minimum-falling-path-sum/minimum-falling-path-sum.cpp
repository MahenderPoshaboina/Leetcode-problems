class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) dp[n-1][i]= matrix[n-1][i];

        for(int i=n-2; i>=0; i--){
            for(int j= m-1; j>=0; j--){
                int up= dp[i+1][j];
                int dl = (j>0)?dp[i+1][j-1]:INT_MAX;
                int dr = (j<m-1)?dp[i+1][j+1]:INT_MAX;
                dp[i][j] = matrix[i][j] + min(up, min(dl,dr));
            }
        } 

        int minSum=INT_MAX;

        for(int j=0; j<n; j++){
            minSum = min(minSum, dp[0][j]);
        }
        return minSum;
    }
};