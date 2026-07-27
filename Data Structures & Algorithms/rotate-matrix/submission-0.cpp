class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int j = 0; j < matrix.size()/2; j++){
            matrix[j].swap(matrix[matrix.size()-j-1]);
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix.size(); j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
