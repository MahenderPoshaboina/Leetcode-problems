class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minimum = INT_MAX;
        int left=0, right=0;
        int arraySum=0;
        while(right <size(nums)){
            arraySum += nums[right];
            while(arraySum >= target){
                minimum = min(minimum, right-left+1);
                arraySum -= nums[left];
                left++;
            }
            right++;
        }
        
        return minimum == INT_MAX?0:minimum;
    }
};