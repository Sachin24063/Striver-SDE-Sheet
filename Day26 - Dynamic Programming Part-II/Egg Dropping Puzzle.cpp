class Solution
{
private:
int solve(int n, int k, vector<vector<int>>&dp){
    if(k == 1 || k== 0 || n == 1){
        return k;
    }
    if(dp[n][k] != -1) return dp[n][k];
    int mini = INT_MAX;
    for(int i=1; i<=k; i++){
        int broke = solve(n-1, i-1, dp);
        int notbroke = solve(n, k-i, dp);
        mini = min(mini, max(broke, notbroke));
    }
    return dp[n][k] = mini + 1;
}
    public:
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
        return solve(n, k, dp);
    }
};
