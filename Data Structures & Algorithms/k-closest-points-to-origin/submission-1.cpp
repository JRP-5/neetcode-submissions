class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return pow(a[0], 2) + pow(a[1], 2) < pow(b[0], 2) + pow(b[1], 2);
        };
        make_heap(points.begin(), points.end(), cmp);
        for(int i = points.size(); i > k; i--){
            pop_heap(points.begin(), points.end(), cmp);
            points.pop_back();
        }
        return points;
    }
};
