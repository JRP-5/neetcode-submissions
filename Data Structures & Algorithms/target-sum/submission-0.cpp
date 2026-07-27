class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return dfs(nums, 0, 0, target);
    }
    int dfs(vector<int>& nums, int index, int currSum, int target){
        if(index == nums.size()){
            if(currSum == target){
                return 1;
            }
            return 0;
        }
        return dfs(nums, index+1, currSum + nums[index], target) + dfs(nums, index+1, currSum - nums[index], target);
    }
};
