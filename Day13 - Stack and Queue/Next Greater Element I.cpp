class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
       stack<int> st;
       int n = nums2.size();
       st.push(nums2[n-1]);
       mp[nums2[n-1]] = -1;
       for(int i=n-2;i>=0;i--){
           while(!st.empty() && st.top() <= nums2[i]){
               st.pop();
           }
           if(!st.empty()){
               mp[nums2[i]] = st.top();
           }
           else mp[nums2[i]] = -1;
           st.push(nums2[i]);
       }
       for(int i=0;i<nums1.size();i++){
           ans.push_back(mp[nums1[i]]);
       }
       return ans;
    }
};
