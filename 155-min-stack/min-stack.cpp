class MinStack {
    stack<long long> st;
    long long min;
public:
    MinStack() {}

    void push(int value) {
        if (st.empty()){
            st.push(value);
            min=value;
        }
        else if(value<min){
            st.push(2LL*value-min);
            min=value;
        }
        else{
            st.push(value);
        }
        
    }

    void pop() {
        if (st.top()<min){
            long long t= st.top();
            st.pop();
            min=min*2-t;
        }else{st.pop();}
    }

    int top() { return st.top()<min ? (int)min : (int)st.top(); }

    int getMin() { return (int)min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */