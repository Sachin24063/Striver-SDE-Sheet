class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               long long temp_sum = (long)target - nums[i] - nums[j];
                int left = j+1, right = nums.size()-1;
                while(left < right){
                    int temp_ans = nums[left] + nums[right];
                    if(temp_ans < temp_sum){
                        left++;
                    }
                    else if(temp_ans > temp_sum){
                        right--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(right>left && nums[right] == nums[right-1]) right--;
                        right--;
                        left++;
                    }
                }
                while(j<n-1 && nums[j] == nums[j+1])j++;
            }
            while(i<n-1 && nums[i] == nums[i+1])i++;
        }
        return ans;
    }
};
