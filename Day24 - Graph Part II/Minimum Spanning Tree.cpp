
class disjointset{
    vector<int> rank, parent,size;
    public:
    disjointset(int n){
        rank.resize(n+1, 0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int find_ultimate_parent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find_ultimate_parent(parent[node]);
    }
    void union_by_rank(int u, int v){
        int ultimate_parent_u = find_ultimate_parent(u);
        int ultimate_parent_v = find_ultimate_parent(v);
        if(ultimate_parent_u == ultimate_parent_v) return;
        if(rank[ultimate_parent_u] < rank[ultimate_parent_v]){
            parent[ultimate_parent_u] = ultimate_parent_v;
        }
        else if(rank[ultimate_parent_v] < rank[ultimate_parent_u]){
            parent[ultimate_parent_v] = ultimate_parent_u;
        }
        else{
            //if equal then you can connect either u to v or v to u anything
            parent[ultimate_parent_v] = ultimate_parent_u;
            rank[ultimate_parent_u]++;
        }
        
    }
    
    
    void union_by_size(int u, int v){
        int ultimate_parent_u = find_ultimate_parent(u);
        int ultimate_parent_v = find_ultimate_parent(v);
        if(ultimate_parent_u == ultimate_parent_v) return;
        if(size[ultimate_parent_u] < size[ultimate_parent_v]){
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v] += size[ultimate_parent_u];
        }
        else{
            //if equal then you can connect either u to v or v to u anything
             parent[ultimate_parent_u] = parent[ultimate_parent_v];
             size[ultimate_parent_u] += size[ultimate_parent_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<pair<int, vector<int>>> edges;
       for(int i=0;i<V;i++){
           for(auto it: adj[i ]){
               int node = i;
               int weight = it[1];
               int adjnode = it[0];
               edges.push_back({weight, {node, adjnode}});
           }
       }
       //creating the object of our desjointset datastructure with size V
       disjointset ds(V);
       sort(edges.begin(),edges.end());
       int total_cost = 0;
       for(auto it: edges){
           int wt = it.first;
           int u = it.second[0];
           int v = it.second[1];
           if(ds.find_ultimate_parent(u) != ds.find_ultimate_parent(v)){
               total_cost += wt;
               ds.union_by_rank(u,v);
           }
       }
       return total_cost;
    }
};
