class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int w = 1; w <= amount; w++) {
        if (w % coins[0] == 0) {
            dp[0][w] = w / coins[0];
        } else {
            dp[0][w] = INT_MAX;
        }
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= amount; target++) {
            int notTake = dp[ind - 1][target];
            int take = INT_MAX;
            if (target >= coins[ind]) {
                if (dp[ind][target - coins[ind]] != INT_MAX) {
                    take = 1 + dp[ind][target - coins[ind]];
                }
            }
            dp[ind][target] = min(take, notTake);
        }
    }

    return dp[n - 1][amount] == INT_MAX ? -1 : dp[n - 1][amount];
}

};