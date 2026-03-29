#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> results;

        int n = nums.size();
        if (nums[0] > 0 or nums[n - 1] < 0) {
            return results;
        }

        int nulls = 0;
        for (auto num : nums) {
            if (num == 0) {
                nulls++;
            }
            if (num > 0) {
                break;
            }
        }
        if (nulls >= 3) {
            results.push_back({0, 0, 0});
        }

        int left = 0; 
        int right = n - 1;
        int middle; 

        while (nums[left] < 0) {
            middle = left + 1;
            right = n - 1;
            while (nums[left] + nums[middle] <= 0 and right > middle) {
                while (nums[left] + nums[middle] + nums[right] > 0 and right > middle) {
                    right--;
                }

                if (nums[left] + nums[middle] + nums[right] == 0 and right > middle) {
                    results.push_back({nums[left], nums[middle], nums[right]});
                } 

                if (nums[middle] == nums[middle + 1]) {
                    middle++;
                    while (middle < right and nums[middle - 1] == nums[middle]) {
                        middle++;
                    }
                } else {
                    middle++;
                }
            }
            if (nums[left + 1] == nums[left]) {
                left++;
                while (nums[left] == nums[left - 1]) {
                    left++;
                }
            } else {
                left++;
            }
        }
        return results;
    }
    
};
