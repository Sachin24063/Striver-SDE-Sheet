class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   vector<int> top_order;
	     vector<int>indegree(V,0);
	     for(int i=0;i<V;i++){
	     for(auto it: adj[i]){
	         indegree[it]++;
	     }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    while(!q.empty()){
	         int node = q.front();
	         top_order.push_back(node);
	         q.pop();
	         
	         for(auto it: adj[node]){
	              indegree[it]--;
	             if(indegree[it] == 0){
	                 q.push(it);
	             }
	         }
	    }
	    return top_order;
	}
};
