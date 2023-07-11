class Solution {
public:
    int find(int i, int j, vector<vector<int>> grid, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];

        int l= grid[i][j]+ find(i-1, j, grid, dp);
        int r = grid[i][j]+ find(i, j-1, grid, dp);

        return dp[i][j]= min(l,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        // int dp[n][m];
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) dp[i][j]= grid[i][j];
                else{
                    int l=grid[i][j];
                    int r=grid[i][j];
                    if(i>0) l += dp[i-1][j];
                    else l += 1e9;
                    if(j>0) r += dp[i][j-1];
                    else r += 1e9;
                    dp[i][j]= min( l,r );
                }
            }
        }
        // return find(n-1, m-1, grid, dp);
        return dp[n-1][m-1];
    }
};