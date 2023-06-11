class Solution {
public:
    void merge(vector<int>& nums, int low, int high, int mid, int& cnt){
        int j = mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]> 2 * (long long)nums[j]){
                j++;
            }
            cnt += (j-(mid+1));
        }
        
        int left = low, right = mid+1, k=0;
        vector<int> temp(high-low+1);
        while(left<=mid && right<=high){
            if(nums[left]<nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        
        while(left <= mid){
            temp[k++] = nums[left++];
        }
        
        while(right <= high){
            temp[k++] = nums[right++];
        }
        
        for(int i=low; i<=high;i++){
            nums[i] = temp[i-low];
        }
    }
    
    void merge_sort(vector<int>&nums, int low, int high, int& cnt){
        if(low<high){
            int mid = (high+low)/2;
            merge_sort(nums, low, mid, cnt);
            merge_sort(nums, mid+1, high, cnt);
            merge(nums, low, high, mid, cnt);
        }
    }
    
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        merge_sort(nums,0,nums.size()-1,cnt);
        return cnt;
    }
};
