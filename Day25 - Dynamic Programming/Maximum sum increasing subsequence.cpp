class Solution{
private: 
int solve(int idx, int prev, int arr[], int n, vector<vector<int>>&dp){
    if(idx == n){
        return 0;
    }
    if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
    int notpick = solve(idx+1, prev, arr, n, dp);
    int pick = 0;
    if(prev == -1 || arr[idx] > arr[prev]){
        pick = solve(idx+1, idx, arr, n, dp) + arr[idx];
    }
    return dp[idx] [prev+1] = max(pick, notpick);
}
	public:
	int maxSumIS(int arr[], int n)  
	{  
	   vector<int>prev1(n+1, 0), curr(n+1, 0);
	   //return solve(0, -1, arr, n, dp);
	   for(int idx=n-1; idx>=0;idx--){
	       for(int prev=idx-1; prev>=-1; prev--){
	           int notpick = prev1[prev+1];
                int pick = 0;
                if(prev == -1 || arr[idx] > arr[prev]){
                    pick = prev1 [idx+1] + arr[idx];
                }
                curr[prev+1] = max(pick, notpick);
	       }
	       prev1 = curr;
	   }
	   return prev1[0];
	}  
};
