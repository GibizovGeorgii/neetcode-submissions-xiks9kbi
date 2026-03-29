class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::map<int, int> freqs;

        for (auto num : nums) {
            freqs[num]++;
        }

        std::vector<int> answer;
        if (freqs.empty()) {
            return answer;
        }

        if (freqs.size() == 1) {
            answer.push_back(nums[0]);
            return answer;
        } 

        
        int cand1, cand2;
        int freq1 = 0, freq2 = 0;
        for (auto it = freqs.begin(); it != freqs.end(); ++it) {
            if (it->second >= freq1) {
                freq2 = freq1; 
                cand2 = cand1;
                freq1 = it->second;
                cand1 = it->first;
            } else if (it->second >= freq2) {
                freq2 = it->second;
                cand2 = it->first;
            }
        }

        if (freq2 > nums.size() / 3) {
            answer.push_back(cand2);
        }

        if (freq1 > nums.size() / 3) {
            answer.push_back(cand1);
        }

        return answer;
    }
};