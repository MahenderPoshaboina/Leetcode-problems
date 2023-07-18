class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        
        int ind=-1;
        int N= nums.size();
        if(N==1) return;
        for(int i= N-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=N-1; i>ind; i--){
            if(nums[i]> nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }
        
        reverse(nums.begin()+ind+1, nums.end());
        // return arr;
        // }
    }
};