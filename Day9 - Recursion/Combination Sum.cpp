class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<vector<int>>& ans,vector<int>& temp, int sum, int n){
        if(sum == target){
            ans.push_back(temp);
        }
        else if(sum < target){
            for(int i=idx; i<n; i++){
                temp.push_back(candidates[i]);
                solve(i, candidates, target, ans, temp, sum+candidates[i], n);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,candidates, target, ans, temp, 0, candidates.size());
        return ans;
    }
};
