class Solution {
public:
    bool dfs(int node, int par,
             vector<vector<int>>& adj,
             vector<bool>& vis) {

        if (vis[node]) return true;

        vis[node] = true;

        for (auto child : adj[node]) {
            if (child == par) continue;
            if (dfs(child, node, adj, vis)) return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(n + 1, false);

            if (dfs(u, -1, adj, vis)) {
                return {u, v};
            }
        }
        return {};
    }
};