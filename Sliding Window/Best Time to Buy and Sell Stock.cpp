class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell_price = prices.back();
        int n = prices.size() , ans = 0;
        for(int j = n - 2; j >= 0; j--) {
            int profit = sell_price - prices[j];
            if(profit > ans) ans = profit;
            if(sell_price < prices[j]) sell_price = prices[j];
        }
        return ans;
    }
};
