class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<std::pair<int, int>> last_temp;
        
        int tmp_size = temperatures.size();
        for (int i = 0; i < tmp_size; ++i) {
            if (last_temp.empty()) {
                last_temp.push({temperatures[i], i});
            } else {
                while (!last_temp.empty() and temperatures[i] > last_temp.top().first) {
                    temperatures[last_temp.top().second] = i - last_temp.top().second;
                    last_temp.pop();
                }
                last_temp.push({temperatures[i], i});
            }
        }

        while (!last_temp.empty()) {
            temperatures[last_temp.top().second] = 0;
            last_temp.pop();
        }
        return temperatures;
    }
};
