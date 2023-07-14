class Solution {
private:
int solve(int idx, vector<int>& coins, int target, vector<vector<int>>&dp){
    if(idx == 0){
        if(target%coins[0] == 0){
            return target/coins[0];
        }
        return 1e9;
    }
    if(dp[idx][target] != -1) return dp[idx][target];

    int pick = 1e9;
    int notpick = solve(idx-1, coins, target, dp);
    if(target>=coins[idx]) pick = solve(idx, coins, target-coins[idx], dp) +1;
    
    return dp[idx][target] = min(pick, notpick);
}
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        // int ans = solve(n-1, coins, amount, dp);
        // if(ans >= 1e9) return -1;
        // return ans;
        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0){
                prev[i] = i/coins[0];
            }
            else{
                prev[i] = 1e9;
            }
        }
        for(int i=1;i<n;i++){
            vector<int>temp(amount+1,0);
            for(int target=1;target<=amount;target++){
                int pick = INT_MAX;
                int notpick = prev[target];
                if(target>=coins[i]) pick = temp[target-coins[i]] + 1;
                temp[target] = min(pick, notpick);
            }
            prev = temp;
        }
        if(prev[amount] >= 1e9) return -1;
        return prev[amount];
    }
};
