bool min_pages(int val, vector<int>&A, int students){
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<A.size();i++){
        if(sum+A[i]>val){
            cnt++;
            sum = A[i];
           if(sum > val) return false;
        }
        else{
            sum += A[i];
        }
    }
    return cnt<students;
}

int Solution::books(vector<int> &A, int B) {
    if(B>A.size()) return -1;
    int low = INT_MAX, high = A[0];
    for(int i=0;i<A.size();i++){
        high += A[i];
        low = min(low,A[i]);
    }
        while(low <= high){
            int mid = (high + low)/2;
            if(min_pages(mid,A,B)){
                high = mid-1;
            }
            else low = mid+1;
        }
    return low;
}
