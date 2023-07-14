class Solution
{
	private:
	void DFS(vector<int> adj[], vector<int>& visited, stack<int>& st, int source){
	    visited[source] = 1;
	    for(auto it: adj[source]){
	        if(!visited[it]){
	            DFS(adj, visited, st, it);
	        }
	    }
	    st.push(source);
	}
	
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> ans;
	   stack<int>st;
	   vector<int>visited(V,0);
	   for(int i=0;i<V;i++){
	       if(!visited[i]){
	           DFS(adj, visited, st, i);
	       }
	   }
	   while(!st.empty()){
	       ans.push_back(st.top());
	       st.pop();
	   }
	   return ans;
	}
};
