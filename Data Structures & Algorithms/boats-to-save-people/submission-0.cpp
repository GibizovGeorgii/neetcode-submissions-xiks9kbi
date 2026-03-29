class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int left = 0; 
        int right = people.size() - 1;
        int result = 0;

        while (left <= right) {
            if (left == right) {
                result++;
                break;
            }
            if (people[left] + people[right] <= limit) {
                result++;
                left++;
                right--;
            } else if (people[left] >= people[right]) {
                result++;
                left++;
            } else {
                result++;
                right--;
            }
        }
        return result;
    }
};