class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Correct graph construction
        for (auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adj[prereq].push_back(course); // prereq → course
            indegree[course]++;           // course depends on prereq
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node);

            for (int nei : adj[node]) {
                if (--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (order.size() != numCourses) return {};
        return order;
    }
};