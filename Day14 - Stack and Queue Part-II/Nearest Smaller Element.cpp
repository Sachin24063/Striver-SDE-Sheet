vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
     vector<int> ans(n);
     stack<int> st;
     st.push(-1);
     for(int i=0;i<n;i++){
         while(!st.empty() && st.top() >= A[i]){
             st.pop();
         }
         ans[i] = st.top();
         st.push(A[i]);
     }
     return ans;
}
