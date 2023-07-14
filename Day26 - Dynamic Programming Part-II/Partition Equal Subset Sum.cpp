class Solution {
private:
    bool solve(int idx, vector<int>& nums, int k, vector<vector<int>>& dp) {
        if (k == 0) return true;
        if (idx < 0) {
            return false;
        }
        if (dp[idx][k] != -1) return dp[idx][k];
        bool nottake = solve(idx - 1, nums, k, dp);
        bool take = false;
        if (nums[idx] <= k) take = solve(idx - 1, nums, k - nums[idx], dp);
        return dp[idx][k] = (take || nottake);
    }

public:
    bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) return false;
    int k = sum / 2;
    vector<vector<bool>>dp(n, vector<bool>(1000001,false));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for(int i=1;i<n;i++){
        for(int target = 1; target<=k; target++){
             bool nottake =  dp[i-1][target];
                bool take = false;
                if(nums[i] <= target) take = dp[i-1][target-nums[i]];
                dp[i][target] = (take || nottake);
        }
    }
return dp[n-1][k];
}
};
