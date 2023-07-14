//Using Recursion and Memoization which gives the TLe
class Solution {
public:
    bool solve(string s, int pos, set<string>& st,vector<int>& dp){
        if(pos == s.size()) return true;
        if(dp[pos] != -1) return dp[pos];
        
        for(int i=pos;i<s.size();i++){
            if(st.count(s.substr(pos,i-pos+1))){
                 if(solve(s, i+1, st,dp)) {
                     return dp[pos] = true;
                     }
                 }
        }
        return dp[pos] = false;
        }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it: wordDict){
            st.insert(it);
        }
        vector<int>dp(s.size(), -1);
        return solve(s, 0, st,dp);
    }
};

//using DP Top down approach
/*class Solution {
public:
    bool solve(string s, int pos, unordered_set<string>& st,vector<bool> & dp){
        if(pos == s.size()) return true;
       if(dp[pos]==true) return dp[pos];

        for(int i=pos;i<s.size();i++){
            if(st.count(s.substr(pos,i-pos+1))){
                    if(solve(s, i+1, st,dp)) return dp[pos] = true;
                 }
        }
        return dp[pos]=false;
        }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<bool>dp(301,false);
        return solve(s, 0, st,dp);
    }
};
*/

// Using DP Bottom up tabulation method
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> st(wordDict.begin(), wordDict.end());
//         int n = s.size();
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
        
//         for (int len = 1; len <= n; len++) {
//             for (int i = 0; i <= n - len; i++) {
//                 int j = i + len - 1;
//                 string sub = s.substr(i, len);
//                 if (st.count(sub)) {
//                     dp[i][j] = true;
//                     continue;
//                 }
//                 for (int k = i; k < j; k++) {
//                     if (dp[i][k] && dp[k + 1][j]) {
//                         dp[i][j] = true;
//                         break;
//                     }
//                 }
//             }
//         }
        
//         return dp[0][n - 1];
//     }
// };


