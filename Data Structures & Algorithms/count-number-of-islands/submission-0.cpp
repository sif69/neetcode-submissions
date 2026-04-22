class Solution {
public:
    int dR[4] = {0,0,-1,1};
    int dC[4] = {-1,1,0,0};

    void dfs(int r,int c,vector<vector<char>>& grid,
             vector<vector<int>>& vis,int n,int m){

        vis[r][c]=1;

        for(int k=0;k<4;k++){
            int p=r+dR[k];
            int q=c+dC[k];

            if(p>=0 && p<n && q>=0 && q<m &&
               !vis[p][q] && grid[p][q]=='1'){
                dfs(p,q,grid,vis,n,m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};