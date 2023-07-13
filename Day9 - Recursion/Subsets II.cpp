class Solution {
public:
    void solve(int idx, vector<int>&nums, vector<int> d_s,vector<vector<int>>&ans){
        ans.push_back(d_s);

    for(int i=idx; i<nums.size();i++){
        if(i != idx && nums[i] == nums[i-1]) continue;
        d_s.push_back(nums[i]);
        solve(i+1, nums, d_s, ans);
         d_s.pop_back();
    }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> d_s;
        solve(0, nums, d_s, ans);
        return ans;
    }
};
