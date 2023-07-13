int helper(vector<int>&a  , int val){
    int l=0, r = a.size()-1;
    while(l<=r){
        int  mid = (l+r)/2;
        if(a[mid] <= val){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return l;
}

int Solution::findMedian(vector<vector<int>>& A) {
    int n = A.size(), m = A[0].size();
    int low = 1, high = 1e9;
    while(low <= high){
        int cnt = 0, mid = (low + high)/2;
    for(auto it: A){
        cnt += helper(it, mid);
    }
    if(cnt <= (n*m)/2) low = mid+1;
    else high = mid-1;
    }
    return low;
}
