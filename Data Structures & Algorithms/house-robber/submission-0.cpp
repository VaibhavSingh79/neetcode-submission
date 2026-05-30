class Solution {
public:
    vector<int> memo;
    
    int dfs(vector<int> &nums, int index){
        if(index < 0) return 0;

        if(memo[index] != -1) return memo[index];

        int rob_max = nums[index] + dfs(nums, index-2);
        int skip_curr = dfs(nums, index-1);

        return memo[index] = max(rob_max, skip_curr);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return n;

        memo.assign(n, -1); //initialisation with -1 for n size

        return dfs(nums, n-1);


    }
};
