class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int maxArea = 0;
         for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, bfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
    int bfs(vector<vector<int>>& grid, int a, int b){
        int area = 0;
        queue<pair<int, int>> q;
        q.push({a, b});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(x >=0 && y >=0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                grid[x][y] = 0;
                area++;
                q.push({x-1, y});
                q.push({x+1, y});
                q.push({x, y-1});
                q.push({x, y+1});
            }
        }
        return area;
    }
};
