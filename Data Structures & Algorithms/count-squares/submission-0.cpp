class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    int findSquare(vector<int> point, int side, int y){
        int multiplier = mp[point[0]][y];
        if(mp.find(point[0] + side) != mp.end()){
            // cout << point[0] << " " << point[1] << endl;
            // cout << y << endl;
            if(mp[point[0] + side].find(y) != mp[point[0] + side].end()){
                multiplier *= mp[point[0] + side][y];
                // cout << "Here \n";
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
        if(mp.find(point[0] + side) != mp.end()){
            if(mp[point[0] + side].find(point[1]) != mp[point[0] + side].end()){
                multiplier *= mp[point[0] + side][point[1]];
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
        return multiplier;
    }
    int count(vector<int> point) {
        if(mp.find(point[0]) == mp.end()){
            return 0;
        }
        unordered_map<int, int> m1 =  mp[point[0]];
        int ans = 0;
        for(const auto &[y, count]: m1){
            if(y == point[1]){
                continue;
            }
            ans += findSquare(point, y - point[1], y);
            ans += findSquare(point, point[1] - y, y);

        }
        return ans;
    }
};
