class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26,0);
        for(int i=0; i<s.size(); i++) freq[s[i]- 'a']++;
        vector<int>vis(26,0);
        stack<char>Stack;

        for(int i=0; i<s.size(); i++){
            if(vis[s[i]- 'a']== 1) {
                freq[s[i]- 'a']--;
                continue;
            }
            while (!Stack.empty() && s[i] < Stack.top() && freq[Stack.top() - 'a'] > 0 ){
                vis[Stack.top()-'a'] = 0;
                Stack.pop();
            }
            Stack.push(s[i]);
            vis[s[i]- 'a'] =1;
            freq[s[i]- 'a']--;
        }

        string ans="";
        while(!Stack.empty()){
            ans+= Stack.top();
            Stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};