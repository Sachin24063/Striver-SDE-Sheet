class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        if(n > m) return kthElement(arr2, arr1, m, n, k);

        int low =max(0, k-m), high = min(k,n);
        while(low <= high){
            int cut1 = (low+high)/2; //partition1
            int cut2 = k - cut1; //partition 2
            
            int left1,left2,right1,right2;

            if(cut1 == 0) left1 = INT_MIN;
            else left1 = arr1[cut1-1];

            if(cut2 == 0) left2 = INT_MIN;
            else left2 = arr2[cut2-1];

            if(cut1 == n) right1 = INT_MAX;
            else right1 = arr1[cut1];

            if(cut2 == m) right2 = INT_MAX;
            else right2 = arr2[cut2];

            if(left1 <= right2 && left2 <= right1){
                    return max(left1, left2);
             }
             else if(left1 > right2){
                 high = cut1-1;
             }
             else{
                 low = cut1+1;
             }
        }
             return 1;
    }
};
