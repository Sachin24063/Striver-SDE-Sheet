class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int high = (row * column)-1;
        int low = 0;
        if(column==0) return false;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[mid / column][mid % column] == target){
                return true;
            }
            if(matrix[mid / column][mid % column] > target){
                 high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};
