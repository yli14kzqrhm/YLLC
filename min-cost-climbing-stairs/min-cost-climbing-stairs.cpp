class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp2 = min(cost[1], cost[0]);
        if (cost.size() == 2) {
            return dp2;
        } 

        int dp3 = min(cost[1], cost[2] + dp2);
        if (cost.size() == 3) {
            return dp3;
        } 
        
        int ans;
        
        for (int i = 4; i <= cost.size(); i++) {
            ans = min(cost[i-2] + dp2, cost[i-1] + dp3);
            dp2 = dp3;
            dp3 = ans;
        }
        
        return ans;
    }
};