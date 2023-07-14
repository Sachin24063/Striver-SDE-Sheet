class Solution {
int solve(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == nums.size()){
            return 0;
        }
        
        if (dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int notpick = solve(idx+1, prev, nums, dp);

        int pick = 0;
        if (prev == -1 || nums[idx] > nums[prev]){
        pick = solve(idx+1, idx, nums, dp) + 1;
        }
        return dp[idx][prev+1] = max(pick, notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        /*
        vector<int>prev1(n+1, 0), curr(n+1, 0);
        // return solve(0, -1, nums, dp);
        for(int idx = n-1; idx>=0; idx--){
            for(int prev = idx-1; prev>=-1; prev--){
                int notpick = prev1[prev+1];

                int pick = 0;
                if (prev == -1 || nums[idx] > nums[prev]){
                pick = prev1[idx+1]+1;
                }
                curr[prev+1] = max(pick, notpick);
            }
            prev1 = curr;
        }
        return prev1[0];
        */
        /*
        int ans = 1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
          for(int prev = 0; prev<i; prev++){
            if(nums[prev] < nums[i]){
              dp[i] = max(dp[i], dp[prev]+1);
              ans = max(ans, dp[i]);
            }
          }
        }
        return ans;
        */
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
          if(nums[i] > ans.back()) ans.push_back(nums[i]);
          else{
             int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
             ans[idx] = nums[i];
          }
        }
        return ans.size();
    }
};
