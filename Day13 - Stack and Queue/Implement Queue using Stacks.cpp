class MyQueue {
public:
    stack<int>st,st1;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
       if(st1.empty()){
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
       }
        int ans = st1.top();
        st1.pop();
        return ans;
    }
    
    int peek() {
        if(st1.empty()){
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        }
        return st1.top();
    }
    
    bool empty() {
        return (st.empty() && st1.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
