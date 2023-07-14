//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	   int n = matrix.size();
	   //to implement our logic we can first make all the -1 to infinity
	   for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	           if(matrix[i][j] == -1){
	               matrix[i][j] = 1e9;
	           }
	           //if(i == j) matrix[i][j] = 0;
	       }
	   }
	   
	   for(int via=0; via<n; via++){
	       for(int i=0;i<n;i++){
	           for(int j=0;j<n;j++){
	               matrix[i][j] = min(matrix[i][j], (matrix[i][via] + matrix[via][j]));
	           }
	       }
	   }
	   //at the end of the day make all the infinity to -1
	   for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	           if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	           }
	       }
	   }
	}
};
