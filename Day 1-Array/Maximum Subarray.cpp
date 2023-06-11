class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans =0;
        int expected = nums[0];
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            if(ans > expected) expected = ans;
            if(ans<0) ans = 0;
        }
        return expected;
    }
};
