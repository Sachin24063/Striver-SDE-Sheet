vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    pq.push({A[0] + B[0], {0, 0}});
    st.insert({0, 0});
    vector<int> ans;

    for(int i = 0; i < C; i++){
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.first);
        int left = top.second.first;
        int right = top.second.second;
    
        if(left+1 < A.size() && !st.count({left+1, right})){
            pq.push({A[left+1]+B[right], {left+1,right}});
            st.insert({left+1, right});
        }
        if(right+1 < B.size() && !st.count({left, right+1})){
            pq.push({A[left]+B[right+1], {left,right+1}});
            st.insert({left, right+1});
        }
    }

    return ans;
}
