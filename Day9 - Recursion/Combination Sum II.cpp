public:
    void solve(int idx, int sum, int target, vector<int>&temp, vector<int>&candidates, vector<vector<int>>&ans,int n){
        if(sum == target){
            ans.push_back(temp);
            return;
        } 
        for(int i=idx; i<n;i++){
            if(i!=idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solve(i+1, sum+candidates[i],target, temp, candidates, ans, n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,0,target,temp,candidates, ans,candidates.size());
        return ans;
    }
};
