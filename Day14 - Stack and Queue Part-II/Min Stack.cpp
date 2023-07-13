class MinStack {
public:
    stack<int>st;
    stack<int>min_ele;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min_ele.empty() || val <= min_ele.top()) min_ele.push(val);
    }
    
    void pop() {
        int n = st.top();
        st.pop();
        if(min_ele.top() == n) min_ele.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_ele.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
