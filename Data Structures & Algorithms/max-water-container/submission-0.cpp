class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; 
        int right = heights.size() - 1;

        int area = std::min(heights[left], heights[right]) * (heights.size() - 1);

        for (; left + 1 < right;) {
            if (heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
            area = std::max(area, std::min(heights[left], heights[right]) * (right - left));
        }

        return area;
    }
};
