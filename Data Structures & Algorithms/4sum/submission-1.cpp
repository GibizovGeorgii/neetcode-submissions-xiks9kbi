class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums , int target) {
        int a, b, c, d;
        std::vector<std::vector<int>> result;
        int size = nums.size();

        // если размер массива меньше 4, ответов нет
        if (nums.size() < 4) {
            return result;
        }

        // сортируем массив
        std::sort(nums.begin(), nums.end());

        a = 0;
        while (a < size - 3) {
            b = a + 1;
            while (b < size - 2) {
                c = b + 1;
                while (c < size - 1) {
                    d = size - 1;
                    
                    while (c < d) {
                        long long sum = static_cast<long long>(nums[a]) + nums[b] + nums[c] + nums[d];
                        if (sum > target) {
                            d--;
                        } else if (sum < target) {
                            c++;
                        } else {
                            result.push_back({nums[a], nums[b], nums[c], nums[d]});
                            break;
                        }
                    }
                    
                    
                    if (nums[c] == nums[c + 1]) {
                        c++;
                        while (c < size - 1 and nums[c] == nums[c - 1]) {
                            c++;
                        }
                    } else {
                        c++;
                    }
                }
                
                if (nums[b] == nums[b + 1]) {
                    b++;
                    while (b < size - 2 and nums[b] == nums[b - 1]) {
                        b++;
                    }
                } else {
                    b++;
                }
            }

            if (nums[a] == nums[a + 1]) {
                a++;
                while (a < size - 3 and nums[a] == nums[a - 1]) {
                    a++;
                }
            } else {
                a++;
            }
        }
        return result;
    }
};


