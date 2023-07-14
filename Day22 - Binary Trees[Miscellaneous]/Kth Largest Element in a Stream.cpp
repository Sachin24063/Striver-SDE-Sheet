class KthLargest {
public:
int K;
priority_queue<int, vector<int>, greater<int>> min_heap;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i=0;i<nums.size();i++){
            min_heap.push(nums[i]); 
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        while(min_heap.size()>K){
            min_heap.pop();
        }
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
