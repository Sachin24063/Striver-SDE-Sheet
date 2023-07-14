class Solution {
public:
void solve(vector<vector<int>>& image, int sr, int sc, int new_color, int n, int m, int source){
    if(sr<0 || sr >= m || sc<0 || sc >= n){
        return;
    }
    else if(image[sr][sc] != source){
        return;
    }
    image[sr][sc] = new_color;
    solve(image, sr-1, sc, new_color, n, m, source);
    solve(image, sr+1, sc, new_color, n, m, source);
    solve(image, sr, sc-1, new_color, n, m, source);
    solve(image, sr, sc+1, new_color, n, m, source);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int source = image[sr][sc];
        if(color == source) return image;
        solve(image, sr, sc, color, n, m, source);
        return image;
    }
};
