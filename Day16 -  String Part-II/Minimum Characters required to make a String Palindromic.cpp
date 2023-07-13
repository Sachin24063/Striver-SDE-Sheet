int Solution::solve(string A) {
    string temp = A;
    reverse(A.begin(),A.end());
    temp += "$" + A;
    int n = temp.size();
    int len = 0, i=1;
    vector<int>lps(n);
    lps[0] = 0;
    while(i<n){
        if(temp[len] == temp[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
    return A.size() lps.back();
}
