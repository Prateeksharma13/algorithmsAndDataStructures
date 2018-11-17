class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> one; 
    stack<int> two;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!two.empty()) {
            one.push(two.top());
            two.pop();
        }
        one.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!one.empty()) {
            two.push(one.top());
            one.pop();
        }
        int ret = two.top();
        two.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(!one.empty()) {
            two.push(one.top());
            one.pop();
        } 
        return two.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return one.empty() && two.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
