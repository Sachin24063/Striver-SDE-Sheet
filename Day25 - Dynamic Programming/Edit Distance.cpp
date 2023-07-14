class Solution {
private:
int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp){
    if(i == 0){
        return j;
    }
    if(j==0){
        return i;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(word1[i-1] == word2[j-1]){
        return dp[i][j] = solve(i-1, j-1, word1, word2, dp);
    }
    else{
    int insert = solve(i, j-1, word1, word2, dp) + 1;
    int remove = solve(i-1, j, word1, word2, dp) + 1;
    int replace = solve(i-1, j-1, word1, word2, dp) + 1;
    return dp[i][j] = min(insert, min(remove, replace));
    }
}
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>prev(m+1,0), curr(m+1, 0);
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
            for(int i=1;i<=n;i++){
                curr[0] = i;
                for(int j=1;j<=m;j++){
                    if(word1[i-1] == word2[j-1]){
                         curr[j] = prev[j-1];
                    }
                    else{
                    int insert = prev[j-1] + 1;
                    int remove = prev[j] + 1;
                    int replace = curr[j-1] + 1;
                    curr[j] = min(insert, min(remove, replace));
                    }
            }
            prev = curr;
        }
        return prev[m];
    }
     
    };
