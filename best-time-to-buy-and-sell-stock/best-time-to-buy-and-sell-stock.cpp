class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buy = 0, sell = 0;
        

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[buy]) {
                buy = i;
                sell = buy;
            }
            
            if (prices[i] > prices[sell]) {
                sell = i;
            }
            
            if (buy < sell) {
                ans = max(ans, prices[sell] - prices[buy]);
            }
        }
        
        
        return ans;
    }
};