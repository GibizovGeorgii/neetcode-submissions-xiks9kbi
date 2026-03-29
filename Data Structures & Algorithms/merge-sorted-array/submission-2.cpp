class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r1 = m - 1; // указывает на последний ненулевой элемент первого массива
        int it1 = n + m - 1; // указывает на текущий элемент первого массива
        int it2 = n - 1; // указывает на текущий элемент второго массива

        while (it2 >= 0) {
            if (r1 < 0) {
                while (it2 >= 0) {
                    nums1[it1] = nums2[it2];
                    it2--;
                    it1--;
                }
                return;
            }

            while (it2 >= 0 and nums2[it2] >= nums1[r1]) {
                nums1[it1] = nums2[it2];
                it1--;
                it2--;
            }

            while (r1 >= 0 and nums2[it2] <= nums1[r1]) {
                std::swap(nums1[it1], nums1[r1]);
                it1--;
                r1--;
            }
        }
    }
};