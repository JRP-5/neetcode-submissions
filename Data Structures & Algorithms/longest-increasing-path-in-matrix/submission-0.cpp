class Solution {
public:
    const vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> paths(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(paths[i][j] == -1){
                    explore(matrix, paths, i, j);
                }
            }   
        }
        int maxPath = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                maxPath = max(maxPath, paths[i][j]);
            }   
        }
        return maxPath;
    }
    void explore(vector<vector<int>>& matrix, vector<vector<int>>& paths, int x, int y){
        int maxPath = 0;
        for(pair<int, int> dir : dirs){
            int a = x + dir.first;
            int b = y + dir.second;
            if( a>= 0 && b>=0 && a < matrix.size() && b < matrix[0].size() && matrix[x][y] < matrix[a][b]){
                if(paths[a][b] == -1){
                    explore(matrix, paths, a, b);
                }
                maxPath = max(maxPath, paths[a][b]);
    
            }
        }
        paths[x][y] = maxPath+1;
    }
};
