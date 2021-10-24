class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        int ans = 0;
        
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] > amount) {
                continue;
            } 
            dp[coins[i]] = 1;
        }
        
        for (int i = 1; i <= amount; i++) {
            if (dp[i] != 0) {
                continue;
            }
            
            int val = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                int tmp = INT_MAX;
                if (i < coins[j]) {
                    continue;
                } else if (i == coins[j]) {
                    tmp = dp[i];
                } else {
                    if (dp[i - coins[j]] == -1) {
                        continue;
                    }
                    tmp = dp[i - coins[j]];
                }
                
                val = min(tmp, val); 
            }
            
            if (val == INT_MAX) {
                dp[i] = -1;
            } else {
                dp[i] = val + 1;
            }
        }
        
        return dp[amount];
    }
};