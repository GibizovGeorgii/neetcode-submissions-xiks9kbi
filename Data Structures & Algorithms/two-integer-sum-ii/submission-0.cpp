class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            while (nums[left] + nums[right] < target) {
                left++;
            }
            while (nums[left] + nums[right] > target) {
                right--;
            }
            if (nums[left] + nums[right] == target) {
                break;
            }
        }

        std::vector<int> result {left + 1, right + 1};
        return result;
    }
};
