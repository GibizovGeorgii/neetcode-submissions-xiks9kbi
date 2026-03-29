class Solution {
public:
    int NOD(int a, int b) {
        int max = std::sqrt(a);
        int nod = 1;
        for (int i = 1; i <= max; i++) {
            if (a % i == 0) {
                if (b % (a / i) == 0) {
                    return a / i;
                }
                if (b % i == 0) {
                    nod = i;
                }
            }
        }
        return nod;
    }

    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int step = NOD(size, k);
        if (k % size == 0) {
            return;
        }

        for (int i = 0; i < step; i++) {
            int temp = nums[i];
            for (int j = 1; j <= size / step; j++) {
                std::swap(temp, nums[(i + j * k) % size]);
            }
        }
    }
};
