class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        calci(nums, target, ans, temp, 0, 0);
        return ans;
    }

    void calci(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp, int index, int sum) {
        if (sum == target) {
            ans.push_back(temp);
            return; 
        }
        if (sum > target) {
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            sum += nums[i];
            calci(nums, target, ans, temp, i, sum);
            sum -= nums[i];
            temp.pop_back();
        }
    }
};