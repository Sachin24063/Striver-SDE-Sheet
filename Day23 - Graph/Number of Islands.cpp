class Solution {
private:
void BFS(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
    int m = grid.size();
    int n = grid[0].size();
    visited[i][j] = 1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        vector<int> a = {1,-1,0,0};
        vector<int> b = {0,0,1,-1};
        for(int i=0; i<4;i++){
            int x = row + a[i];
            int y = col + b[i];
            if(x>=0 && x<m && y>=0 && y<n &&
                grid[x][y] == '1' && !visited[x][y]){
                    visited[x][y] = 1;
                    q.push({x,y});
                }
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int componenets = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    componenets++;
                    BFS(grid, visited, i, j);
                }
            }
        }
        return componenets;
    }
};
