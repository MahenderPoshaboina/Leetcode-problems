class Solution {
public:
    int climbStairs(int n) {
        int res=0;
        int prev1=1;
        int prev2=2;
        if(n<=2) return n;
        for(int i=2; i<n; i++){
            res = prev2+prev1;
            prev1=prev2;
            prev2= res;
        }
        return res;
    }
};