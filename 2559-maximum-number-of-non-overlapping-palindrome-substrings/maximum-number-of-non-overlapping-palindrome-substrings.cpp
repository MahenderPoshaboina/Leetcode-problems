// class Solution {
// public:
//     bool isPalindrome(string s, int i, int j){
//         while(i<j){
//             if(s[i++] != s[j--]) return false;
//         }
//         return true;
//     }
//     int maxPalindromes(string s, int k) {
//         int ans=0;
//         int n= s.size();
//         for(int i=0; i<n; i++){
//             for(int j=i; i<n; j++){
//                 int len= j-i+1;
//                 if(len>k +1) break;
//                 if(len >=k and isPalindrome(s,i,j) ){
//                     ans++;
//                     i=j-1;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
public:
    int maxPalindromes(string s, int k) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                int len= j-i+1;
                if(len>k+1){
                    break;
                }
                if(len>=k and isPalindrome(s, i, j)){
                    ans++; 
                    i=j;
                    break;
                }
            }
        }
        return ans;
    }
};