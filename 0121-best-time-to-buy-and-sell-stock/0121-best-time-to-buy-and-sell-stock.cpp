class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_buy = prices[0];
        int maximum = 0;

        for (int i = 1; i < prices.size(); i++) {
            curr_buy = min(curr_buy, prices[i]);
            int profit = prices[i] - curr_buy;
            maximum = max(maximum, profit);
        }

        return maximum;
    }
};