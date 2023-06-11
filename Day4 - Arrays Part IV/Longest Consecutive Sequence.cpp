class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int min = *min_element(nums.begin(),nums.end());
        set<int>st;
        for(auto it: nums) st.insert(it);
        int streak=1;
        while(true){
            if(st.count(min)){
                streak +=1;
                min += 1;
            }
            else 
            break;
        }
        return streak-1;
    }
};
