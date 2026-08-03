class Solution {
public:
    static bool myfunction (vector<int>& x, vector<int>& y) { 
        if(x[0] == y[0]){
            return x[1] < y[1];
        }
        return x[0] < y[0]; 
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), myfunction);
        int start = intervals[0][0];
        int i = 0;
        vector<vector<int>> newInts;
        while(i < intervals.size()){
            start = intervals[i][0];
            newInts.push_back(intervals[i]);
            while(i < intervals.size() && intervals[i][0] == start){
                i++;
            }
            
        }
        int erased = intervals.size() - newInts.size();
        // cout << erased << endl;
        i = 1;
        int end = newInts[0][1];
        while(i < newInts.size()){
            if(end > newInts[i][0]){
                erased++;
                end = min(end, newInts[i][1]);
            }
            else{
                end = newInts[i][1];
            }
            i++;
        }
        return erased;
    }
};
