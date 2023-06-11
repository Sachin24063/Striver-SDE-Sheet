class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int inf_point = 0;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                inf_point = i;
                break;
            }
        }
        if(inf_point == 0) sort(nums.begin(),nums.end());
        else{
             int min = INT_MAX;
             int swappable = nums[inf_point-1];
             for(int i=inf_point;i<nums.size();i++){
                 if(nums[i]-swappable > 0 && nums[i]-swappable <min){
                     swap(nums[inf_point-1],nums[i]);
                 }
             }
             sort(nums.begin()+inf_point, nums.end());
        }
    }
};
