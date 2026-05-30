class Solution {
public:
//top down
vector<int> memo;
    int dfs(vector<int> &nums, int house, int stop_idx){
        if(house < 0) return 0;

        if(house < stop_idx) return 0;
        if(memo[house] != -1) return memo[house]; //means it's visited

        int prev_rob = nums[house] + dfs(nums, house-2, stop_idx); 
        int skip_rob = dfs(nums, house-1, stop_idx); //I cannot rob adjacent houses

        return memo[house] = max(prev_rob, skip_rob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];
        memo.assign(n, -1);
        //first scenario check from 0 to n-1
        int scnA =  dfs(nums, n-2, 0);

        memo.assign(n, -1);
        int scnB = dfs(nums, n-1, 1);

        return max(scnA, scnB);

    }
};