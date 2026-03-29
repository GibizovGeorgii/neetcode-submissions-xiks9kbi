class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::map<int, int> freqs;
        freqs.insert({0, 1});

        int prefix_sum = 0;
        int result = 0;
        for (int num : nums) {
            prefix_sum += num;
            if (freqs.contains(prefix_sum - k)) {
                result += freqs[prefix_sum - k];
            }
            freqs[prefix_sum]++;
        }

        return result;
    }
};