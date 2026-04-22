class Solution {
    int n, m;
    vector<int> dr{1,-1,0,0};
    vector<int> dc{0,0,1,-1};

    void bfs(queue<pair<int,int>>& q,
             vector<vector<int>>& vis,
             vector<vector<int>>& h) {

        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (int k=0;k<4;k++) {
                int nr=r+dr[k], nc=c+dc[k];
                if (nr<0||nc<0||nr>=n||nc>=m) continue;
                if (vis[nr][nc]) continue;
                if (h[nr][nc] < h[r][c]) continue;
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
    }

    void initPacific(queue<pair<int,int>>& q, vector<vector<int>>& vis) {
        for (int i=0;i<n;i++) {
            vis[i][0]=1;
            q.push({i,0});
        }
        for (int j=0;j<m;j++) {
            vis[0][j]=1;
            q.push({0,j});
        }
    }

    void initAtlantic(queue<pair<int,int>>& q, vector<vector<int>>& vis) {
        for (int i=0;i<n;i++) {
            vis[i][m-1]=1;
            q.push({i,m-1});
        }
        for (int j=0;j<m;j++) {
            vis[n-1][j]=1;
            q.push({n-1,j});
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pac(n, vector<int>(m));
        vector<vector<int>> atl(n, vector<int>(m));
        queue<pair<int,int>> qp, qa;

        initPacific(qp, pac);
        initAtlantic(qa, atl);

        bfs(qp, pac, heights);
        bfs(qa, atl, heights);

        vector<vector<int>> ans;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i,j});

        return ans;
    }
};