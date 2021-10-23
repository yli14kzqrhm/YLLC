class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int,int>> s;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && (temperatures[i] >= s.top().first)) {
                s.pop();
            }
            
            ans[i] = (s.empty() ? 0 : (s.top().second - i));
            
            s.push({temperatures[i], i});
        }
        
        return ans;
    }
};