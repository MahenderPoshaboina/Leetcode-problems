class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1); // Frequency can be at most nums.size()

        for (auto it : freqMap) {
            int num = it.first;
            int freq = it.second;
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && k > 0; i--) {
            for (int j = 0; j < buckets[i].size() && k > 0; j++) {
                result.push_back(buckets[i][j]);
                k--;
            }
        }

        return result;
    }
};