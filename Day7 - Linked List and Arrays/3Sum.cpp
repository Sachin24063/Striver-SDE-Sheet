class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j = i+1, n = nums.size()-1;
            while(j<n){
                if(nums[i]+nums[j]+nums[n] == 0){
                    vector<int> v = {nums[i],nums[j],nums[n]};
                    st.insert(v);
                    j++;
                    n--;
                }
                else if(nums[i]+nums[j]+nums[n] < 0){
                    j++;
                }
                else{
                    n--;
                }
            }
        }
      for(auto it : st) ans.push_back(it);
        return ans;
    }
};
