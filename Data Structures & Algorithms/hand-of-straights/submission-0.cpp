class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        vector<pair<int, int>> arr;
        unordered_map<int, int> m;
        for(int i : hand){
            m[i]++;
        }
        for(auto &[a, b]: m){
            arr.push_back({a, b});
        }
        sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first; // this sorts in ascending order
        });
        int i = 0;
        while(i < arr.size()){
            arr[i].second--;
            for(int j = 1; j < groupSize; j++) {
                if(i+j >= arr.size()){
                    return false;
                }
                if(arr[i+j].second == 0 || arr[i+j-1].first + 1 != arr[i+j].first) {
                    return false;
                }
                arr[i+j].second--;
            }

            while(i < arr.size() && arr[i].second == 0){
                i++;
            }
        }
        return true;
    }
};
