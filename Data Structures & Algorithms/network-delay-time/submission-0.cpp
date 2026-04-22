class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj = buildGraph(times, n);
        vector<int> dist = dijkstra(adj, n, k);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }

private:
    static const int INF = 1e9;

    vector<vector<pair<int,int>>> buildGraph(vector<vector<int>>& times, int n) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        return adj;
    }

    vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int n, int src) {
        vector<int> dist(n + 1, INF);
        set<pair<int,int>> st;

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());

            int d = it.first, u = it.second;

            for (auto &edge : adj[u]) {
                int v = edge.first, w = edge.second;

                if (d + w < dist[v]) {
                    if (dist[v] != INF) st.erase({dist[v], v});
                    dist[v] = d + w;
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
    }
};