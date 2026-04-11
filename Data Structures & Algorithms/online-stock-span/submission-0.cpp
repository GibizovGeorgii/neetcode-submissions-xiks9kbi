class StockSpanner {
    std::stack<int> prev;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int counter = 1;
        while (!prev.empty() and std::abs(prev.top()) <= price) {
            if (prev.top() > 0) {
                counter++;
                prev.pop();
            } else {
                prev.pop();
                counter += -prev.top();
                prev.pop();
            }
        }
        if (counter > 1) {
            prev.push(-counter);
            prev.push(-price);
        } else {
            prev.push(price);
        }
        return counter;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */