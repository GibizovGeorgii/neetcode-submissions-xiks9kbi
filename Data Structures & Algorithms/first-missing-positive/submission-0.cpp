class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num : nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (auto num : nums) {
            if (std::abs(num) <= n and nums[std::abs(num) - 1] > 0) {
                nums[std::abs(num) - 1] *= -1;
            }
        }

        int result = 1;
        for (auto num : nums) {
            if (num < 0) {
                result++;
            } else {
                break;
            }
        }

        return result;
    }
};