class MinStack {
    stack<int> st, s;

public:
    MinStack() {}

    void push(int value) {
        st.push(value);
        if (s.empty() || value <= s.top())
            s.push(value);
    }

    void pop() {
        if (st.top() == s.top())
            s.pop();
        st.pop();
    }

    int top() { return st.empty() ? -1 : st.top(); }

    int getMin() { return s.empty() ? -1 : s.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */