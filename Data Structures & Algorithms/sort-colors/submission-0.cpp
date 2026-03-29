class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hmap[3] = {0, 0, 0};
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            hmap[nums[i]]++;
        }

        int j = 0;
        for (int i = 0; i < 3; ++i) {
            for (int k = 0; k < hmap[i]; ++k, ++j) {
                nums[j] = i;
            }
        }
    }
};