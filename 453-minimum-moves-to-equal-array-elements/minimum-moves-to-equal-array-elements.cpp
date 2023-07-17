class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEle= *min_element(nums.begin(), nums.end());
        int res=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int d= abs(minEle- nums[i]);
            res += d;
        }
        return res;
    }
};