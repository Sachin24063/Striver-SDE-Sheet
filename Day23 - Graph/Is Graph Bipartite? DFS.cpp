class Solution {
private:
bool DFS(int source,  unordered_map<int, vector<int>>& adj, vector<int>& color, int col){
    color[source] = col;
    for(auto it: adj[source]){
        if(color[it] == -1){
            if(!DFS(it, adj, color, !color[source])) return false;
        }
        else if(color[it] == color[source]){
            return false;
        }
    }
    return true;
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>>adj;
        int n = graph.size();
        for(int i=0;i<n;i++){
            for(int j : graph[i]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i] == -1 && !DFS(i, adj, color, 0)){
                return false;
        }
    }
     return true;
    }
};
