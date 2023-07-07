class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        unordered_map<char, int>mp;
        int start =0, end=0;
        int maxi =0;
        int maxCount=0;
        int replacements=0;
        if(s.size()==1) return 1;
        while(end < s.size()){

            mp[s[end]] ++;
            maxCount = max(maxCount, mp[s[end]]);
            replacements = (end-start +1)-maxCount;

            if(replacements>k){
                mp[s[start]]--;
                start++;
            } 
            maxi = max(maxi, end-start+1);
            end++;
        }
        return maxi;
    }
};