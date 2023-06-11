class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>> st;
        vector<vector<int>> ans;
        for(auto it: intervals){
                if(st.empty()){st.push(it);}
                else{
                    auto temp =  st.top();
                    if(it[0] <= temp[1]){
                    st.pop();
                    temp[0] = min(temp[0],it[0]);
                    temp[1] = max(temp[1],it[1]);
                    st.push(temp);
                }
                else st.push(it);
                }
            }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
