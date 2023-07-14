#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, vector<int>>adj;
    vector<int>indegree(n+1,0);
     for(auto it: edges){
       adj[it.first].push_back(it.second);
       indegree[it.second]++;
     }

  queue<int>q;
  for(int i=1;i<=n;i++){
    if(indegree[i]==0) q.push(i);
  }
  int count = 0;
  while(!q.empty()){
    int node = q.front();
    count++;
    q.pop();
    for(auto it: adj[node]){
      indegree[it]--;
      if(indegree[it] == 0) q.push(it);
    }
  }
  if(count == n) return 0;
  return 1;
}
