class Solution
{
    private:
    void BFS(int source, vector<vector<int>> adj[], vector<int>& dist){
        dist[source] =0;
        set<pair<int,int>>st;
        st.insert({0, source});
        while(!st.empty()){
            auto container = *(st.begin()); //pointer og first element in the set
            int node = container.second;
            int dis = container.first;
            st.erase(container);
            for(auto it: adj[node]){
                int edgeweight = it[1];
                int adjnode = it[0];
                if(dis + edgeweight < dist[adjnode]){
                    if(dist[adjnode] != INT_MAX){
                    st.erase({dist[adjnode], adjnode});
                    }
                        dist[adjnode] = dis + edgeweight;
                        st.insert({dist[adjnode], adjnode});
                }
            }
        }
    }
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        BFS(S, adj, dist);
        return dist;
    }
};
