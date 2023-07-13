#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    stack<int>stk;
    vector<int>left(n),right(n),ans(n,INT_MIN);
    // left[0]=-1;
    // stk.push(0);
    for(int i=0;i<n;i++) {
        while(!stk.empty() && a[stk.top()]>=a[i]) {
            stk.pop();
        }
        if(stk.empty()) left[i] = -1;
        else left[i] = stk.top();
        stk.push(i);
    }
    while(!stk.empty()) {
        stk.pop();
    }
    // right[n-1]=n;
    // stk.push(n-1);
    for(int i=n-1;i>=0;i--) {
        while(!stk.empty() && a[stk.top()]>=a[i]) {
            stk.pop();
        }
        if(stk.empty()) right[i] = n;
        else right[i] = stk.top();
        stk.push(i);
    }
    for(int i=0;i<n;i++) {
        int len=right[i]-left[i]-1;
        ans[len-1]=max(ans[len-1],a[i]);
    }
    for(int i=n-2;i>=0;i--) {
        ans[i]=max(ans[i],ans[i+1]);
    }
    return ans;
}
