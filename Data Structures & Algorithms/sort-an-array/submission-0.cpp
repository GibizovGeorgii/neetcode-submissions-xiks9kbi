class Solution {
public:
    int presort (vector<int>& nums, int l, int r, int d) {
        int i = l - 1;
        int j = r;

        for (;;) {
            while (nums[++i] < nums[d]);
            while (nums[j] > nums[d]) {
                if (j == l) {
                    break;
                }
                j--;
            }
            if (i >= j) {
                break;
            }
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[i], nums[d]);
        return i;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int d = presort(nums, l, r - 1, r);

        quickSort(nums, l, d - 1);
        quickSort(nums, d + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};