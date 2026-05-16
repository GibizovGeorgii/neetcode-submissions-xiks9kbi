class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> largest_left;
        int n = heights.size();
        int max_space = 0;

        for (int i = 0; i <= n; i++) {
            while (!largest_left.empty() and (i == n or heights[largest_left.top()] >= heights[i])) {
                int top_ind = largest_left.top();
                largest_left.pop();
                int h;
                if (largest_left.empty()) {
                    h = i;
                } else {
                    h = i - largest_left.top() - 1;
                }
                max_space = std::max(max_space, heights[top_ind] * h);
            }
            largest_left.push(i);
        }

        return max_space;
    }
};
