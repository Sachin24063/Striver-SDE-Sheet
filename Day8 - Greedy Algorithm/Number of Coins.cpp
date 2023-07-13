class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int>dp(V+1, INT_MAX);
	    dp[0] = 0;
	    for(int i=1; i<=V;i++){
	        for(int j=0;j<M;j++){
	            if(i-coins[j] >=0 && dp[i-coins[j]]!=INT_MAX){
	                dp[i] = min(dp[i],dp[i-coins[j]]+1);
	            }
	        }
	    }
	    if(dp[V] == INT_MAX) return -1;
	    return dp[V];
	} 
	  
};
