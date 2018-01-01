#include <queue>         
class MyStack {
private:
    queue<int> queueOriginal;
    queue<int> queueTemp;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queueOriginal.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int element;
        do {
            element = queueOriginal.front();
            queueOriginal.pop();
            if(!queueOriginal.empty()) {
                queueTemp.push(element);                 
            }
        }
        while(!queueOriginal.empty());
        swap(queueOriginal, queueTemp);
        return element;
    }
    
    /** Get the top element. */
    int top() {
        int element;
        while(!queueOriginal.empty()) {
            element = queueOriginal.front();
            queueOriginal.pop();            
            queueTemp.push(element); 
        }
        swap(queueOriginal, queueTemp);
        return element;
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queueOriginal.empty();
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
