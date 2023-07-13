bool place_cow(vector<int> &stalls, int k, int mid){
    int cow = 1 ;
    int place = stalls[0];
    for(int i=1;i<stalls.size();i++){
        if((stalls[i] - place) >= mid){
            cow ++;
            place = stalls[i];
        }
        if(cow == k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    int ans = 0;
    sort(stalls.begin(),stalls.end());
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = (low + high)/2;
        if(place_cow(stalls, k, mid)){
            ans = max(ans,mid);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}
