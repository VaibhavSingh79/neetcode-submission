class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int curr_sum = nums[0]; //I will be update this
        for(int i=1; i < nums.size(); i++){
            curr_sum = max(nums[i], curr_sum + nums[i]);
            best = max(curr_sum, best);
        }
        return best;
    }
};
