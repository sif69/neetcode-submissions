class Solution {
public:
    int ver[4] = {-1, 1, 0, 0};
    int hor[4] = {0, 0, -1, 1};
    
    bool check(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        // Base case: out of bounds or water or already visited
        if (!check(grid, x, y) || !grid[x][y]) {
            return 0;
        }
        
        // Mark as visited by setting to 0
        grid[x][y] = 0;
        
        // Count current cell
        int area = 1;
        
        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = x + ver[i];
            int newY = y + hor[i];
            area += dfs(grid, newX, newY);  // ✅ Recursive call
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    maxArea = max(maxArea, dfs(grid, i, j));  // ✅ No +1 needed
                }
            }
        }
        
        return maxArea;
    }
};