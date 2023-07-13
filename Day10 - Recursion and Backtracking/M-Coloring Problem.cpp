class Solution{
public:
    bool is_safe(int n, int node, bool graph[101][101], int color[], int col){
        for(int i=0;i<n;i++){
            if(i != node && graph[i][node] == true && color[i] == col){
                return false;
            }
        }
        return true;
    }
    

    bool solve(int node, int color[], bool graph[101][101],int m, int n){
        if(node == n){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(is_safe(n, node,  graph, color, i)){
                color[node] = i;
                if(solve(node+1,color,graph,m,n)) return true;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        if(solve(0,color,graph,m,n)) return true;
        return false;
    }
};
