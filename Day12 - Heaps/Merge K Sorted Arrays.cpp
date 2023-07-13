#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto it: kArrays){
        for(int i=0;i<it.size();i++){
            pq.push(it[i]);
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
