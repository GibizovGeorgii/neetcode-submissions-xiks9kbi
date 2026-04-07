class MyQueue {
    std::stack<int> first;
    std::stack<int> second;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        first.push(x);    
    }
    
    int pop() {
        if (second.empty()) {
            while (!first.empty()) {
                second.push(first.top());
                first.pop();
            }
        }
        int temp = second.top();
        second.pop();
        return temp;
    }
    
    int peek() {
        if (second.empty()) {
            while (!first.empty()) {
                second.push(first.top());
                first.pop();
            }
        }
        return second.top();
    }
    
    bool empty() {
        if (first.empty() and second.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */