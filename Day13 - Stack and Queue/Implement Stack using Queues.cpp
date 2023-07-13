class MyStack {
public:
    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        // // step 1 push all the elements of q1 into q2
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // //push element x into empty queue q1
        // q1.push(x);
        // //now push all the elements of q2 in q1
        // while(!q2.empty()){
        //     q1.push(q2.front());
        //     q2.pop();
        // }
        q1.push(x);
    }
    
    int pop() {
        int size=q1.size();
        while(size > 1){
            q1.push(q1.front());
            q1.pop();
            size--;
        }
    int n = q1.front();
        q1.pop();
        return n;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return(q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
