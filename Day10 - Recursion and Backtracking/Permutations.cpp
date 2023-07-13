class Solution {
public:
    void solve(int idx,  vector<int>&nums, vector<bool>&choosen, vector<vector<int>>&ans, vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(choosen[i] == false){
            temp.push_back(nums[i]);
            choosen[i] = true;
            solve(i+1,nums,choosen,ans,temp);
            temp.pop_back();
            choosen[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<bool> choosen(n,false);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,choosen,ans,temp);
        return ans;
    }
};
