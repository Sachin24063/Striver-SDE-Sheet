class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-2;
        while(low <= high){
            int mid = (low+high)/2;
            int adj = 0;
            if(mid % 2 == 0) adj = mid+1;
             else adj = mid-1;
                if(nums[mid] == nums[adj]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
        }
        return nums[low];
    }
};
