class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        std::vector<int> answer(n);
        answer[0] = 1;
        answer[1] = nums[0];
        for (int i = 2; i < n; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        
        int mul = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            answer[i] *= mul;
            mul *= nums[i];
        }

        return answer;
    }
};
