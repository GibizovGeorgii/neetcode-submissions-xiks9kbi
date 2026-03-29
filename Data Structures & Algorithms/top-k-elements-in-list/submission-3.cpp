class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        for (auto number : nums) {
            freqMap[number]++;
        }

        std::vector<int> answer;
        std::map<int, std::vector<int>, std::greater<int>> freqGroups;
        for (auto [key, value] : freqMap) {
            freqGroups[value].push_back(key);
        }

        for (auto it = freqGroups.begin(); k > 0 and it != freqGroups.end(); k -= std::size(it->second), it++) {
            answer.insert(answer.end(), (it->second).begin(), (it->second).end());
        }
        return answer;
    }
};
