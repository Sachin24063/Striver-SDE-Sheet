// User function Template for C++

class Solution{
private:
bool ispalindrome(string s, int i, int j){
    while(i<j){
        if(s[i] != s[j]) return false;
            i++;
            j--;
    }
    return true;
}
int solve(int idx, string s, vector<int>& dp){
    if(idx >= s.size()){
        return 0;
    }
    if(dp[idx] != -1) return dp[idx];
    int mini = 1e8;
    for(int i=idx; i<s.size();i++){
        if(ispalindrome(s, idx, i)){
            int min_step = 1 + solve(i+1, s, dp);
            mini = min(mini, min_step);
        }
    }
    return dp[idx] = mini;
}
public:
    int palindromicPartition(string str)
    {
        vector<int>dp(str.size(),-1);
        return solve(0, str, dp)-1;
    }
};
