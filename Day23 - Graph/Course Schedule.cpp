class Solution {
/*public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create a adjanjancy list
        unordered_map<int, vector<int>> adj;
        vector<int>indegree(numCourses, 0);
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(count == numCourses) return true;
        return false;
    }
    */

private:
bool DFS(unordered_map<int, vector<int>>& adj, vector<int>& visited, vector<int>& result, int source) {
    visited[source] = 1;
    
    for (auto it : adj[source]) {
        if (visited[it] == 1) {
            return true;  // Cycle detected
        } else if (visited[it] == 0) {
            if (DFS(adj, visited, result, it))
                return true;
        }
    }
    
    visited[source] = 2;
    result.push_back(source);
    return false;
}

public:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> adj;
    for (auto it : prerequisites) {
        adj[it[0]].push_back(it[1]);
    }
    
    vector<int> visited(numCourses, 0);
    vector<int> result;
    
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0 && DFS(adj, visited, result, i)) {
            return false;  // Cycle detected, cannot finish all courses
        }
    }
    
    reverse(result.begin(), result.end());
    
    return result.size() == numCourses;
}
};
