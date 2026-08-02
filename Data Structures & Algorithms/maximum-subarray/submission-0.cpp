class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int curr = maxSub;
        for(int i = 1; i < nums.size(); i++){
            curr = max(curr + nums[i], nums[i]);
            maxSub = max(curr, maxSub);
        }
        return maxSub;
    }
};
