class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        
        dp[2] = min(cost[0], cost[1]);
        
        if (n == 2) {
            return dp[2];
        }
        
        dp[3] = min(dp[2] + cost[2], cost[1]);
        
        if (n == 3) {
            return dp[3];
        }
        
        for (int i = 4; i <= n; i++) {
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i - 2]);
        }
        
        return dp[n];
    }
};