class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        int n = nums1.size() + nums2.size();
        int l = -1;
        int r = nums1.size()-1;
        while(l<=r){
            int i = floor((double)(r+l+1)/2);
            int j = (n+1)/2 - i-2;
            int aLeft = i>= 0 ? nums1[i] : INT_MIN;
            int aRight = i+1 < nums1.size() ? nums1[i+1] : INT_MAX;
            int bLeft = j>=0 ? nums2[j] : INT_MIN;
            int bRight = j+1 < nums2.size() ? nums2[j+1] : INT_MAX;
            // cout << aLeft <<"|" <<aRight<< " " << bLeft << "|" << bRight << endl;
            if(aLeft > bRight) {
                r = i-1;
            }
            else if(aRight < bLeft) {
                l = i+1;
            }
            else{
                if(n%2==0){
                    double left = max(aLeft, bLeft);             
                    double right = min(aRight, bRight);
                    // cout << left << " " << right <<  endl;
                    return (left+right)/2;
                }
                return max(aLeft, bLeft);
            }
        }
        return -14;
    }
};
