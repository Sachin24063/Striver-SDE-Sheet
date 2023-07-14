// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V, 1e8);
        dist[S] = 0;
        for(int i=0;i<V;i++){
        for(auto it: edges){
            int source = it[0];
            int dest = it[1];
            int weight = it[2];
            if(dist[source] + weight < dist[dest]){
                dist[dest] = dist[source] + weight;
            }
        }
        }
        //here we complete the bellman ford algorithm but in question it is given that if graph
        //contains the negative cycle then return vector with a single value as 1.
        //so we can make one more relaxation to check that thing
        for(auto it: edges){
            int source = it[0];
            int dest = it[1];
            int weight = it[2];
            if(dist[source] + weight < dist[dest]){
               return {-1};
            }
        }
        return dist;
    }
};
