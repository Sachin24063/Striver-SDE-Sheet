class Solution {
public:
    bool is_valid(int i, int j, int n, int m, vector<vector<int>>&grid){
        return(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                q.push({i,j});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int time = 0;
        while(!q.empty()){
            int q_size = q.size();
            int temp = 0;
            while(q_size--){
                pair<int,int>p = q.front();
                q.pop();
                int x1 = p.first;
                int y1 = p.second;

                vector<int> a = {1,-1,0,0};
                vector<int> b = {0,0,1,-1};

                for(int i=0;i<4;i++){
                    int x = x1 + a[i];
                    int y = y1 + b[i];
                    if(is_valid(x,y,n,m,grid)){
                        grid[x][y] = 2;
                        q.push({x,y});
                        temp++;
                    }
                }
            }
            if(temp != 0) time++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){ 
                    time = -1;
                    break;
                }
            }
        }
        return time;
    }
};
