class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t="";
        for(int i= s.size()-1; i>=0; i--){
            t += s[i];
        }
        int ind1= s.size();
        int ind2= t.size();
        vector<vector<int>>dp(ind1+1, vector<int>(ind2+1, 0));
        
        for(int i=1; i<=ind1; i++){
            for(int j=1; j<=ind2; j++ ){
                // if(dp[i][j] != -1) return dp[i][j];
                if(s[i-1]== t[j-1]) dp[i][j]= dp[i-1][ j-1]+1;
                else dp[i][j]=max(dp[i-1][ j], dp[i][ j-1]);
            }
	    }

        return dp[ind1][ind2];
    }
};