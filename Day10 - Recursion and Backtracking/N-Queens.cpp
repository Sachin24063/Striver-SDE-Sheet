class Solution {
public:
    vector<vector<string>> ans;
    bool is_safe(int row, int col, vector<string>&board){
        for(int i=0;i<board.size();i++){
            if(board[row][i] == 'Q') return false;
        }
        for(int i = row,j=col; i>=0 && j>=0;i--,j--){
                if(board[i][j] == 'Q') return false;
        }
        for(int i = row,j=col; i<board.size() && j>=0;i++,j--){
                if(board[i][j] == 'Q') return false;
        }
        return true;
    }

public:
    void solve(int col,vector<string>&temp){
        if(col == temp.size()){
            ans.push_back(temp);
              return;
        }
        for(int i=0;i<temp.size();i++){
        if(is_safe(i,col,temp)){
            temp[i][col] = 'Q';
            solve(col+1, temp);
            temp[i][col] = '.';
        }
        }
        }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n,string(n,'.'));
        solve(0,temp);
        return ans;
    }
};
