class Solution {
  private:
  void DFS(int node, vector<int> adj[], vector<int>& ans, vector<int> & visited){
      visited[node] = 1;
      ans.push_back(node);
      //travers all the neighbours of that particular node
      for(auto it: adj[node]){
          if(!visited[it]){
              DFS(it, adj, ans, visited);
          }
      }
  }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int> visited(V,0);
       vector<int> ans;
       int start = 0;// because of 0 index based graph
       DFS(start, adj, ans, visited);
       return ans;
    }
};
