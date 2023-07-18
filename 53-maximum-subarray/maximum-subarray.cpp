class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        long long csum=0, osum=LONG_MIN;

        for(int i=0; i<n; i++){
            csum += nums[i];
            if(csum > osum){
                osum = csum;
            }
            if(csum <0) csum =0;
        }
        return osum;
    }
};