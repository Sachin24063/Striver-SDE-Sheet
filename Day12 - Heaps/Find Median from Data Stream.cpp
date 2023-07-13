class MedianFinder {
public:
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty() && min_heap.empty()){
             max_heap.push(num);
        }
        else{
            if(max_heap.top() < num) 
                min_heap.push(num);
            else max_heap.push(num);
        }
    }
    
    double findMedian() {
        if(max_heap.empty() && min_heap.empty()) return 0.0;

        if(max_heap.size() == min_heap.size()){
            return ((double)max_heap.top() + (double)min_heap.top())/2.0;
        }
        else if(max_heap.size() == min_heap.size()+1){
            return (double)max_heap.top();
        }
        else if(max_heap.size()+1 == min_heap.size()){
            return (double)min_heap.top();
        }
        else if(max_heap.size() > min_heap.size()+1){
            int ele = max_heap.top();
            max_heap.pop();
            min_heap.push(ele);
           return findMedian();
        }
        else if(max_heap.size()+1 < min_heap.size()){
            int ele = min_heap.top();
            min_heap.pop();
            max_heap.push(ele);
           return findMedian();
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
