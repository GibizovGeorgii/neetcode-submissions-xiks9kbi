class FreqStack {
    std::vector<int> mainStack;
    std::map<int, std::unordered_set<int>, std::greater<int>> freqLevels;
    std::map<int, int> freqs;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
		mainStack.push_back(val);
        if (!freqs.contains(val)) {
            freqs[val]++;
            freqLevels[1].insert(val);
        } else {
            freqLevels[freqs[val]].erase(val);
            if (freqLevels[freqs[val]].empty()) {
                freqLevels.erase(freqs[val]);
            }
			freqs[val]++;
            freqLevels[freqs[val]].insert(val);
        }
    }
    
    int pop() {
		int n = mainStack.size();
		int val;
        for (int i = n - 1; i >= 0; i--) {
			val = mainStack[i];
            if ((freqLevels.begin())->second.contains(val)) {
				freqs[val]--;
				if (freqs[val] == 0) {
					freqs.erase(val);
				}

				int top_freq = freqLevels.begin()->first;
                freqLevels[top_freq].erase(val);
                if (freqLevels[top_freq].empty()) {
                    freqLevels.erase(top_freq);
                }
				if (top_freq > 1) {
					freqLevels[top_freq - 1].insert(val);
				}
				mainStack.erase(mainStack.begin() + i);
				break;
            }
        }
		return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */