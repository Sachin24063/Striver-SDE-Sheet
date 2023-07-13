// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> &m,int n, vector<string>& ans, string s, int row, int col, vector<vector<int>>& visited){
        if(row == n-1 && col== n-1){
            ans.push_back(s);
            return;
        }
        //downward
        if(row+1<n && !visited[row+1][col] && m[row+1][col] == 1){
            visited[row][col] = 1;
            solve(m, n, ans, s+'D', row+1, col,visited);
           visited[row][col] = 0;
        }
        //left side
        if(col-1>=0 && !visited[row][col-1] && m[row][col-1] == 1){
            visited[row][col] = 1;
            solve(m, n, ans, s+'L', row, col-1,visited);
           visited[row][col] = 0;
        }
        //right side
        if(col+1<n && !visited[row][col+1] && m[row][col+1] == 1){
            visited[row][col] = 1;
            solve(m, n, ans, s+'R', row, col+1,visited);
            visited[row][col] = 0;
        }
        //upward
        if(row-1>=0 && !visited[row-1][col] && m[row-1][col] == 1){
            visited[row][col] = 1;
            solve(m, n, ans, s+'U', row-1, col,visited);
            visited[row][col] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>>visited(n, vector<int>(n,0));
        vector<string> ans;
        string s="";
        if(m[0][0]==1){solve(m, n, ans, s,0,0,visited);}
        return ans;
    }
};

    
