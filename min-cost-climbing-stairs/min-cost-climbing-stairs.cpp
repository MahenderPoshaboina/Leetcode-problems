class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>f= cost;
        // return 0;
        for(int i=2; i<size(cost); i++){
            f[i]= cost[i]+ min(f[i-1], f[i-2]);
        }
        return min(f[size(cost)-1], f[size(cost)-2]);
    }
};