class Solution {
private:
int solve(int idx1, int idx2, string text1, string text2, vector<vector<int>>&dp){
    if(idx1 <0 || idx2 <0){
        return 0;
    }
    
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int match = 0, notmatch=0;
    if(text1[idx1] == text2[idx2]){
        match = 1 + solve(idx1-1, idx2-1, text1, text2, dp);
    }
    else{
        notmatch = max(solve(idx1-1, idx2, text1, text2, dp),
                        solve(idx1, idx2-1, text1, text2, dp));
    }
    return dp[idx1][idx2] = max(match, notmatch);
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int>prev(n2+1,0), curr(n2+1, 0);
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int match=0, notmatch=0;
                if(text1[i-1] == text2[j-1]){
                    match = 1 + prev[j-1];
                 }
                else{
                    notmatch = max(curr[j], curr[j-1]);
                 }
                curr[j] = max(match, notmatch);
            }
            prev = curr;
        }
        return prev[n2];
    }
};
