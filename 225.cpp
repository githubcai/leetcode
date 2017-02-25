class MyStack {
    queue<int> que1, que2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(que1.empty()){
            que1.push(x);
            while(!que2.empty()){
                que1.push(que2.front());
                que2.pop();
            }
        }else{
            que2.push(x);
            while(!que1.empty()){
                que2.push(que1.front());
                que1.pop();
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!que1.empty()){
            int temp = que1.front();
            que1.pop();
            return temp;
        }
        int temp = que2.front();
        que2.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if(!que1.empty()) return que1.front();
        return que2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty() && que2.empty();
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
