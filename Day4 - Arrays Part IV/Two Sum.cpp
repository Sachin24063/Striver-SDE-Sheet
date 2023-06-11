class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        vector<int>ans,dup;
        dup = nums;
        sort(nums.begin(),nums.end());
        while(low<high){
            if(nums[low] + nums[high] == target){
                break;
            }
            else if(nums[low] + nums[high] >target){
                high--;
            }
            else low ++;
        }
       for(int i=0;i<nums.size();i++){
           if(nums[low] == dup[i]) ans.push_back(i);
           else if(nums[high] == dup[i]) ans.push_back(i);
       }
       return ans;
    }
};
