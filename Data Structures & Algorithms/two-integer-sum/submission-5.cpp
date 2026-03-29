#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::multimap<int, int> indices;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
                indices.insert({nums[i], i});
        }

        int i, j;
        std::vector<int> solution;
        for (auto element = indices.begin(); element != indices.end(); element++) {
            i = element->second;
            if (target - element->first == element->first) {
                indices.erase(element);
            }
            if (indices.contains(target - element->first)) {
                j = indices.find(target - element->first)->second;
                break;
            }
        }

        solution.push_back(i);
        solution.push_back(j);
        std::sort(solution.begin(), solution.end());

        return solution;
    }
};
