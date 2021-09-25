class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) {
            return n;
        } else if (n == 2) {
            return 1;
        }
        
        int ans, s0 = 0, s1 = 1, s2 = 1;
        
        for (int i = 3; i <= n; i++) {
            ans = s0 + s1 + s2;
            s0 = s1;
            s1 = s2;
            s2 = ans;
        }
        
        return ans;
    }
};