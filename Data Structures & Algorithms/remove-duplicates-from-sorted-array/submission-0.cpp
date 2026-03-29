class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }

        int l = 0; 
        int r = 1;

        while (r < nums.size()) {
            if (nums[l] == nums[r]) {
                r++;
            } else {
                l++;
                nums[l] = nums[r];
                r++;
            }
        }
        return l + 1;
    }
};