class MinStack {
private:
    stack<int>st;
    stack<int>minStack;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minStack.size()){
            val = min(val, minStack.top());
        }
        minStack.push(val);
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
