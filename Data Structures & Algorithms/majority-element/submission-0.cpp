class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freqs;
        for (const int& number: nums) {
            freqs[number]++;
        }

        int max = 0;
        int answer;
        for (const auto& [number, frequency] : freqs) {
            if (frequency > max) {
                max = frequency;
                answer = number;
            }
        }

        return answer;
    }
};