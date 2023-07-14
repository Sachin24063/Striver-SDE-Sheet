
class Solution{
private:
int solve(int idx, int W, int wt[], int val[], vector<vector<int>>&dp){
    if(idx == 0){
        if(wt[0] <= W){
            return val[0];
        }
        return 0;
    }
    if(dp[idx][W] != -1) return dp[idx][W]; 
    int pick = -1e8;
    int notpick = solve(idx-1, W, wt, val, dp);
    if(W >= wt[idx]) pick = solve(idx-1, W-wt[idx], wt,val, dp) + val[idx];
    return dp[idx][W] = max(pick, notpick);
}
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<int>dp(W+1,0);
    //   return solve(n-1, W, wt, val, dp);
    for(int i=wt[0]; i<= W; i++){
        dp[i] = val[0];
    }
    for(int i=1;i<n;i++){
        for(int j = W;j>=0;j--){
            int pick = -1e8;
            int notpick = dp[j];
            if(j >= wt[i]) pick = dp[j-wt[i]] + val[i];
            dp[j] = max(pick, notpick);
        }
    }
    return dp[W];
    }
};
