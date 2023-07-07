class Solution {
public:
    int ans;
    std::vector<int> count;
    
    int distributeCookies(std::vector<int>& cookies, int k) {
        ans = INT_MAX;
        count.resize(k);

        backtrack(0, cookies, k);
        return ans;
    }
    
    void backtrack(int cookieNumber, std::vector<int>& cookies, int k) {
        if (cookieNumber == cookies.size()) {
            int max = 0;
            for (int i = 0; i < k; i++) {
                max = std::max(max, count[i]);
            }
            ans = std::min(ans, max);
            return;
        }
        
        for (int i = 0; i < k; i++) {
            count[i] += cookies[cookieNumber];
            backtrack(cookieNumber + 1, cookies, k);
            count[i] -= cookies[cookieNumber];
            if (count[i] == 0) {
                break;
            }
        }
    }
};