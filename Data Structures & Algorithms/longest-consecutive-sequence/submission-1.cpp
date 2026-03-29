class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> hash_nums;

        if (nums.empty()) {
            return 0;
        }
        
        hash_nums.insert(nums.begin(), nums.end());

        int answer = 1;
        for (auto number : nums) {
            if (hash_nums.find(number - 1) != hash_nums.end()) {
                continue;
            } 

            int len = 1;
            while (hash_nums.find(number + 1) != hash_nums.end()) {
                len++;
                number++;
            }
            answer = std::max(answer, len);
        }

        return answer;
    }
};
