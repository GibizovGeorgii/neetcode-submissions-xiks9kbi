#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniq;

        
        for (auto number : nums) {
            if (uniq.contains(number)) {
                return true;
            } else {
                uniq.insert(number);
            }
        }
        return false;
    }
};