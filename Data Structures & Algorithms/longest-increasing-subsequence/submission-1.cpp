class Solution {
public:
    vector<int> memo;
    int dfs(vector<int> &nums, int index){
        if(index == nums.size()) return 0;

        if(memo[index] != -1) return memo[index];
        int curr = 1;
        
        for(int i=index+1; i< nums.size(); i++){
            if(nums[index] < nums[i]){
                int branch = 1 + dfs(nums, i);
                curr = max(curr, branch);
            }
        }
        return memo[index] = curr;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int cnter = 1;
        memo.assign(n, -1);
        for(int i=0; i < nums.size(); i++){
            int curr = dfs(nums, i);
            cnter = max(curr, cnter);
        }
        return cnter;
    }
};
