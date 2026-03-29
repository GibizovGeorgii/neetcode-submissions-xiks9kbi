class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }
        int n = prices.size();
        int day = 0;
        int profit = 0;
        while (day < n - 1) {
            while (prices[day] >= prices[day + 1] and day < n - 1) {
                day++;
            }
            if (day == n - 1) {
                return profit;
            }
            profit -= prices[day];
            while (prices[day] <= prices[day + 1] and day < n - 1) {
                day++;
            }
            profit += prices[day];
        }
    }
};