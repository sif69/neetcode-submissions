class Solution {
public:

    int i,j;
    int ver[4] = {-1, 1, 0, 0};
    int hor[4] = {0, 0, -1, 1};
    
    bool check(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        

        int n = grid.size() , m = grid[0].size();


        int freshness = 0;


        queue<pair<int,int>>q;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    freshness++;
                }
            }
        }

        int minutes = 0,l,r,newX,newY;
        while(!q.empty()){
            int sz = q.size();

            for(j=0;j<sz;j++){
                auto[x,y] = q.front();
                q.pop();
                for(i=0;i<4;i++){
                    newX = x + ver[i];
                    newY = y + hor[i];
                    if(check(grid,newX,newY) && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        q.push({newX,newY});
                        freshness--;
                    }
                }
               
            }
             if(q.size()) minutes++;
                
        }

        return freshness == 0?minutes:-1;


    }
};
