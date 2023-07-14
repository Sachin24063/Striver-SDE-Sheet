class Solution {
private:
int solve(int i, int j, vector<int>& cuts,  vector<vector<int>> &dp){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for(int k=i; k<=j; k++){
        int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int sz = cuts.size();
        vector<vector<int>>dp(sz+1, vector<int>(sz+1,0));
        // return solve(1, sz-2, cuts, dp);
        for(int i=sz; i>=1; i--){
            for(int j=1; j<=sz-2; j++){ 
            if(i>j) continue;
            int mini = 1e9;
            for(int k=i; k<=j; k++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
            }
        }
        return dp[1][sz-2];
    }
};
