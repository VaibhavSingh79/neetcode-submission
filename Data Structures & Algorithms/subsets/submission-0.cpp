class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        susb(ans, nums, temp, 0);
        return ans;
    }
    void susb(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int index){
        ans.push_back(temp);
        if(index == nums.size()) return;

        for(int i=index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            susb(ans, nums,temp,i+1);
            temp.pop_back();    
        }
    }
};
