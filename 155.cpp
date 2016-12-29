class MinStack {
    stack<int> st, mSt;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(mSt.empty()){
            mSt.push(x);
        }else{
            if(mSt.top() >= x) mSt.push(x);
        }
    }
    
    void pop() {
        if(mSt.top() == st.top()) mSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mSt.top();
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
