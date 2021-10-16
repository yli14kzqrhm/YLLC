class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        
        vector<int> ans;
        
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                ans.push_back(i);
            }
        }
        
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < adj[ans[i]].size(); j++) {
                if ((--in[adj[ans[i]][j]]) == 0) {
                    ans.push_back(adj[ans[i]][j]);
                }
            }
        }
        
        if (ans.size() != numCourses) {
            return {};
        } else {
            return ans;
        }
    }
};