class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int streak = 0;
        int curr_streak=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr_streak+=1;
                streak = max(streak,curr_streak);
            }
            else curr_streak = 0;
        }
        return streak;
    }
};
