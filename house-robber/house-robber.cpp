class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        } else if (n == 3) {
            return max(nums[0] + nums[2], nums[1]);
        }
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + dp[0];
        for (int i = 3; i < n; i++) {
            dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
        }
        
        return max(dp[n-1], dp[n-2]);
    }
};