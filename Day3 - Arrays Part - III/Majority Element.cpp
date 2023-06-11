class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size()/2;
    unordered_map<int, int> mp;
        for(int it=0;it<nums.size();it++){
            mp[nums[it]]++;
            if(mp[nums[it]]>size) return nums[it];
        }
        return -1;
    }
};
