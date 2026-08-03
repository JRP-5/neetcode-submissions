class Solution {
public:
    void dump(vector<vector<int>>& arr){
        for(int i = 0; i < arr.size(); i++){  
            for(int j = 0; j < arr[0].size(); j++){
                cout << arr[i][j] <<  " ";
            }
            cout << endl;    
        }       
    }

    int numDistinct(string s, string t) {
        if(s.size() < t.size()){
            return 0;
        }
        vector<vector<int>> arr(t.size(), vector<int>(s.size(), 0));
        
        arr[0][0] = s.at(0) == t.at(0);
        
        for(int j = 1; j < s.size(); j++){
            if(s.at(j) == t.at(0)){
                arr[0][j] = arr[0][j-1] + 1;
            }
            else{
                arr[0][j] = arr[0][j-1];
            }
        }
        for(int i = 1; i < t.size(); i++){  
            arr[i][i] = arr[i-1][i-1] && t.at(i)==s.at(i);
            for(int j = i+1; j < s.size(); j++){
                if(s.at(j) == t.at(i)){
                    arr[i][j] = arr[i][j-1] + arr[i-1][j-1];
                }
                else{
                    arr[i][j] = arr[i][j-1];
                }
            }
        }
        // dump(arr);
        return arr[t.size()-1][s.size()-1];
    }
};
