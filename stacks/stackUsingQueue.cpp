#include <stack>
class MyStack {
private: 
    queue<int> stack;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack.push(x);
        for(int iterator = 0; iterator < stack.size() - 1; iterator++) {
            int element = stack.front();
            stack.push(element);
            stack.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int element = stack.front();
        stack.pop();
        return element;
    }
    
    /** Get the top element. */
    int top() {
        return stack.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
       return stack.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
