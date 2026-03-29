class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = 1;
        int n = height.size();
        int result = 0;

        if (n < 3) {
            return 0;
        }

        while (right < n) {
            while (left + 1 < n and height[left] <= height[left + 1]) {
                left++;
            }

            int sum = 0;
            right = left + 1;

            while (right < n and height[right] < height[left] ) {
                sum += height[left] - height[right];
                right++;
            }
            if (right != n) {
                result += sum;
                left = right;
            } else {
                break;
            }
        }
        
        right = n - 1;
        left = n - 2;
        while (left >= 0) {
            while (right - 1 >= 0 and height[right] <= height[right - 1]) {
                right--;
            }

            int sum = 0;
            left = right - 1;

            while (left >= 0 and height[left] <= height[right] ) {
                sum += height[right] - height[left];
                left--;
            }
            if (left != -1) {
                result += sum;
                right = left;
            } else {
                break;
            }
        }
        
        
        return result;
    }
};