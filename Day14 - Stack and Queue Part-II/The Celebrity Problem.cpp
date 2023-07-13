#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
int findCelebrity(int n) {
	
	vector<vector<int>>matrix(n, vector<int>(n));
	 for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 1;  // Set diagonal elements to 1
            } else if (knows(i, j)) {
                matrix[i][j] = 1;  // Person i knows person j
            }
        }
    }
	
	stack<int> st;
	for(int i=0;i<n;i++) st.push(i);

	while(st.size() > 1){
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();
		
		if(knows(a,b)) st.push(b);
		else st.push(a);
	}
	int potential_candidate = st.top();
	
	bool row_check  = true;
	for(int i=0; i<n; i++){
		if(matrix[potential_candidate][i] == 1 && potential_candidate != i) row_check = false;
	}
	bool col_check = true;
	for(int i=0;i<n;i++){
		if(matrix[i][potential_candidate] == 0) col_check = false;
	}

	if(row_check == true && col_check == true) return potential_candidate;
	return -1;
	
}
