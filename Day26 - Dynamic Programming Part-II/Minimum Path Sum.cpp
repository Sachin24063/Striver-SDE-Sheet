class Solution {
private:
int findmin(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(m<0 || n<0){
        return 1e5;
    }
    if(m==0 && n==0){
        return grid[m][n];
    }
    if(dp[m][n] != -1) return dp[m][n];
    int up = grid[m][n] + findmin(m-1, n, grid, dp);
    int left = grid[m][n] + findmin(m, n-1, grid, dp);
    return dp[m][n] = min(up, left);
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        dp[0][0] = grid[0][0];
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int left=1e5%‹,up =1e5;
                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up, left);
            }
        }
        return dp[m-1][n-1];
    }
};
