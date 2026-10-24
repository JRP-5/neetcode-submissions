class Solution {
public:
    void dump(vector<vector<int>> &arr){
        for(auto a: arr){
            for(auto b : a){
                cout << b << " ";
            }
            cout << endl;
        }
    }
    int minDistance(string word1, string word2) {
        if(word1.size() == 0){
            return word2.size();
        }
        if(word2.size() == 0){
            return word1.size();
        }
        vector<vector<int>> arr(word1.size(), vector<int>(word2.size()));
        if(word1[0] == word2[0]){
            arr[0][0] = 0;
            word1[0] = '-';
        }
        else {
            arr[0][0] = 1;
        }
        for(int j = 1; j < word2.size(); j++){
            if(word1[0] == word2[j]){
                arr[0][j]  = arr[0][j-1]; 
                word1[0] = '-';
            }
            else{
                arr[0][j]  = arr[0][j-1] + 1; 
            }
            
        }
        for(int i = 1; i < word1.size(); i++){
            if(word1[i] != word2[0]){
                arr[i][0] = arr[i-1][0] + 1;
            }
            else {
                arr[i][0] = arr[i-1][0];
            }
            for(int j = 1; j < word2.size(); j++){
                
                if(word1[i] != word2[j]){
                    arr[i][j] = min(min(arr[i-1][j], arr[i][j-1]), arr[i-1][j-1]) + 1;
                }
                else {
                    arr[i][j] = arr[i-1][j-1];
                }
            }
        }
        // dump(arr);
        return arr.back().back();
    }
};
