class Solution {
public:
    int search(vector<int>& a, int t) {
        int n=a.size();
        int low=0, high=a.size()-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(t==a[mid]){
                return mid;
            }
            else{
                if(a[low]<=a[mid]){
                    if(t>=a[low] && t<=a[mid]){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                else{
                    if(t>=a[mid] && t<=a[high]){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
            }
        }
        return -1;
    }
};
