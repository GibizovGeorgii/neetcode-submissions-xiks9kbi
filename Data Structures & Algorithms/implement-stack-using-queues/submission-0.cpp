class MyStack {
    std::queue<int> my_stack;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        my_stack.push(x);
    }
    
    int pop() {
        int x = my_stack.back();
        int size = my_stack.size();
        for (int i = 0; i < size - 1; i++) {
            int temp = my_stack.front();
            my_stack.pop();
            my_stack.push(temp);
        }
        my_stack.pop();
        return x;
    }
    
    int top() {
        return my_stack.back();
    }
    
    bool empty() {
        return my_stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */