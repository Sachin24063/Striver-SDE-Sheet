#include<bits/stdc++.h>

void DFS(int source, unordered_map<int, vector<int>>& adj, vector<bool>& visited, stack<int>& st){
    visited[source] = true;
     
    for(auto it: adj[source]){
        if(!visited[it]){
            DFS(it, adj, visited, st);
        }
    }
    st.push(source);
}

void step3_dfs(int source, unordered_map<int, vector<int>>& adjT, vector<bool>& visited, vector<int>& SCC){
    visited[source] = true;
    SCC.push_back(source);
    for(auto it: adjT[source]){
        if(!visited[it]){
            step3_dfs(it, adjT, visited, SCC);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Step 1: Store all nodes in sorted order according to their finish time
    vector<bool> visited(n, false);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            DFS(i, adj, visited, st);
        }
    }

    // Step 2: Reverse the entire graph
    unordered_map<int, vector<int>> adjT;
    for(int i = 0; i < n; i++) {
        visited[i] = false; // Reset visited array
        for(auto it: adj[i]) {
            adjT[it].push_back(i);
        }
    }

    // Step 3: Perform a DFS according to finish time
    vector<vector<int>> all_scc;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!visited[node]) {
            vector<int> SCC;
            step3_dfs(node, adjT, visited, SCC);
            all_scc.push_back(SCC);
        }
    }
    
    return all_scc;
}
