#include <stack>
 
class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> originalStack; 
    std::stack<int> minStack;
    
    void push(int x) {
        originalStack.push(x);
        if(minStack.empty() || minStack.top() >= x) {
            minStack.push(x);
        }
    }
    
    void pop() {
        if(originalStack.top() == minStack.top()) {
            minStack.pop();
        }
        originalStack.pop();
    }
    
    int top() {
        return originalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
