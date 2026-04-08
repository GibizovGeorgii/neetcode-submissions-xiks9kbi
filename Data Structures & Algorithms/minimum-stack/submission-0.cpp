class MinStack {
    std::stack<int> gen_st;
    std::stack<int> min_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (min_st.empty() or val <= min_st.top()) {
            min_st.push(val);
        }
        gen_st.push(val);
    }
    
    void pop() {
        if (min_st.top() == gen_st.top()) {
            min_st.pop();
        }
        gen_st.pop();
    }
    
    int top() {
        return gen_st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
