class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; //for storing final
        vector<int> temp;
        vector<int> freq;
        sort(nums.begin(), nums.end());
        susb(nums, temp, ans, 0);
        return ans;
    }
    void susb(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int index){
        ans.push_back(temp);
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            susb(nums, temp, ans, i+1);
            temp.pop_back();
        }
    }
};
